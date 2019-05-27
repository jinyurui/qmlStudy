import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import CPLUS 1.0

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property int showIndex: -1
    property string itemInfo: getInfo(showIndex)
    onItemInfoChanged: {
        console.log(itemInfo)
    }
    function getInfo(index){
        switch(index){
        case 0:
            return "1q"
        case 1:
            return "2w"
        case 2:
            return "3e"
        case 3:
            return "4e"
        default:
            return ""
        }
    }

    ListModel{
        id:viewModel
        ListElement{desc : "Q"}
        ListElement{desc : "W"}
        ListElement{desc : "E"}
        ListElement{desc : "R"}
    }

    SrcText{
        id: srcText
    }

    Column{
        anchors.fill: parent
        Row{
            id: rowView
            spacing: 20

            ListView{
                id:view
                width: 150
                height: 210
                model: viewModel
                currentIndex: -1
                delegate: DragTest{
                    onShowInfo: {
                        showIndex = index
                    }
                    onDeleteItem: {
                        viewModel.remove(index)
                    }
                    onItemClicked: {
                    }
                }
                clip: true
            }

            Text {
                id: name
                color: "#00ffff"
                font.bold: true
                width: 60
                height: 50
                font.pointSize: 24
            }
            Binding{
                target: name
                property: "text"
                value: srcText.name
            }
            Rectangle{
                width: 70
                height: 70
                color: "#11223300"
                Image{
                    anchors.centerIn: parent
                    source: mouseArea.pressed ? "qrc:/icon-60-back-blue.png" : "qrc:/back.png"
                }
                MouseArea{
                    anchors.fill: parent
                    id: mouseArea
                    onClicked: {
                        //viewModel.append({desc: "123"})
                        viewModel.insert(view.currentIndex + 1, {desc: "123"})
                    }
                }
            }

            Text {
                id: other
                color: "#00ffff"
                font.bold: true
                font.pointSize: 24
                width: 60
                height: 50
            }
        }

        Rectangle{
            width: parent.width
            height: 300
            border.color: "black"
            Flipable{
                id:flipable
                property bool flipped: false
                anchors.fill: parent

                front: ShaderEffectSource{
                    sourceItem: rowView
                    sourceRect: Qt.rect(0, 0, rowView.width/2, rowView.height)
                    anchors.fill: parent
                }
                back: ShaderEffectSource{
                    sourceItem: rowView
                    sourceRect: Qt.rect(rowView.width/2, 0, rowView.width/2, rowView.height)
                    anchors.fill: parent
                }

                transform: Rotation {
                    id: rotation
                    origin.x: flipable.width/2      // rotation base pos (center)
                    origin.y: flipable.height/2
                    axis.x: 1; axis.y: 0; axis.z: 0 // rotation by x
                    angle: 0                        // the default angle
                }

                states: State {
                    name: "back"
                    PropertyChanges { target: rotation; angle: 180 }
                    when: flipable.flipped
                }

                transitions: Transition {
                    NumberAnimation { target: rotation; property: "angle"; duration: 4000 }
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        flipable.flipped = !flipable.flipped
                        console.log(flipable.state)
                    }
                }

            }
        }

    }
    Component.onCompleted: {
        console.log("com ok")
        other.text = Qt.binding(function(){
            return srcText.name
        })
    }

    // item layout by out json, under proterty set time, com ok.
    Rectangle{
        //z: 100
        visible: false
        anchors.fill: parent
        border.color: "yellow"
        LayoutTest{
            id: layoutTest
            layoutID: "LayoutTest"
            anchors.top: parent.top
            anchors.left: parent.left
        }
    }
}
