import QtQuick 2.0
import QtQuick.Controls 2.5
Item {
    id: root

    SwipeView {
        id: view
        currentIndex: 0
        anchors.fill: parent

        Item {
            id: firstPage
            Text {
                anchors.centerIn: parent
                text: qsTr("firstPage")
            }
        }
        Item {
            id: secondPage
            Text {
                anchors.centerIn: parent
                text: qsTr("secondPage")
            }
        }
        Item {
            id: thirdPage
            Text {
                anchors.centerIn: parent
                text: qsTr("thirdPage")
            }

        }
    }

    PageIndicator {
        id: indicator

        count: view.count
        currentIndex: view.currentIndex

        anchors.bottom: view.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ComboBox{
        id: conbox
        anchors.right: parent.right
        anchors.top: parent.top
        width: 100
        height: 50
        model: view.count
        currentIndex: 0
        onActivated: {
            view.currentIndex = currentIndex
        }
    }
}
