import QtQuick 2.0
import QtQuick.Controls 2.5

Item {
    id: root
    Rectangle{
        id: backGround
        color: "#333e66"
        anchors.fill: parent
    }

    property bool check: mainAnimaCheck.checked

    // 对于定位的控件，其x y属性无法发生对应的动画
    // 属性改变导致的行为，改变即发生动画
    Behavior on check{
    SequentialAnimation{
        id: mainAnima
        ParallelAnimation{
            PropertyAnimation{
                target: controlBtn
                properties: "y"
                to: 0
            }
            PropertyAnimation{
                target: controlBtn
                properties: "scale"
                from: 0.2
                to: 2.0
            }

        }
        PropertyAnimation{
            target: controlBtn
            properties: "y"
            to: root.height - controlBtn.height - 20
        }
    }
    }

    // 属性改变 diff 属性动画, 改变状态可通过 state = value， 或者 State的when属性
    state: "A"
    states: [
        State {
            name: "A"
            //when:
            PropertyChanges{
                target: ball
                y: -ball.width - 20
                scale: 0.2
            }
        },
        State{
            name: "B"
            PropertyChanges {
                target: ball
                y: (root.height-ball.height)/2
                scale: 2
            }
        }
    ]
    // 属性变化的动画过渡
    transitions: [Transition {
            from: "A"
            to: "B"
            NumberAnimation{duration: 1500; target: ball; properties: "y, scale"}
        },
        Transition {
            from: "B"
            to: "A"
            NumberAnimation{duration: 750; target: ball; properties: "y, scale"}
        }
    ]

    Rectangle{
        id: ball
        x: (root.width - width)/2
        color: "#00FFFF"
        width: 30
        height: 30
        radius: 15
    }

    RoundButton{
        id: controlBtn
        x: (root.width - width)/2
        y: root.height - height - 20
        width: 20
        height: 20
        onClicked: {
            if(root.state == "A"){
                root.state = "B"
            }else{
                root.state = "A"
            }
        }
    }

    CheckBox{
        id: mainAnimaCheck
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        width: 20
        height: 20
    }
}
