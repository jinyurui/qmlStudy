import QtQuick 2.0
import QtQuick 2.12

Rectangle {
    id: root
    color: "#556"
    //property var comItem
    property alias text: showDesc.text
//    Loader{
//       //source: comItem
//       sourceComponent: Rectangle{
//            color: "red"
//       }
//       anchors.fill: root
//    }
    Text {
        id: showDesc
        anchors.bottom: root.bottom
        anchors.bottomMargin: 2
        anchors.left: root.left
        anchors.leftMargin: 0
        anchors.right: root.right
        anchors.rightMargin: 0
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        color: "yellow"
        text: "helllo"
    }

}
