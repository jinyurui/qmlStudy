import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    // 5.11， then you can use function for listmodel
    ListModel{
        id: gmodel
        ListElement{desc:"open"; callback:function(arg){console.log("open" + arg);popup.open();}}
        ListElement{desc:"close"; callback:function(arg){console.log("close" + arg);popup.close();}}
        ListElement{desc:"new"; callback:function(arg){
            console.log("new")
            otherLoad.properties = {"text":"from model","backColor": Qt.rgba(0, 1, 1, 0.2)}
            otherLoad.active = true
        }}
        ListElement{desc:"exit"; callback:function(arg){console.log("exit")}}
    }

    ListView{
        width: 200
        height: 400
        model: gmodel
        delegate: Button{
            text: desc
            height: 33
            width: parent.width
            onClicked: {
                callback(index)
            }
        }
    }

    Popup {
        id: popup
        x: 110
        y: 0
        width: 200
        height: 300
        padding: 0
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose
        Rectangle{
            anchors.fill: parent

            ListView{
                anchors.fill: parent
                model: gmodel
                delegate: Button{
                    text: desc
                    height: 33
                    width: parent.width
                }
            }
            Button{
                onClicked: popup.close()
                anchors.top: parent.top
                anchors.right: parent.right
                width: 30
                height: 30
            }
        }
    }


    // active and setSource
    Loader{
        id: otherLoad
        property var properties
        active: false
        width: 100
        height: 100
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        source: "Other.qml"
        QtObject{
            id: priviteNumber
            property bool hasSet: false
        }
        onActiveChanged: {
            if(active && !priviteNumber.hasSet){
                //  Setting the initial property values
                //of an instance of a component in this manner
                //will not trigger any associated Behaviors.
                // if active is false , the data will buffer
                setSource(source, properties)
                priviteNumber.hasSet = true
            }
        }

        onSourceChanged: {
            console.log("important  :: source has changed " + source)
        }


        // this Behavior will not case by Loader.setSource funtion
        Behavior on source {
             NumberAnimation { duration: 10000 }
        }
    }
}
