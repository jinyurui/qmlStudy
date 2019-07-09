import QtQuick 2.0

Rectangle {
    id: rectangle
    width: 100
    height: 100
    Text {
        text: qsTr("it from qmlExternPlugin")
        anchors.fill: parent
        horizontalAlignment: Text.AlignLeft
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    }
}
