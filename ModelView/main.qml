import QtQuick 2.9
import QtQuick.Window 2.2
import CPLUS 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property var modelData: [
        {"name":"q",
            "place":"newyork",
            "number":"1214423",
            "rich":"5"},
        {"name":"w",
            "place":"newTown",
            "number":"1123212",
            "rich":"3"},
        {"name":"w",
            "place":"newyork",
            "number":"1112123",
            "rich":"6"}
    ]
    PersonModel{
        id: personModel
    }
    ListView{
        anchors.top: root.top
        anchors.left: root.left
        width: 200
        model: personModel
        delegate: Rectangle{
            width: parent.width
            height: 50
            Text {
                anchors.centerIn: parent
                text: name
            }
        }
        section.property: "place"
    }

    Component.onCompleted: {
        personModel.setJsonArray(modelData)
    }
}
