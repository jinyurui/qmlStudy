import QtQuick 2.0

ListView {
    id: root
    width: 240; height: 320
    model: ListModel {
        ListElement{name:"item"}
    }

    delegate: Rectangle {
        width: 100; height: 30
        border.width: 1
        color: "lightsteelblue"
        Text {
            anchors.centerIn: parent
            text: name
        }
    }

    add: Transition {
        NumberAnimation { property: "x"; from: -root.width; duration: 400 }
        NumberAnimation { property: "scale"; from: 0; to: 1.0; duration: 1000 }
    }
    property var otherModle: ListModel{
        ListElement{name:"molechange"}
    }


    focus: true
    Keys.onSpacePressed: model.append({ "name": "Item " + model.count })
}
