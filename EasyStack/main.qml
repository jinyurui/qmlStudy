import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    StackView{
        id: mainStack
        anchors.fill: parent
        initialItem: CusRect{
            Button{
                id: optBtn
                text: "opt"
                width: 50
                height: 50
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.margins: 20
                onClicked: {
                    mainStack.push("MainSetPage.qml")
                }
            }
        }
    }
}
