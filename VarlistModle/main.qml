import QtQuick 2.12
import QtQuick.Window 2.12
import Water 1.0
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    BackEndData{
        id: endData
    }

    ListView{
        width: 200
        height: 500
        model: endData.data
        delegate: Rectangle{
            width: parent.width
            height: 20
            Text {
                anchors.centerIn: parent
                text: modelData.name + ": " + modelData.age
            }
        }
        onModelChanged: {
            console.log("model change")
            // case model.data = model.data, so changed, then case populate
        }
        populate: Transition {
            NumberAnimation { properties: "x"; from: -200; duration: 200}
        }
    }

    Row{
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
        spacing: 0
        height: 30

        Button{
            width: 100
            height: 30
            text: "up"
            onClicked: {
                var listModel = endData.data.slice()
                listModel.sort(function(a, b) {
                    return (a.age - b.age)})
                endData.data = listModel
            }
        }
        Button{
            width: 100
            height: 30
            text: "down"
            onClicked: {
                var listModel = endData.data.slice()
                listModel.sort(function(a, b) {
                    return (- a.age + b.age)})
                endData.data = listModel
            }
        }
        Button{
            width: 100
            height: 30
            text: "add"
            onClicked: {
                var listModel = endData.data.slice()
                listModel.push({"name":"other", "age": 100})
                endData.data = listModel
            }
        }
        Button{
            width: 100
            height: 30
            text: "del"
            onClicked: {
                var listModel = endData.data.slice()
                listModel.splice(0,1)
                endData.data = listModel
            }
        }

    }
}
