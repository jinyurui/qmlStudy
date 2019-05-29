import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import CPLUS 1.0

/** node
* @key    jsonArray in qml and c++
* @desc   jsonArray from qml can use easy, then turn c++ to qml,the objetc can not use key
*/

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    // jsonarray
    property var modelData: [
        {name:"q",
            place:"SHANGHAI",
            number:"1214423",
            rich:"5"},
        {name:"w",
            place:"BEIJING",
            number:"1123212",
            rich:"3"},
        {name:"e",
            place:"SHANGHAI",
            number:"1112123",
            rich:"6"},
        {name:"R",
            place:"BEIJING",
            number:"1112123",
            rich:"6"},
        {name:"T",
            place:"BEIJING",
            number:"1112123",
            rich:"6"},
        {name:"y",
            place:"SHANGHAI",
            number:"1112123",
            rich:"6"}
    ]
    PersonModel{
        id: personModel
        personJsonArray: modelData
    }
    ListView{
        id:view
        width: 200
        height: 400
        anchors.left: root.left
        anchors.top: root.top
        anchors.bottom: root.bottom
        clip: true
        model: personModel
        delegate: Item{
            width: parent.width
            height: 50
            Rectangle{
                width: parent.width
                height: 50
                border.color: "black"
                Text {
                    anchors.centerIn: parent
                    text: name
                }
                MouseArea{
                    id:mouseArea
                    anchors.fill: parent
                    onClicked: {
                        var object = personModel.personMapData.getValue(index)
                        console.log("get info : " + object.name + object.place + object.number + object.rich)
                    }
                }
            }
            Row{
                visible: mouseArea.containsPress
                anchors.bottom: parent.bottom
                width: parent.width
                height: 20
                Repeater{
                    model: rich
                    Item {
                        width: 16
                        height: 16
                        Rectangle{
                            width: 12
                            height: 12
                            radius: 6
                            color: "red"
                            anchors.centerIn: parent
                        }
                    }
                }
            }
        }
        section.property: "place"
        section.delegate:Rectangle{
            width: parent.width
            height: 30
            color: "#00ffff"
            Text{
                anchors.centerIn: parent
                text: section
            }
        }
    }
    Button{
        id:testbtn
        anchors.left: view.right
        anchors.top: root.top
        anchors.topMargin: 20
        width: 200
        height: 100
        text: "test qml jsonarray"
        onClicked: {
            console.log("json qml to qml : " + modelData[0].name + modelData[0].place + modelData[0].number + modelData[0].rich)
        }
    }
}
