import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Ball{
        id:behaviorBall
        ballR: 30
        showStr: "Behavior"
        color: "#00ffff"
        // object property changed
        Behavior on y{
            NumberAnimation{
                easing.type: Easing.InQuint
                duration: 1000
            }
        }
    }

    Ball{
        id:animalBall
        ballR: 30
        showStr: "Animal on"
        color: "#ff0000"
        // animal on ,
        NumberAnimation on y {
            to: 400
            duration: 4000
        }
    }

    Ball{
        id: aloneBall
        x:(parent.width-width)/2
        ballR: 30
        color: "#0000ff"
        showStr: "alone animal"
    }

    Ball{
        id: groupBall
        ballR: 10
        color: "#889900"
        showStr: "G"
    }

    NumberAnimation{
        id: aloneAnimation
        target: aloneBall
        properties: "y"
        from: 0
        to:400
        duration: 4000
        running: false
        onStopped: {
            console.log("aloneAnimal stop")
        }
    }

    ParallelAnimation{
        id:groupAnimation
        SequentialAnimation{
            loops: 5
            NumberAnimation{
                target: groupBall
                properties: "x"
                to: root.width
                duration: 800
            }
            NumberAnimation{
                target: groupBall
                properties: "x"
                to: 0
                duration: 800
            }
        }
        NumberAnimation{
            target: groupBall
            properties: "y"
            from: 0
            to: 400
            duration: 8000
        }

        ScaleAnimator{
            target: groupBall
            from: 1.0
            to: 2.0
            duration: 8000
        }
        RotationAnimation{
            target: groupBall
            to: 360
            duration: 8000
        }
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            behaviorBall.y = Math.round(Math.random()*400)
            animalBall.y = 20
            aloneAnimation.restart()
            groupAnimation.start()
        }
    }

}
