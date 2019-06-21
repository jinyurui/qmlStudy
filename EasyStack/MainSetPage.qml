import QtQuick 2.0
import QtQuick.Controls 2.5

CusRect {
    id: root
    property int currentIndex: -1
    property var descs: ["dir","voice","save","history","about"]

    Button{
        id: backBtn
        width: 80
        height: 30
        text: "back"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 20
        onClicked: {
            if(setStack.depth == 1){
                currentIndex = -1
                mainStack.pop()
            }else{
                currentIndex = -1
                setStack.pop()
            }
        }
    }
    Text {
        text: setStack.depth == 1 ? "mainpage" : descs[currentIndex]
        color: Qt.lighter("red")
        font.pointSize: 24
        font.bold: true
        anchors.left: backBtn.right
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 12
    }

    StackView{
        id: setStack
        anchors.top: backBtn.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.topMargin: 20
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        initialItem: gridSetCom
    }


    ListModel{
        id: setModel
        ListElement{
            desc: "dir_set"
        }
        ListElement{
            desc: "voice_set"
        }
        ListElement{
            desc: "save_set"
        }
        ListElement{
            desc: "history_set"
        }
        ListElement{
            desc: "about_set"
        }
    }

    Component{
        id: gridSetCom
        GridView{
            id: gridSetView
            model: setModel
            cellWidth: 100
            cellHeight: 100
            delegate: Rectangle{
                color: Qt.lighter("#667788")
                width: 80
                height: 80
                border.color: "yellow"
                Text {
                    anchors.centerIn: parent
                    text: desc
                    color: "black"
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: Text.WordWrap
                }
                MouseArea{
                    id: mouseArea
                    anchors.fill: parent
                    onClicked: {
                       setStack.push("CusRect.qml")
                        root.currentIndex = index
                    }
                }
            }
        }
    }
}
