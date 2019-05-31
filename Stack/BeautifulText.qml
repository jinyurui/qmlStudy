import QtQuick 2.0
import QtGraphicalEffects 1.0
import QtQuick 2.9
import QtQuick.Layouts 1.3

Item{
    id: root
    property alias text: textShow.text
    property alias fontSize: textShow.font.pointSize
    property alias fontColor: textShow.color
    width: childrenRect.width
    height: childrenRect.height
    MouseArea{
        id: mouseArea
        anchors.fill: parent
    }
    Text{
        id: textShow
        anchors.centerIn: parent
        text: "hello"
        font.pointSize: 12
        font.bold: true
        color: "#04f6a8"
        layer.enabled: true
        layer.effect: mouseArea.containsPress ? glowGraphical : shadowGraphical

    }
    Component{
        id:glowGraphical
        Glow{
            color: "#f1d000"
            samples: 7
        }
    }
    Component{
        id: shadowGraphical
        DropShadow{
            color: "black"
            horizontalOffset: 7
            verticalOffset: 10
            spread: 0.3
            samples: 7
        }
    }
}

