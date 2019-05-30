import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    id: root
    visible: true
    width: 860
    height: 480
    title: qsTr("Hello World")
    Rectangle{
        id: leftView
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        width: root.width/5
        color: "#666666"
        ListView{
            id: listView
            anchors.fill: parent
            model: 5
            delegate: Rectangle{
                width: parent.width
                height: 50
                color: "#123123"
                Text {
                    id: showStr
                    anchors.centerIn: parent
                    text: index
                    color: "#89a89a"
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        listView.currentIndex = index
                        stackViewPush(index)
                    }
                }
            }
        }
    }
    Rectangle{
        id: vline
        width: 2
        height: root.height
        color: "#aaaaaa"
        anchors.left: leftView.right
        anchors.leftMargin: 0
    }
    Rectangle{
        id: title
        height: 100
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: vline.right
        anchors.leftMargin: 0
        color: "#224488"
        Text {
            anchors.centerIn: parent
            text: listView.currentIndex
            font.pointSize: 18
            font.bold: true
        }
    }
    Rectangle{
        id: hline
        height: 2
        color: "#cccccc"
        anchors.left: vline.right
        anchors.leftMargin: 0
        anchors.top: title.bottom
        anchors.topMargin: 0
        width: root.width - leftView.width - 3
    }
    StackView{
        id: mainView
        anchors.top: hline.bottom
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: vline.right
        anchors.leftMargin: 0
//        initialItem:Text3D{
//            anchors.fill: parent
//        }
        initialItem: Gama{
            anchors.fill: parent
        }
    }
    ListModel{
        id:graphiclModel
    }

    function stackViewPush(index){
        //mainView.push("qrc:/GraphicalEffect.qml")
    }
}



