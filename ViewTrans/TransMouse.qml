import QtQuick 2.0

Item {
    id: root
    signal pressed(var mouse)
    signal released(var mouse)
    signal clicked(var mouse)
    signal doubleClicked(var mouse)
    signal pressAndHold(var mouse)

    MouseArea{
        anchors.fill: parent
        onPressed: {mouse.accepted = false; root.pressed(mouse);}
        onReleased: {mouse.accepted = false; root.released(mouse);}
        onClicked: {mouse.accepted = false; root.clicked(mouse);}
        onDoubleClicked: {mouse.accepted = false; root.doubleClicked(mouse);}
        onPressAndHold: {mouse.accepted = false; root.pressAndHold(mouse);}
    }
}
