import QtQuick 2.0

// if use Loader or Repeater ...  you can not use destroy

Rectangle {
    id: root
    width: 100
    height: 100
    radius: 50
    color: "red"
    opacity: 1
    Component.onCompleted: {
        console.log("create and render")
        showTime.start()
    }
    Component.onDestruction: {
        console.log("del")
    }

    // animal only diff Behavior, property change case Behavior
    NumberAnimation on opacity{to: 0; duration: 3000}
    NumberAnimation on y{to: 0; duration: 3000}

    Timer{
        id: showTime
        repeat: false
        interval: 3000
        onTriggered: {
            root.destroy()
        }
    }
}
