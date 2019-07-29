import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    property alias text: descButton.text
    property var backColor: "yellow"
    Rectangle{
        anchors.fill: parent
        color: backColor
        Button{
            id: descButton
            width: 80
            height: 80
            anchors.centerIn: parent
            anchors.margins: 0
        }
    }
}
