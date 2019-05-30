import QtQuick 2.0
import QtQuick 2.12

Rectangle{
    GridView{
        anchors.fill: parent
        cellHeight: 200
        cellWidth: 200
        //currentIndex: 0
        model: ListModel{
            id:listModel
            ListElement{desc: "blend"; url: ""}
        }
        clip: true
        delegate: GraphicalItem {
            text: desc
        }
    }
    color: "#12121200"
}
