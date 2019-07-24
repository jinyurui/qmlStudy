import QtQuick 2.9
import QtQuick.Window 2.2
import Water 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle{
        anchors.fill: parent
        Image {
            source: "./apple.svg"
            width: 50
            height: 50
            anchors.margins: 30
        }

        GFrameBufferObject{
            id: gfbo
            anchors.centerIn: parent
            width: 300
            height: 300
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                gfbo.test()
                console.log("w: " + gfbo.width  +" h: " + gfbo.height )
            }
        }
    }

    Component.onCompleted: {
        console.log("ok----")
    }
}
