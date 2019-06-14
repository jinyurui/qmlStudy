import QtQuick 2.9
import QtQuick.Window 2.2
import TextToSpeech 1.0
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TextSp{
        id: textSp
        text: fileReader.readFile(":/123.txt")
        volume: volumeControl.value
    }

    FileReader{
        id: fileReader
    }
    ScrollView{
        id: view
        anchors.fill: parent
        TextArea{
            text: textSp.text
            verticalAlignment: Text.AlignTop
            horizontalAlignment: Text.AlignLeft
            padding: 5
            font.capitalization: Font.SmallCaps
            font.italic: true
            font.pointSize: 12
            textFormat: Text.PlainText
            wrapMode: Text.WordWrap
        }
    }

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        onClicked: {
            controls.visible = true
            volumeControl.visible = true
            duringTime.restart()
        }
    }

    Timer{
        id: duringTime
        interval: 10000
        repeat: false
        running: false
        onTriggered: {
            controls.visible = false
            volumeControl.visible = false
        }
    }

    Rectangle{
        id: controls
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.margins: 50
        height: 50
        visible: false
        color: "#11223300"
        border.width: 2
        border.color: "yellow"
        Row{
            anchors.left: parent.left
            anchors.leftMargin: 30
            anchors.verticalCenter: parent.verticalCenter
            spacing: 10
            Button{
                text: "start"
                enabled: textSp.state == TextSp.Ready
                onClicked: {
                    console.log("btn click")
                    textSp.start()
                }
            }
            Button{
                text: "pause"
                enabled: textSp.state == TextSp.Working
                onClicked: {
                    textSp.pause()
                }
            }
            Button{
                text: "resume"
                enabled: textSp.state == TextSp.Paused
                onClicked: {
                    textSp.resume()
                }
            }
            Button{
                text: "stop"
                enabled: textSp.state == TextSp.Working
                onClicked: {
                    textSp.stop()
                }
            }
        }

        Behavior on visible{
            NumberAnimation{
                duration: 1000
            }
        }

        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onContainsMouseChanged: {
                containsMouse ? duringTime.stop() : duringTime.restart()
            }
            onClicked: {
                console.log("click...")
                mouse.accepted = false
            }
            onPressed: {
                console.log("press...")
                mouse.accepted = false
            }

        }
    }

    Slider{
        id: volumeControl
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.top: parent.top
        anchors.topMargin: 30
        height: parent.height*0.4
        value: 0.5
        from: 0
        to: 1
        orientation: Qt.Vertical
        visible: false
    }
}
