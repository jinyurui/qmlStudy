import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: root
    width: 640
    height: 480

    // listmodel 如何嵌套
    //    property ListModel rootModel: ListModel{
    //        ListElement{desc: "1.0"; subData: [ListElement{desc: "1.0-1"}]}
    //        ListElement{desc: "2.0"; subData: []}
    //        ListElement{desc: "3.0"; subData: []}
    //    }

    property var rootModel: [
        {"desc": "1.0", "subData": [{"desc": "1.0-1"},{"desc": "1.0-2"}]},
        {"desc": "2.0", "subData": []},
        {"desc": "3.0", "subData": []}
    ]

    ListView{
        id: mainView
        anchors.fill: parent
        model: root.rootModel
        snapMode: ListView.SnapToItem
        delegate: Item{
            width: 100
            height: childView.visible ? 30 + childView.height : 30
            property var modelSrc: modelData.subData
            property var nodeCount: modelSrc.length

            Rectangle{
                border.color: "black"
                width: 100
                height: 30
                Text {
                    anchors.centerIn: parent
                    text: modelData.desc
                }
                MouseArea{
                    id: mouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked:{
                        childView.visible = !childView.visible
                    }
                }
                Row{
                    visible: mouseArea.containsMouse
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    RoundButton{
                        text: "+"
                        width: 20
                        height: 20
                        onClicked: {
                            console.log("add")
                            rootModel[index]["subData"].push({"desc":"n.0-1"})
                            rootModel= rootModel
                        }
                    }
                    RoundButton{
                        text: "-"
                        width: 20
                        height: 20
                        onClicked: {
                            console.log("del")
                            rootModel[index]["subData"].pop()
                            rootModel = rootModel
                        }
                    }
                }
            }

            ListView{
                id: childView
                x: 10
                y: 30
                model: parent.modelSrc
                height: 30*parent.nodeCount
                visible: false
                delegate: Rectangle{
                    border.color: "red"
                    width: 90
                    height: 30
                    Text {
                        anchors.centerIn: parent
                        text: modelData.desc
                    }
                }
            }
        }
    }

}
