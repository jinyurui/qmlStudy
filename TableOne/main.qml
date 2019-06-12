import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
/** node
* @key    control 1 TableView
* @desc
*/
Window {            //  window >> object and surface
    id: root        //  is no item , rootItem will created then, so use parent
    visible: true
    width: Screen.width
    height: 480
    title: qsTr("Hello World")

    ListModel {
        id: libraryModel
    }

    TableView {
        anchors.fill: parent
        TableViewColumn {
            role: "title"
            title: "Title"
            width: root.width*0.4
        }
        TableViewColumn {
            role: "author"
            title: "Author"
            width: root.width*0.3
        }
        TableViewColumn{
            role: "desc"
            title: "desc"
            width: root.width*0.2
        }
        TableViewColumn{
            role: "rich"
            title: "rich"
            width: root.width*0.1
        }
        model: libraryModel
        rowDelegate: Rectangle{
            height: 80
            width: parent.width
            color: styleData.row%2 ? "yellow" : "red"
        }
        headerDelegate: Rectangle{
            height: 30
            width: parent.width
            color: styleData.column%2 ? "#00ffff" : "#234545"
            Text {
                text: styleData.value
                color: "red"
            }
        }
        itemDelegate: Text {
            text: styleData.value
            font.pointSize: 24
            font.bold: true
            color: styleData.selected? "black" : "white"
        }
    }

    Timer{
        repeat: true
        interval: 1000
        running: true
        onTriggered: {
            libraryModel.append({ "title": "Outstanding",
                                    "author": "Frederik",
                                    "desc": "top",
                                    "rich": 10})
        }
    }

    // jsonArray
    property var phones: [
    {first:"123",two:"456",three:"789"},
    {first:"111",two:"444",three:"777"}
    ]

    Column{
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.rightMargin: 20
        anchors.leftMargin: 20
        anchors.left: parent.left
        anchors.right: parent.right
        spacing: 10
        Repeater{
            model: phones
            delegate: Rectangle{
                width: 100
                height: 20
                border.color: "#00ffff"
                Text {
                    text: modelData.first + "-" + modelData.two + "-" + modelData.three
                }
            }
        }
    }

}
