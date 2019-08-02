import QtQuick 2.12
import QtQuick.Window 2.12
import Water 1.0


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id:root

    Loader{
        id: ballLoader
        anchors.centerIn: parent
        width: 100
        height: 100
        active: false
        sourceComponent: GRedball{

        }
    }

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        onClicked: {
            createRedBall(mouseX, mouseY);
        }
        onDoubleClicked: {

        }
    }

    function createRedBall(x, y){
        var component = Qt.createComponent("RedBall.qml");
        if (component.status == Component.Ready){
            var obj = component.createObject(root, {"x": x,
                                              "y": y,
                                                 "width": "10",
                                                 "height": "10",
                                                 "radius": "5"});
        }
    }
}
