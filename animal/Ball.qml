import QtQuick 2.0

Rectangle {
    property int ballR
    property alias showStr: label.text
    width: 2*ballR
    height: width
    radius: ballR

    Text {
        id: label
        anchors.centerIn: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        wrapMode: Text.WordWrap
    }
}
