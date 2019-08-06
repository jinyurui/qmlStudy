import QtQuick 2.0

Rectangle {
    color: "red"
    width: 100
    height: 100
    radius: 50
    property alias text: show.text
    Text{
        id: show
        anchors.centerIn: parent
    }
}
