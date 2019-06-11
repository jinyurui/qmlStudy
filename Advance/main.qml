import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects 1.12
import Advance 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    DataControl{
        id: dataControl
        desc: "object control,is not view item, so you can not use view item in.
               like QtObject in qml."
    }

    Rectangle{
        width: 200
        height: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Text {
            id: dataDesc
            anchors.centerIn: parent
            text: dataControl.desc
            font.pointSize: 20
            visible: false
        }
        DropShadow{
            anchors.fill: dataDesc
            color: "#00ffff"
            source: dataDesc
            verticalOffset: 4
            horizontalOffset: 3
            samples: 7
        }

    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            dataControl.controlObject(DataControl.QPlace)
        }
    }
}
