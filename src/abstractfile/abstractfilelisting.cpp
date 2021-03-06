/*
 * Copyright 2016-2017 Matthieu Gallien <matthieu_gallien@yahoo.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "abstractfilelisting.h"

#include "musicaudiotrack.h"
#include "notificationitem.h"
#include "elisautils.h"

#include <KFileMetaData/Properties>
#include <KFileMetaData/ExtractorCollection>
#include <KFileMetaData/Extractor>
#include <KFileMetaData/SimpleExtractionResult>
#include <KFileMetaData/UserMetaData>

#include <QThread>
#include <QHash>
#include <QFileInfo>
#include <QDir>
#include <QFileSystemWatcher>
#include <QMimeDatabase>
#include <QSet>
#include <QPair>
#include <QAtomicInt>

#include <QtGlobal>

#include <algorithm>
#include <utility>

class AbstractFileListingPrivate
{
public:

    explicit AbstractFileListingPrivate(QString sourceName) : mSourceName(std::move(sourceName))
    {
    }

    QFileSystemWatcher mFileSystemWatcher;

    QHash<QString, QUrl> mAllAlbumCover;

    QHash<QUrl, QSet<QPair<QUrl, bool>>> mDiscoveredFiles;

    QString mSourceName;

    bool mHandleNewFiles = true;

    KFileMetaData::ExtractorCollection mExtractors;

    QAtomicInt mStopRequest = 0;

    QMimeDatabase mMimeDb;

    int mImportedTracksCount = 0;

};

AbstractFileListing::AbstractFileListing(const QString &sourceName, QObject *parent) : QObject(parent), d(std::make_unique<AbstractFileListingPrivate>(sourceName))
{
    connect(&d->mFileSystemWatcher, &QFileSystemWatcher::directoryChanged,
            this, &AbstractFileListing::directoryChanged);
    connect(&d->mFileSystemWatcher, &QFileSystemWatcher::fileChanged,
            this, &AbstractFileListing::fileChanged);
}

AbstractFileListing::~AbstractFileListing()
= default;

void AbstractFileListing::init()
{
    executeInit();
}

void AbstractFileListing::newTrackFile(const MusicAudioTrack &partialTrack)
{
    const auto &newTrack = scanOneFile(partialTrack.resourceURI());

    if (newTrack.isValid() && newTrack != partialTrack) {
        Q_EMIT modifyTracksList({newTrack}, d->mAllAlbumCover, d->mSourceName);
    }
}

void AbstractFileListing::resetImportedTracksCounter()
{
    d->mImportedTracksCount = 0;
}

void AbstractFileListing::applicationAboutToQuit()
{
    d->mStopRequest = 1;
}

void AbstractFileListing::scanDirectory(QList<MusicAudioTrack> &newFiles, const QUrl &path)
{
    if (d->mStopRequest == 1) {
        return;
    }

    QDir rootDirectory(path.toLocalFile());
    rootDirectory.refresh();

    if (rootDirectory.exists()) {
        watchPath(path.toLocalFile());
    }

    auto &currentDirectoryListingFiles = d->mDiscoveredFiles[path];

    auto currentFilesList = QSet<QUrl>();

    rootDirectory.refresh();
    const auto entryList = rootDirectory.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);
    for (const auto &oneEntry : entryList) {
        auto newFilePath = QUrl::fromLocalFile(oneEntry.canonicalFilePath());

        if (oneEntry.isDir() || oneEntry.isFile()) {
            currentFilesList.insert(newFilePath);
        }
    }

    auto removedTracks = QVector<QPair<QUrl, bool>>();
    for (const auto &removedFilePath : currentDirectoryListingFiles) {
        auto itFilePath = std::find(currentFilesList.begin(), currentFilesList.end(), removedFilePath.first);

        if (itFilePath != currentFilesList.end()) {
            continue;
        }

        removedTracks.push_back(removedFilePath);
    }

    auto allRemovedTracks = QList<QUrl>();
    for (const auto &oneRemovedTrack : removedTracks) {
        if (oneRemovedTrack.second) {
            allRemovedTracks.push_back(oneRemovedTrack.first);
        } else {
            removeFile(oneRemovedTrack.first, allRemovedTracks);
        }
    }
    for (const auto &oneRemovedTrack : removedTracks) {
        currentDirectoryListingFiles.remove(oneRemovedTrack);
        currentDirectoryListingFiles.remove(oneRemovedTrack);
    }

    if (!allRemovedTracks.isEmpty()) {
        Q_EMIT removedTracksList(allRemovedTracks);
    }

    if (!d->mHandleNewFiles) {
        return;
    }

    for (const auto &newFilePath : currentFilesList) {
        QFileInfo oneEntry(newFilePath.toLocalFile());

        auto itFilePath = std::find(currentDirectoryListingFiles.begin(), currentDirectoryListingFiles.end(), QPair<QUrl, bool>{newFilePath, oneEntry.isFile()});

        if (itFilePath != currentDirectoryListingFiles.end()) {
            continue;
        }

        if (oneEntry.isDir()) {
            addFileInDirectory(newFilePath, path);
            scanDirectory(newFiles, newFilePath);

            if (d->mStopRequest == 1) {
                break;
            }

            continue;
        }
        if (!oneEntry.isFile()) {
            continue;
        }

        auto newTrack = scanOneFile(newFilePath);

        if (newTrack.isValid() && d->mStopRequest == 0) {
            addCover(newTrack);

            addFileInDirectory(newTrack.resourceURI(), path);
            newFiles.push_back(newTrack);

            ++d->mImportedTracksCount;
            if (d->mImportedTracksCount % 50 == 0) {
                Q_EMIT importedTracksCountChanged();
            }

            if (newFiles.size() > 500 && d->mStopRequest == 0) {
                Q_EMIT importedTracksCountChanged();
                emitNewFiles(newFiles);
                newFiles.clear();
            }
        }

        if (d->mStopRequest == 1) {
            Q_EMIT importedTracksCountChanged();
            break;
        }
    }
}

const QString &AbstractFileListing::sourceName() const
{
    return d->mSourceName;
}

int AbstractFileListing::importedTracksCount() const
{
    return d->mImportedTracksCount;
}

void AbstractFileListing::directoryChanged(const QString &path)
{
    const auto directoryEntry = d->mDiscoveredFiles.find(QUrl::fromLocalFile(path));
    if (directoryEntry == d->mDiscoveredFiles.end()) {
        return;
    }

    Q_EMIT indexingStarted();

    scanDirectoryTree(path);

    Q_EMIT indexingFinished();
}

void AbstractFileListing::fileChanged(const QString &modifiedFileName)
{
    auto modifiedFile = QUrl::fromLocalFile(modifiedFileName);

    auto modifiedTrack = scanOneFile(modifiedFile);

    if (modifiedTrack.isValid()) {
        Q_EMIT modifyTracksList({modifiedTrack}, d->mAllAlbumCover, d->mSourceName);
    }
}

void AbstractFileListing::executeInit()
{
}

void AbstractFileListing::triggerRefreshOfContent()
{
    d->mImportedTracksCount = 0;
}

void AbstractFileListing::refreshContent()
{
    triggerRefreshOfContent();
}

MusicAudioTrack AbstractFileListing::scanOneFile(const QUrl &scanFile)
{
    MusicAudioTrack newTrack;

    newTrack = ElisaUtils::scanOneFile(scanFile, d->mMimeDb, d->mExtractors);

    if (newTrack.isValid()) {
        QFileInfo scanFileInfo(scanFile.toLocalFile());
        if (scanFileInfo.exists()) {
            watchPath(scanFile.toLocalFile());
        }
    }

    return newTrack;
}

void AbstractFileListing::watchPath(const QString &pathName)
{
    d->mFileSystemWatcher.addPath(pathName);
}

void AbstractFileListing::addFileInDirectory(const QUrl &newFile, const QUrl &directoryName)
{
    const auto directoryEntry = d->mDiscoveredFiles.find(directoryName);
    if (directoryEntry == d->mDiscoveredFiles.end()) {
        watchPath(directoryName.toLocalFile());

        QDir currentDirectory(directoryName.toLocalFile());
        if (currentDirectory.cdUp()) {
            const auto parentDirectoryName = currentDirectory.absolutePath();
            const auto parentDirectory = QUrl::fromLocalFile(parentDirectoryName);
            const auto parentDirectoryEntry = d->mDiscoveredFiles.find(parentDirectory);
            if (parentDirectoryEntry == d->mDiscoveredFiles.end()) {
                watchPath(parentDirectoryName);
            }

            auto &parentCurrentDirectoryListingFiles = d->mDiscoveredFiles[parentDirectory];

            parentCurrentDirectoryListingFiles.insert({directoryName, false});
        }
    }
    auto &currentDirectoryListingFiles = d->mDiscoveredFiles[directoryName];

    QFileInfo isAFile(newFile.toLocalFile());
    currentDirectoryListingFiles.insert({newFile, isAFile.isFile()});
}

void AbstractFileListing::scanDirectoryTree(const QString &path)
{
    auto newFiles = QList<MusicAudioTrack>();

    scanDirectory(newFiles, QUrl::fromLocalFile(path));

    if (!newFiles.isEmpty() && d->mStopRequest == 0) {
        Q_EMIT importedTracksCountChanged();
        emitNewFiles(newFiles);
    }
}

void AbstractFileListing::setHandleNewFiles(bool handleThem)
{
    d->mHandleNewFiles = handleThem;
}

void AbstractFileListing::emitNewFiles(const QList<MusicAudioTrack> &tracks)
{
    Q_EMIT tracksList(tracks, d->mAllAlbumCover, d->mSourceName);
}

void AbstractFileListing::addCover(const MusicAudioTrack &newTrack)
{
    auto itCover = d->mAllAlbumCover.find(newTrack.albumName());
    if (itCover != d->mAllAlbumCover.end()) {
        return;
    }

    QFileInfo trackFilePath(newTrack.resourceURI().toLocalFile());
    QFileInfo coverFilePath(trackFilePath.dir().filePath(QStringLiteral("cover.jpg")));

    if (coverFilePath.exists()) {
        d->mAllAlbumCover[newTrack.resourceURI().toString()] = QUrl::fromLocalFile(coverFilePath.absoluteFilePath());
    }
}

void AbstractFileListing::removeDirectory(const QUrl &removedDirectory, QList<QUrl> &allRemovedFiles)
{
    const auto itRemovedDirectory = d->mDiscoveredFiles.find(removedDirectory);

    if (itRemovedDirectory == d->mDiscoveredFiles.end()) {
        return;
    }

    const auto &currentRemovedDirectory = *itRemovedDirectory;
    for (const auto &itFile : currentRemovedDirectory) {
        if (itFile.first.isValid() && !itFile.first.isEmpty()) {
            removeFile(itFile.first, allRemovedFiles);
            if (itFile.second) {
                allRemovedFiles.push_back(itFile.first);
            }
        }
    }

    d->mDiscoveredFiles.erase(itRemovedDirectory);
}

void AbstractFileListing::removeFile(const QUrl &oneRemovedTrack, QList<QUrl> &allRemovedFiles)
{
    auto itRemovedDirectory = d->mDiscoveredFiles.find(oneRemovedTrack);
    if (itRemovedDirectory != d->mDiscoveredFiles.end()) {
        removeDirectory(oneRemovedTrack, allRemovedFiles);
    }
}

void AbstractFileListing::setSourceName(const QString &name)
{
    d->mSourceName = name;
}

void AbstractFileListing::increaseImportedTracksCount()
{
    ++d->mImportedTracksCount;
}


#include "moc_abstractfilelisting.cpp"
