import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import Water 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        anchors.fill: parent
        Image {
            id: imageSrc
            source: "./apple.svg"
            width: 50
            height: 50
            anchors.margins: 30
        }

        GFrameBufferObject{
            id: gfbo
            anchors.top: imageSrc.bottom
            anchors.topMargin: 30
            anchors.left: parent.left
            anchors.leftMargin: 50
            anchors.right: parent.right
            anchors.rightMargin: 50
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 50
            posZ: posValue.value
            turn: false
            topWin: root
        }

        Button{
            width: 50
            height: 50
            text: gfbo.turn ? "turn" : "stop"
            onClicked: {
                gfbo.turn = !gfbo.turn
            }
            anchors.top: parent.top
            anchors.right: posValue.left
            anchors.margins: 20
        }

        Slider{
            id: posValue
            value: 2
            from: -20
            to: 20
            orientation: Qt.Vertical
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 20
            width: 10
        }
    }

    Component.onCompleted: {
        gfbo.createViewControl()
    }
}
