import QtQuick 2.0

Item {
    property alias color: ball.color
    Rectangle{
        id: ball
        width: 20
        height: 20
        radius: 10
    }
    z: 100
}
