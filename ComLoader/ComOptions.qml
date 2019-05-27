import QtQuick 2.0

Item {
    width: 100
    height: 100
    Rectangle{
        id: backGround
        anchors.fill: parent
        radius: 50
        color:Qt.rgba(
                  0 + Math.round(Math.random()*1),
                  0 + Math.round(Math.random()*1),
                  0 + Math.round(Math.random()*1))
    }
}
