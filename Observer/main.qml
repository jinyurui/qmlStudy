import QtQuick 2.9
import QtQuick.Window 2.2
import Water 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea{
        anchors.fill: parent
        onClicked: {
            GDataSum.testSubjectCallBack()
        }
    }
}
