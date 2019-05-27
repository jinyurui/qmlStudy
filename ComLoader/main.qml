import QtQuick 2.9
import QtQuick.Window 2.2
import Views 1.0

// question QQmlComponent: Created graphical object was not placed in the graphics scene.

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ViewManager{
        id: viewManager
        onCountChanged: {
            console.log(count)
        }

    }

    Rectangle{
        width: 100
        height: 100
        radius: 50
        color: Qt.rgba(255, 0 , 0, 100)
        anchors.centerIn: parent
        MouseArea{
            anchors.fill: parent
            id: redMouseArea
            onClicked: {
                viewManager.addCom(comRect)
                helpCreater.create()
            }
        }
    }

    Component{
        id: comRect
        Rectangle{
            width: 5
            height: 5
            radius: 2.5
            color: Qt.rgba(
                       0 + Math.round(Math.random()*1),
                       0 + Math.round(Math.random()*1),
                       0 + Math.round(Math.random()*1))
            x: 10 + Math.round(Math.random() * root.width)
            y: 10 + Math.round(Math.random() * root.height)
        }
    }

    QtObject{
        id: helpCreater
        function create(){
            var com = Qt.createComponent("qrc:/ComOptions.qml")
            if((com)&&(com.status == Component.Ready)){
                console.log("qml create com ok")
                var obj = com.createObject(root)
                if(obj){
                    console.log("then com create obj ok")
                }
            }else{
                console.log("err !!!" + com.status)
                switch(com.status){
                case Component.Error:{
                    console.log("error")
                    break;
                }
                case Component.Null:{
                    console.log("null")
                    break;
                }
                case Component.Ready:{
                    console.log("Ready")
                    break;
                }
                case Component.Loading:{
                    console.log("Loading")
                    break;
                }
                }
            }
        }
    }
}
