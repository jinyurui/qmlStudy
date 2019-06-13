import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick 2.12
import QtQuick.Controls 2.12
import CPLUSE 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    DataCon{
        id: dataCon
    }

    ListView{
        width: 400
        height: 300
        model: dataCon.dataList
        delegate: Rectangle{
            width: parent.width
            height: 50
            Text {
                anchors.centerIn: parent
                text: index + "__[ " + modelData.name + ":: " + modelData.count + "]"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }
}
