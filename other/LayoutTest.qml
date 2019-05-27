import QtQuick 2.0
import CPLUS 1.0
ItemLayout {
    Rectangle{
        id: one
        objectName: "one"
        color: "red"
        anchors.top: parent.top
        anchors.left: parent.left
    }
    Rectangle{
        id: two
        objectName: "two"
        color: "black"
        anchors.top: parent.top
        anchors.left: one.right
    }

}
