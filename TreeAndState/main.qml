import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Loader{
        id: mainLoader
        anchors.fill: parent
    }

    Component.onCompleted: {
        mainLoader.setSource("MainPage.qml")
    }
}
