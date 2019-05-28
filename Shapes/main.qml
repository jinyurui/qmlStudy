import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick 2.12

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    ListModel{
        id: modelUrl
        ListElement{desc: "one"; url: "qrc:/ShapeContext.qml"}
    }

    Image {
        id: backImae
        source: "qrc:/background.png"
        anchors.fill: parent
    }

    ListView{
        id: leftView
        anchors.left: root.left
        anchors.top: root.top
        anchors.bottom: root.bottom
        width: 300
        //clip: true
        model: modelUrl
        delegate: Rectangle{
            border.color: "#00ffff"
            color: "#11223300"
            width: parent.width
            height: 50
            Text {
                id: name
                text: desc
                anchors.centerIn: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            TapHandler{
                onTapped: {
                    showItem(url)
                }
            }
            Rectangle{
                anchors.bottom: parent.bottom
                height: 2
                width: parent.width
                color: "#332"
            }
        }
    }
    Rectangle{
        id:verLine
        anchors.left: leftView.right
        width: 2
        height: root.height
        color: "#445"
    }
    Rectangle {
        id: comParent
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.left: verLine.right
        anchors.top: parent.top
        border.color: "#ff0000"
        border.width: 3
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        color: "#11223300"
    }
    Component{
        id:comObject
        Item {
            id: content
            anchors.fill: parent
            anchors.margins: 3
            property var itemurl
            Loader{
                anchors.fill: parent
                source: parent.itemurl
            }
        }
    }

    function showItem(url){
        var item = comObject.createObject(comParent, {"itemurl": url})
    }
}
