/*
 * Copyright 2016 Matthieu Gallien <matthieu_gallien@yahoo.fr>
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

#include "manageaudioplayertest.h"

#include "manageaudioplayer.h"

#include <QtTest>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QUrl>

ManageAudioPlayerTest::ManageAudioPlayerTest(QObject *parent) : QObject(parent)
{
}

void ManageAudioPlayerTest::initTestCase()
{
}

void ManageAudioPlayerTest::simpleInitialCase()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(QMediaPlayer::NoMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::NoMedia);

    QCOMPARE(skipNextTrackSpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::noPlayCase()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), false);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
}

void ManageAudioPlayerTest::skipNextTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::skipNextTrackWithRandomPlay()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::skipPreviousTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
}

void ManageAudioPlayerTest::playTrackAndskipNextTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(QMediaPlayer::NoMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::NoMedia);

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setCurrentTrack(myPlayList.index(2, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(2, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///3.mp3")));
    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 9);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 5);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));
}

void ManageAudioPlayerTest::playTrackAndskipPreviousTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(QMediaPlayer::NoMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::NoMedia);

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(2, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(2, 0)));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///3.mp3")));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));
    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 9);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 5);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));
}

void ManageAudioPlayerTest::skipNextTrackAndPlayTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));
    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(QMediaPlayer::NoMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::NoMedia);

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(2, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(2, 0)));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///3.mp3")));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 9);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
}

void ManageAudioPlayerTest::skipPreviousTrackAndPlayTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));
    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(QMediaPlayer::NoMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::NoMedia);

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 8);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 9);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 3);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 3);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 10);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 3);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
}

void ManageAudioPlayerTest::playLastCase()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(2, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(2, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///3.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(QMediaPlayer::NoMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::NoMedia);

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.playListFinished();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    QCOMPARE(playerPlaySpy.wait(100), false);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::playSingleTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(QMediaPlayer::NoMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::NoMedia);

    QCOMPARE(skipNextTrackSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.playListFinished();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    QCOMPARE(playerPlaySpy.wait(100), false);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::playRestoredTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::testRestoreSettingsAutomaticPlay()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy titleRoleChangedSpy(&myPlayer, &ManageAudioPlayer::titleRoleChanged);
    QSignalSpy artistNameRoleChangedSpy(&myPlayer, &ManageAudioPlayer::artistNameRoleChanged);
    QSignalSpy albumNameRoleChangedSpy(&myPlayer, &ManageAudioPlayer::albumNameRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("title"), ManageAudioPlayerTest::TitleRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("artist"), ManageAudioPlayerTest::ArtistRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("album"), ManageAudioPlayerTest::AlbumRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setTitleRole(ManageAudioPlayerTest::TitleRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.titleRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::TitleRole));

    myPlayer.setArtistNameRole(ManageAudioPlayerTest::ArtistRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.artistNameRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::ArtistRole));

    myPlayer.setAlbumNameRole(ManageAudioPlayerTest::AlbumRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.albumNameRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::AlbumRole));

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QVariantMap settings;
    settings[QStringLiteral("isPlaying")] = true;
    settings[QStringLiteral("audioPlayerCurrentTitle")] = QStringLiteral("title");
    settings[QStringLiteral("audioPlayerCurrentArtistName")] = QStringLiteral("artist");
    settings[QStringLiteral("audioPlayerCurrentAlbumName")] = QStringLiteral("album");

    myPlayer.setPersistentState(settings);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    QCOMPARE(playerPlaySpy.wait(500), false);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::InvalidMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::InvalidMedia);
}

void ManageAudioPlayerTest::testRestoreSettingsNoAutomaticPlay()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy titleRoleChangedSpy(&myPlayer, &ManageAudioPlayer::titleRoleChanged);
    QSignalSpy artistNameRoleChangedSpy(&myPlayer, &ManageAudioPlayer::artistNameRoleChanged);
    QSignalSpy albumNameRoleChangedSpy(&myPlayer, &ManageAudioPlayer::albumNameRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("title"), ManageAudioPlayerTest::TitleRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("artist"), ManageAudioPlayerTest::ArtistRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("album"), ManageAudioPlayerTest::AlbumRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QVariantMap settings;
    settings[QStringLiteral("isPlaying")] = false;
    settings[QStringLiteral("audioPlayerCurrentTitle")] = QStringLiteral("title");
    settings[QStringLiteral("audioPlayerCurrentArtistName")] = QStringLiteral("artist");
    settings[QStringLiteral("audioPlayerCurrentAlbumName")] = QStringLiteral("album");

    myPlayer.setPersistentState(settings);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setTitleRole(ManageAudioPlayerTest::TitleRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.titleRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::TitleRole));

    myPlayer.setArtistNameRole(ManageAudioPlayerTest::ArtistRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.artistNameRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::ArtistRole));

    myPlayer.setAlbumNameRole(ManageAudioPlayerTest::AlbumRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.albumNameRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::AlbumRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(1000), false);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::testRestoreSettingsAutomaticPlayAndPosition()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy titleRoleChangedSpy(&myPlayer, &ManageAudioPlayer::titleRoleChanged);
    QSignalSpy artistNameRoleChangedSpy(&myPlayer, &ManageAudioPlayer::artistNameRoleChanged);
    QSignalSpy albumNameRoleChangedSpy(&myPlayer, &ManageAudioPlayer::albumNameRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("title"), ManageAudioPlayerTest::TitleRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("artist"), ManageAudioPlayerTest::ArtistRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("album"), ManageAudioPlayerTest::AlbumRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QVariantMap settings;
    settings[QStringLiteral("isPlaying")] = true;
    settings[QStringLiteral("audioPlayerCurrentTitle")] = QStringLiteral("title");
    settings[QStringLiteral("audioPlayerCurrentArtistName")] = QStringLiteral("artist");
    settings[QStringLiteral("audioPlayerCurrentAlbumName")] = QStringLiteral("album");
    settings[QStringLiteral("playerPosition")] = 10000;

    myPlayer.setPersistentState(settings);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setTitleRole(ManageAudioPlayerTest::TitleRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.titleRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::TitleRole));

    myPlayer.setArtistNameRole(ManageAudioPlayerTest::ArtistRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.artistNameRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::ArtistRole));

    myPlayer.setAlbumNameRole(ManageAudioPlayerTest::AlbumRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(seekSpy.at(0).at(0).toInt(), 10000);
    QCOMPARE(myPlayer.albumNameRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::AlbumRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    myPlayer.setPlayerStatus(QMediaPlayer::NoMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::NoMedia);

    QCOMPARE(skipNextTrackSpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 1);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::playTrackPauseAndSkipNextTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPauseSpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PausedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PausedState));

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    QCOMPARE(playerStopSpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));
    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(100), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    myPlayer.playPause();

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(playerPlaySpy.wait(100), true);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 3);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 6);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 2);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 2);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 7);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 4);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 2);
    QCOMPARE(playerPauseSpy.count(), 1);
    QCOMPARE(playerStopSpy.count(), 1);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);
}

void ManageAudioPlayerTest::testRestoreSettingsNoPlayWrongTrack()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy titleRoleChangedSpy(&myPlayer, &ManageAudioPlayer::titleRoleChanged);
    QSignalSpy artistNameRoleChangedSpy(&myPlayer, &ManageAudioPlayer::artistNameRoleChanged);
    QSignalSpy albumNameRoleChangedSpy(&myPlayer, &ManageAudioPlayer::albumNameRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("title"), ManageAudioPlayerTest::TitleRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("artist"), ManageAudioPlayerTest::ArtistRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("album"), ManageAudioPlayerTest::AlbumRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QStringLiteral("title2"), ManageAudioPlayerTest::TitleRole);
    myPlayList.item(1, 0)->setData(QStringLiteral("artist2"), ManageAudioPlayerTest::ArtistRole);
    myPlayList.item(1, 0)->setData(QStringLiteral("album2"), ManageAudioPlayerTest::AlbumRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setTitleRole(ManageAudioPlayerTest::TitleRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.titleRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::TitleRole));

    myPlayer.setArtistNameRole(ManageAudioPlayerTest::ArtistRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.artistNameRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::ArtistRole));

    myPlayer.setAlbumNameRole(ManageAudioPlayerTest::AlbumRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.albumNameRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::AlbumRole));

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QVariantMap settings;
    settings[QStringLiteral("isPlaying")] = true;
    settings[QStringLiteral("audioPlayerCurrentTitle")] = QStringLiteral("title");
    settings[QStringLiteral("audioPlayerCurrentArtistName")] = QStringLiteral("artist");
    settings[QStringLiteral("audioPlayerCurrentAlbumName")] = QStringLiteral("album");

    myPlayer.setPersistentState(settings);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(1, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(1, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));
    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///2.mp3")));

    QCOMPARE(playerPlaySpy.wait(500), false);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(500), false);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
}

void ManageAudioPlayerTest::testRestorePlayListAndSettingsAutomaticPlay()
{
    ManageAudioPlayer myPlayer;
    QStandardItemModel myPlayList;

    QSignalSpy currentTrackChangedSpy(&myPlayer, &ManageAudioPlayer::currentTrackChanged);
    QSignalSpy playListModelChangedSpy(&myPlayer, &ManageAudioPlayer::playListModelChanged);
    QSignalSpy playerSourceChangedSpy(&myPlayer, &ManageAudioPlayer::playerSourceChanged);
    QSignalSpy urlRoleChangedSpy(&myPlayer, &ManageAudioPlayer::urlRoleChanged);
    QSignalSpy isPlayingRoleChangedSpy(&myPlayer, &ManageAudioPlayer::isPlayingRoleChanged);
    QSignalSpy titleRoleChangedSpy(&myPlayer, &ManageAudioPlayer::titleRoleChanged);
    QSignalSpy artistNameRoleChangedSpy(&myPlayer, &ManageAudioPlayer::artistNameRoleChanged);
    QSignalSpy albumNameRoleChangedSpy(&myPlayer, &ManageAudioPlayer::albumNameRoleChanged);
    QSignalSpy playerStatusChangedSpy(&myPlayer, &ManageAudioPlayer::playerStatusChanged);
    QSignalSpy playerPlaybackStateChangedSpy(&myPlayer, &ManageAudioPlayer::playerPlaybackStateChanged);
    QSignalSpy playerErrorChangedSpy(&myPlayer, &ManageAudioPlayer::playerErrorChanged);
    QSignalSpy persistentStateChangedSpy(&myPlayer, &ManageAudioPlayer::persistentStateChanged);
    QSignalSpy playerPlaySpy(&myPlayer, &ManageAudioPlayer::playerPlay);
    QSignalSpy playerPauseSpy(&myPlayer, &ManageAudioPlayer::playerPause);
    QSignalSpy playerStopSpy(&myPlayer, &ManageAudioPlayer::playerStop);
    QSignalSpy skipNextTrackSpy(&myPlayer, &ManageAudioPlayer::skipNextTrack);
    QSignalSpy seekSpy(&myPlayer, &ManageAudioPlayer::seek);

    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);
    myPlayList.appendRow(new QStandardItem);

    myPlayList.item(0, 0)->setData(QStringLiteral("title"), ManageAudioPlayerTest::TitleRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("artist"), ManageAudioPlayerTest::ArtistRole);
    myPlayList.item(0, 0)->setData(QStringLiteral("album"), ManageAudioPlayerTest::AlbumRole);
    myPlayList.item(1, 0)->setData(QStringLiteral("title2"), ManageAudioPlayerTest::TitleRole);
    myPlayList.item(1, 0)->setData(QStringLiteral("artist2"), ManageAudioPlayerTest::ArtistRole);
    myPlayList.item(1, 0)->setData(QStringLiteral("album2"), ManageAudioPlayerTest::AlbumRole);
    myPlayList.item(2, 0)->setData(QStringLiteral("title3"), ManageAudioPlayerTest::TitleRole);
    myPlayList.item(2, 0)->setData(QStringLiteral("artist3"), ManageAudioPlayerTest::ArtistRole);
    myPlayList.item(2, 0)->setData(QStringLiteral("album3"), ManageAudioPlayerTest::AlbumRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 0);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setTitleRole(ManageAudioPlayerTest::TitleRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 0);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.titleRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::TitleRole));

    myPlayer.setArtistNameRole(ManageAudioPlayerTest::ArtistRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 0);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.artistNameRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::ArtistRole));

    myPlayer.setAlbumNameRole(ManageAudioPlayerTest::AlbumRole);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.albumNameRole(), static_cast<int>(ManageAudioPlayerTest::ManageAudioPlayerTest::AlbumRole));

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 0);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayListModel(&myPlayList);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 0);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QVariantMap settings;
    settings[QStringLiteral("isPlaying")] = true;
    settings[QStringLiteral("audioPlayerCurrentTitle")] = QStringLiteral("title");
    settings[QStringLiteral("audioPlayerCurrentArtistName")] = QStringLiteral("artist");
    settings[QStringLiteral("audioPlayerCurrentAlbumName")] = QStringLiteral("album");

    myPlayer.setPersistentState(settings);

    QCOMPARE(currentTrackChangedSpy.count(), 0);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setCurrentTrack(myPlayList.index(0, 0));

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 0);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.currentTrack(), QPersistentModelIndex(myPlayList.index(0, 0)));

    myPlayer.setUrlRole(ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.urlRole(), static_cast<int>(ManageAudioPlayerTest::ResourceRole));

    QCOMPARE(playerPlaySpy.wait(500), false);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 0);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setIsPlayingRole(ManageAudioPlayerTest::IsPlayingRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 0);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.isPlayingRole(), static_cast<int>(ManageAudioPlayerTest::IsPlayingRole));

    myPlayList.item(0, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///1.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(1, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///2.mp3")), ManageAudioPlayerTest::ResourceRole);
    myPlayList.item(2, 0)->setData(QUrl::fromUserInput(QStringLiteral("file:///3.mp3")), ManageAudioPlayerTest::ResourceRole);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 0);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerSource(), QUrl::fromUserInput(QStringLiteral("file:///1.mp3")));

    myPlayer.setPlayerStatus(QMediaPlayer::LoadingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadingMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerError(QMediaPlayer::NoError);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 1);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::LoadedMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 2);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::LoadedMedia);

    myPlayer.setPlayerStatus(QMediaPlayer::BufferingMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 0);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::BufferingMedia);

    QCOMPARE(playerPlaySpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 0);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::PlayingState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 3);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::PlayingState));

    myPlayer.setPlayerStatus(QMediaPlayer::EndOfMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 1);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), true);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::EndOfMedia);

    myPlayer.setPlayerPlaybackState(ManageAudioPlayer::StoppedState);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 0);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerPlaybackState(), static_cast<int>(ManageAudioPlayer::StoppedState));

    QCOMPARE(skipNextTrackSpy.wait(), true);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 4);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    myPlayer.setPlayerStatus(QMediaPlayer::InvalidMedia);

    QCOMPARE(currentTrackChangedSpy.count(), 1);
    QCOMPARE(playListModelChangedSpy.count(), 1);
    QCOMPARE(playerSourceChangedSpy.count(), 1);
    QCOMPARE(urlRoleChangedSpy.count(), 1);
    QCOMPARE(isPlayingRoleChangedSpy.count(), 1);
    QCOMPARE(titleRoleChangedSpy.count(), 1);
    QCOMPARE(artistNameRoleChangedSpy.count(), 1);
    QCOMPARE(albumNameRoleChangedSpy.count(), 1);
    QCOMPARE(playerStatusChangedSpy.count(), 5);
    QCOMPARE(playerPlaybackStateChangedSpy.count(), 2);
    QCOMPARE(playerErrorChangedSpy.count(), 0);
    QCOMPARE(persistentStateChangedSpy.count(), 1);
    QCOMPARE(playerPlaySpy.count(), 1);
    QCOMPARE(playerPauseSpy.count(), 0);
    QCOMPARE(playerStopSpy.count(), 0);
    QCOMPARE(skipNextTrackSpy.count(), 1);
    QCOMPARE(seekSpy.count(), 0);
    QCOMPARE(myPlayList.data(myPlayList.index(0, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(1, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);
    QCOMPARE(myPlayList.data(myPlayList.index(2, 0), ManageAudioPlayerTest::IsPlayingRole).toBool(), false);

    QCOMPARE(myPlayer.playerStatus(), QMediaPlayer::InvalidMedia);
}

QTEST_GUILESS_MAIN(ManageAudioPlayerTest)


#include "moc_manageaudioplayertest.cpp"
