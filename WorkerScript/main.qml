import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQml.Models 2.12
/** node
* @key    listmodle sync diff thread, and list drag and drop
* @desc   this pro has question, so if you need self sort and on, you best use c++ cusmodel [ListModel]
*/
Window {
    id: root
    visible: true
    width: 1000
    height: 480

    ListModel{
        id: dataModel
        //dynamicRoles: false
        onCountChanged: {
            console.log("-----------cout change to : " + count)
        }
    }

    WorkerScript{
        id: worker
        source: "worker.js"
        onMessage: {
            //console.log("get info   " + messageObject.type + " : " + messageObject.ret)
        }
    }

    DelegateModel {
        id: visualModel

        //model: dataModel
        //delegate: dragDelegate
    }

    ListView {
        id: view

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        width: 200

        //model: visualModel

        //spacing: 4
        //cacheBuffer: 50
    }

    Component {
        id: dragDelegate

        MouseArea {
            id: dragArea

            property bool held: false

            anchors { left: parent.left; right: parent.right }
            height: content.height

            drag.target: held ? content : undefined
            drag.axis: Drag.YAxis

            onPressAndHold: held = true
            onReleased: held = false

            Rectangle {
                id: content
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter
                }
                width: dragArea.width; height: column.implicitHeight + 4

                border.width: 1
                border.color: "lightsteelblue"

                color: dragArea.held ? "lightsteelblue" : "white"
                Behavior on color { ColorAnimation { duration: 100 } }

                radius: 2
                Drag.active: dragArea.held
                Drag.source: dragArea
                Drag.hotSpot.x: width / 2
                Drag.hotSpot.y: height / 2
                states: State {
                    when: dragArea.held

                    ParentChange { target: content; parent: root }
                    AnchorChanges {
                        target: content
                        anchors { horizontalCenter: undefined; verticalCenter: undefined }
                    }
                }

                Column {
                    id: column
                    anchors { fill: parent; margins: 2 }

                    Text { text: 'Name: ' + name }
                    Text { text: 'Type: ' + type }
                    Text { text: 'Age: ' + age }
                    Text { text: 'Size: ' + size }
                }
            }
            DropArea {
                anchors { fill: parent; margins: 10 }

                onEntered: {
                    visualModel.items.move(

                                drag.source.DelegateModel.itemsIndex,
                                dragArea.DelegateModel.itemsIndex)
                }
            }
        }
    }

    ListView{
        id: otherView
        anchors.left: view.right
        anchors.leftMargin: 50
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        clip: true
        model: dataModel
        delegate: Component{
            Rectangle {
                id: contentR
                width: parent.width
                height: columnR.implicitHeight + 4
                border.width: 1
                border.color: "lightsteelblue"
                radius: 2
                Column {
                    id: columnR
                    anchors { fill: parent; margins: 2 }

                    Text { text: 'Name: ' + name }
                    Text { text: 'Type: ' + type }
                    Text { text: 'Age: ' + age }
                    Text { text: 'Size: ' + size }
                }
            }
        }
    }

    Row{
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 50
        spacing: 30
        Label{
            text: "model change"
        }
        Button{
            text: "add by gui thread"
            onClicked: {
                console.log("clicked")
                var start = new Date()
                for(var i = 0; i < 10; i++){
                    dataModel.append({ "name": "Polly_" + i,
                                         "type": "Parrot",
                                         "age": i%100,
                                         "size": "Small"})
                }
                var end = new Date()
                console.log("creat 100000 item time:  " + (end.valueOf() - start.valueOf())  + "ms")
                var message = {'action' : 'sync', 'srcModel': dataModel}
                worker.sendMessage(message)
            }
        }
        Button{
            text: "add by other thread"
            onClicked: {
                var message = {'action' : 'add', 'srcModel': dataModel}
                worker.sendMessage(message)
            }
        }
        Button{
            text: "sort by other thread"
            onClicked: {
                var message = {'action' : 'sort', 'srcModel': dataModel}
                worker.sendMessage(message)
            }
        }
        Button{
            text: "clear"
            onClicked: {
                //var message = {'action' : 'clear', 'srcModel': dataModel}
                //worker.sendMessage(message)
                dataModel.clear();
            }
        }
        Button{
            text: "move"
            onClicked: {
                var message = {'action' : 'move', 'srcModel': dataModel}
                worker.sendMessage(message)
                //dataModel.move(0,1,1)
            }
        }
        Button{
            text: "del"
            onClicked: {
                var message = {'action' : 'del', 'srcModel': dataModel}
                worker.sendMessage(message)
                //dataModel.remove(0)
            }
        }
    }
}

