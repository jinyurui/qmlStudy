import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Rectangle {
        anchors.fill: parent
        color: "black"
        Row{
            spacing: 20
            Image {
                source: "qrc:/icon_phone_accept_active.png"
            }
            Image {
                source: "qrc:/icon_phone_accept_selected.png"
            }
        }
    }
}
