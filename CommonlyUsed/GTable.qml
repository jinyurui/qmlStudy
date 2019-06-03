import QtQuick 2.0
import QtQuick 2.12
import cppContext 1.0

/** node
* @key  tableView based on QtQuick 2
* @desc
*/
Item {
    id: root

    TableView {
        anchors.fill: parent
        flickableDirection: Flickable.HorizontalAndVerticalFlick
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        // only read col and row
        model: TableModel{
            id: tableModel
        }
        /** node
            * @key ListModel only show first col
            * @desc
            */
        /*
            ListModel{
            ListElement{name:"water"; desc:"fire";rich:10}
            ListElement{name:"good"; desc:"per";rich:5}
            ListElement{name:"black"; desc:"blue";rich:2}
            }
            */

        delegate: Component{
            Rectangle{
                implicitHeight: 50
                implicitWidth: 200//column == 0 ? 200 : (column == 1 ? 300 : 100)
                color: column == 0 ? "#0000ff" :(column == 1 ? "#000044" : "#11223300")
                Text {
                    text: column == 0 ? desc : skill
                    anchors.centerIn: parent
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: column == 0 ? "black" : "yellow"
                    visible: column != 2
                }
                Row{
                    visible: column == 2
                    Repeater{
                        model: rich
                        Rectangle{
                            width: 10
                            height: 10
                            radius: 5
                            color: "red"
                        }
                    }
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        //console.log("ckick index:" + index + "[ " + row + "," +column + "]")
                    }
                }
            }
        }
    }
}
