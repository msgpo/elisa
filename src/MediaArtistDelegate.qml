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

import QtQuick 2.4
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Window 2.2
import QtQml.Models 2.1
import QtQuick.Layouts 1.2
import QtGraphicalEffects 1.0

import org.kde.elisa 1.0

FocusScope {
    property StackView stackView
    property MediaPlayList playListModel
    property var musicListener
    property var playerControl
    property var contentDirectoryModel
    property var image
    property alias name: nameLabel.text

    signal artistClicked()
    signal openArtist(var name)

    id: mediaServerEntry

    SystemPalette {
        id: myPalette
        colorGroup: SystemPalette.Active
    }

    Theme {
        id: elisaTheme
    }

    Action {
        id: enqueueAction

        text: i18nc("Add all tracks from artist to play list", "Enqueue")
        iconName: "media-track-add-amarok"
        onTriggered: mediaServerEntry.playListModel.enqueue(mediaServerEntry.name)
    }

    Action {
        id: openAction

        text: i18nc("Open artist view", "Open Artist")
        iconName: 'document-open-folder'
        onTriggered: openArtist(name)
    }

    Action {
        id: enqueueAndPlayAction

        text: i18nc("Clear play list and add all tracks from artist to play list", "Play Now and Replace Play List")
        iconName: "media-playback-start"
        onTriggered: {
            mediaServerEntry.playListModel.clearAndEnqueue(mediaServerEntry.name)
            mediaServerEntry.playerControl.ensurePlay()
        }
    }

    Keys.onReturnPressed: openArtist(name)
    Keys.onEnterPressed: openArtist(name)

    ColumnLayout {
        anchors.fill: parent

        spacing: 0

        MouseArea {
            id: hoverHandle

            hoverEnabled: true
            acceptedButtons: Qt.LeftButton
            focus: true

            Layout.preferredHeight: mediaServerEntry.width * 0.85 + elisaTheme.layoutVerticalMargin * 0.5 + nameSize.height
            Layout.fillWidth: true

            onClicked:
            {
                hoverHandle.forceActiveFocus()
                artistClicked()
            }

            onDoubleClicked: openArtist(name)

            TextMetrics {
                id: nameSize
                font: nameLabel.font
                text: nameLabel.text
            }

            Loader {
                id: hoverLoader
                active: false

                z: 2

                anchors.top: parent.top
                anchors.left: parent.left
                anchors.right: parent.right
                height: mediaServerEntry.width * 0.85 + elisaTheme.layoutVerticalMargin

                sourceComponent: Rectangle {
                    id: hoverLayer

                    anchors.fill: parent

                    color: myPalette.light
                    opacity: 0.85

                    Row {
                        anchors.centerIn: parent

                        ToolButton {
                            id: enqueueButton

                            action: enqueueAction

                            width: elisaTheme.delegateToolButtonSize
                            height: elisaTheme.delegateToolButtonSize
                        }

                        ToolButton {
                            id: openButton

                            action: openAction

                            width: elisaTheme.delegateToolButtonSize
                            height: elisaTheme.delegateToolButtonSize
                        }

                        ToolButton {
                            id: enqueueAndPlayButton

                            action: enqueueAndPlayAction

                            width: elisaTheme.delegateToolButtonSize
                            height: elisaTheme.delegateToolButtonSize
                        }
                    }
                }
            }

            ColumnLayout {
                id: mainData

                spacing: 0
                anchors.fill: parent

                z: 1

                Item {
                    Layout.preferredWidth: mediaServerEntry.width * 0.85
                    Layout.preferredHeight: mediaServerEntry.width * 0.85

                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

                    Image {
                        id: artistDecoration

                        source: Qt.resolvedUrl(elisaTheme.artistImage)

                        anchors.fill: parent

                        sourceSize.width: parent.width
                        sourceSize.height: parent.height

                        fillMode: Image.PreserveAspectFit

                        smooth: true

                        asynchronous: true

                        layer.enabled: image == '' ? false : true
                        layer.effect: DropShadow {
                            radius: 10
                            spread: 0.1
                            samples: 21

                            color: myPalette.shadow
                        }
                    }
                }

                LabelWithToolTip {
                    id: nameLabel

                    font.weight: Font.Bold
                    color: myPalette.text

                    horizontalAlignment: Text.AlignLeft

                    Layout.preferredWidth: mediaServerEntry.width * 0.85
                    Layout.topMargin: elisaTheme.layoutVerticalMargin * 0.5
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom

                    elide: Text.ElideRight
                }
            }
        }

        Item {
            Layout.fillHeight: true
        }
    }

    states: [
        State {
            name: 'default'

            PropertyChanges {
                target: hoverLoader
                active: false
            }
        },
        State {
            name: 'active'

            when: mediaServerEntry.activeFocus || hoverHandle.containsMouse

            PropertyChanges {
                target: hoverLoader
                active: true
            }
        }

    ]
}
