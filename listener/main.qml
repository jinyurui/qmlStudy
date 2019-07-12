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
        color: "#00ffff"
        Row{
            spacing: 20
            anchors.centerIn: parent
            Text {
                id: context
                text: posListen.context
                color: "red"
                font.pointSize: 24
            }
            Text {
                id: posvalue
                text: posListen.posValue
                color: "yellow"
                font.pointSize: 24
            }
        }
    }

    PosListen{
        id: posListen
    }

    Component.onCompleted: {
        posListen.createServiec()
    }
}
