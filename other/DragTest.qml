import QtQuick 2.0

Rectangle {
    id: root
    width: 150
    height: view.currentIndex == index ? 56 : 50
    border.color: "black"
    border.width: view.currentIndex == index ? 3 : 0
    state: "mid"
    states: [
        State {
            name: "mid"
            PropertyChanges {
                target: midRect
                x:0
            }
        },
        State {
            name: "left"
            PropertyChanges {
                target: midRect
                x:50
            }
        },
        State {
            name: "right"
            PropertyChanges {
                target: midRect
                x:-50
            }
        }
    ]
    signal showInfo(var index)
    signal deleteItem(var index)
    signal itemClicked(var index)
    Rectangle {
        id: leftRect
        anchors.right:midRect.left
        anchors.top: parent.top
        anchors.topMargin: view.currentIndex == index ? 3 : 0
        width: 50
        height: 50
        color: "red"
        MouseArea{
            enabled: root.state == "left"
            anchors.fill: parent
            onClicked: {
                showInfo(index)
            }
        }
    }

    Rectangle{
        id:rightRect
        anchors.top: parent.top
        anchors.topMargin: view.currentIndex == index ? 3 :0
        anchors.left: midRect.right
        width: 50
        height: 50
        color: "yellow"
        MouseArea{
            enabled: root.state == "right"
            anchors.fill: parent
            onClicked: {
                deleteItem(index)
            }
        }
    }

    Rectangle{
        id:midRect
        anchors.top: parent.top
        anchors.topMargin: view.currentIndex == index ? 3 : 0
        width: 150
        height: 50
        color: "blue"
        Text {
            anchors.centerIn: midRect
            text: model.desc
        }
        MouseArea {
            id: mouseArea
            anchors.fill: parent
            drag.target: midRect
            drag.axis: Drag.XAxis
            drag.minimumX: -50
            drag.maximumX: 50

            property bool isDraging: drag.active

            onIsDragingChanged: {
                // end drag
                if(!isDraging){
                    // drag to left over 1/3 width of rightRect
                    if((midRect.x < -rightRect.width/3)&&root.state == "mid"){
                        console.log("right")
                        root.state = "right"
                    }else if((midRect.x > leftRect.width/3)&&root.state == "mid"){// // drag to right over 1/3 width of leftRect
                        console.log("left")
                        root.state = "left"
                    }else{
                        console.log("mid")
                        // err root mid state is no effect
                        root.state = "mid"
                        midRect.x = 0
                    }
                }
            }

            onReleased: {
                view.currentIndex = index
                itemClicked(index)
            }
        }
    }

}
// x range -50 50
//  left -25 0 25 right
//

