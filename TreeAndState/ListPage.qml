import QtQuick 2.0
import QtQuick.Controls 2.5

// ListModel function opt jsobject
// use Loader not item's visible as subnode
Item {
    id: root
    width: 640
    height: 480

    property ListModel rootModel: ListModel{}

    ListView{
        id: mainView
        anchors.fill: parent
        model: rootModel
        snapMode: ListView.SnapToItem
        delegate: Item{
            width: 100
            height: subLoader.active ? 30 + subLoader.height : 30
            Rectangle{
                border.color: "black"
                width: 100
                height: 30
                Text {
                    anchors.centerIn: parent
                    text: desc
                }
                MouseArea{
                    id: mouseArea
                    anchors.fill: parent
                    hoverEnabled: true
                    onClicked:{
                        subLoader.active = !subLoader.active
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
                            var data = rootModel.get(index).subData;
                            data.append({"desc": data.count.toString(10)})
                        }
                    }
                    RoundButton{
                        text: "-"
                        width: 20
                        height: 20
                        onClicked: {
                            var data = rootModel.get(index).subData;
                            data.remove(data.count - 1)
                        }
                    }
                }
            }
            Loader{
                id: subLoader
                x: 10
                y: 30
                active: false
                height: 30*subData.count
                sourceComponent: ListView{
                    model: subData
                    delegate: Rectangle{
                        border.color: "red"
                        width: 90
                        height: 30
                        Text {
                            anchors.centerIn: parent
                            text: desc
                        }
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        rootModel.append({"desc":"hello", "subData":[{"desc":"1.0"}]})
    }
}
