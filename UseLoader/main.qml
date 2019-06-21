import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

/** node
* @key  Loader.sourceComponent ,
*       the create context can not get out property, so you should add loader proterty
* @desc
*/

/** node
* @key   Setting by Loader.setSource will not trigger any associated Behaviors.
* @desc
*/

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListModel {
        id: addressModel

        ListElement {
            address: "Aurel Vlaicu 3"
        }
        ListElement {
            address: "Cuza Voda 1"
        }
    }

    GridPage {
        id: paginatedGridView
        width: 400
        height: 300
        rowCount: 2
        columnCount: 3
        spacing: 5
        model: addressModel
        delegate: Rectangle{
            width: 50
            height: 30
            Text {
                anchors.centerIn: parent
                text: itemModel.address
            }
            border.color: Qt.lighter("yellow")
        }
    }

    PageIndicator {
        anchors.top: paginatedGridView.bottom
        anchors.margins: 20
        anchors.horizontalCenter: paginatedGridView.horizontalCenter
        currentIndex: paginatedGridView.currentPage
        count: paginatedGridView.pageCount
    }

    TestHelp{
        anchors.right: parent.right
        anchors.top: parent.top
        backColor: "red"
        otherHelp: 10
        comDelegate: Rectangle{
            color: useColor         // use Loader add proterty
            Text {
                anchors.centerIn: parent
                text: qsTr("text")
            }
        }
    }

    Component{
        id:comTest        //   com out put only useful
        Rectangle{
            id: combody   //   no use this id
            width: 100
            height: 100
            color: useColor
        }
    }

    Loader{
        id: comLoader
        sourceComponent: comTest
        anchors.top: parent.top
        anchors.right: parent.right
        property color useColor: "red"
    }

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        onClicked: {
            comLoader.useColor = Qt.rgba(Math.random(), Math.random(), Math.random())
        }
    }

    Component.onCompleted: {
        for(var i = 0 ; i < 100 ; i++){
            addressModel.append({"address":"hello__" + i})
        }
    }
}
