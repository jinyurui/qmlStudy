import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column{
        anchors.centerIn: parent
        Repeater{
            model: 3
            RoundBtn{
                text: index
            }
        }
    }
}
