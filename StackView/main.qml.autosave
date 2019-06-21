import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // store the stackView items, poor JSarray, use push (add) pop(delete) [](reset)

    /** quetion
* @key    use jsarray as property, on change ?
* @desc
*/
    property var items: []
    property int itemCount: items.length//Qt.binding(function(){return items.length()})
    onItemCountChanged: {
        console.log("root.itemCountChange :: " + itemCount)
    }

    StackView{
        id: stackView
        anchors.top: parent.top
        anchors.bottom: bottomArea.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
        initialItem: null
        pushEnter: Transition {
            SequentialAnimation{
                PropertyAnimation {
                    property: "opacity"
                    from: 0
                    to:1
                    duration: 200
                }
                YAnimator{
                    from: - stackView.height;
                    to: 0;
                    duration: 200
                    easing.type: Easing.OutCubic
                }
            }
        }
        pushExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
                easing.type: Easing.OutCubic
            }
        }
        popEnter: Transition {
            SequentialAnimation{
                PropertyAnimation {
                    property: "opacity"
                    from: 0
                    to:1
                    duration: 500
                }
                YAnimator{
                    from: stackView.height;
                    to: 0;
                    duration: 500
                    easing.type: Easing.OutCubic
                }
            }
        }
        popExit: Transition {
            YAnimator {
                from: 0
                to: -stackView.height
                duration: 200
                easing.type: Easing.OutCubic
            }
        }
    }

    Component{
        id: comRect
        Rectangle{
            Text {
                anchors.centerIn: parent
                text: "this is " + stackView.depth + " page/n you can click this btn opt"
            }
            color: Qt.rgba(Math.random(),Math.random(),Math.random())
        }
    }

    Row{
        id: bottomArea
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20
        height: 40
        spacing: 20
        padding: 10
        Button{
            text: "+"
            font.bold: true
            onClicked: {
                var item = stackView.push(comRect)
                root.items.push(item)
            }
        }
        Button{
            text: "-"
            font.bold: true
            enabled: stackView.depth > 1
            onClicked: {
                var item = stackView.pop()
                root.items.pop(item)
            }
        }
        Button{
            text: "clear"
            font.bold: true
            onClicked: {
                stackView.clear(StackView.PopTransition)
                root.items = []
            }
        }
        Button{
            text: "first"
            font.bold: true
            onClicked: {
                var item = root.items[0]
                if(item){
                    stackView.pop(item)
                }
            }
        }
    }
}
