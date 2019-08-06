import QtQuick 2.12
import QtQuick.Window 2.12
import Water 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // top dataflow
    DataFlow{
        id: rootDataFlow
    }

    property var externProterties: {
        "border.color":"yellow",
        "border.width": 5,
        "text": "qml"
    }


    Component.onCompleted: {
        console.log("----- qml ----- creating !!!!!!!")
        // you can wrapper the pro
        var com = Qt.createComponent("TestPage.qml")
        if(com){
            var obj = com.createObject(root, externProterties)
            rootDataFlow.dataAnalysis(com, obj)
        }

        console.log("----- c++ ----- creating !!!!!!!")
        var item = rootDataFlow.createItem("qrc:/TestPage.qml")
        if(item){
            console.log("item info[w: " + item.width +",h: " + item.height + "]")
        }
    }
}
