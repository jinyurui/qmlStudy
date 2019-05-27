import QtQuick 2.0

Rectangle{
    height: 30
    width: 100
    id: rectCon
    Rectangle{
        id: redR
        anchors.left: rectCon.left
        anchors.top: rectCon.top
        color: "red"
        width: 20
        height: 30
    }
    Rectangle{
        id: blueR
        anchors.left: redR.right
        anchors.top: rectCon.top
        color: "blue"
        width: 20
        height: 20
    }
    Rectangle{
        id: blackR
        anchors.right: blueR.left
        anchors.top: rectCon.top
        color: "black"
        width: 20
        height: 10
    }

}
