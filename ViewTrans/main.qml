import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import Water 1.0
// view transitions
Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Varlist{
        id: varlist
    }

    Flickable{
        id: root
        clip: true
        property var jsdata:[]
        anchors.fill: parent
        Column{
            Button{
                width: 50
                height: 50
                text: "btn"
            }
            Row{
                spacing: 10
                ListView{
                    id: view
                    width: 100
                    height: 300
                    clip: true
                    model: root.jsdata
                    boundsBehavior: Flickable.StopAtBounds
                    delegate: Rectangle{
                        width: parent.width
                        height: 20
                        Text {
                            anchors.centerIn: parent
                            text: modelData.desc + " :: " + modelData.skill
                        }
                        Behavior on x{
                            NumberAnimation{duration: 2000}
                        }
                    }
                    populate: Transition {
                        id: popuTrans
                        SequentialAnimation {
                            PauseAnimation {
                                duration: (popuTrans.ViewTransition.index -
                                           popuTrans.ViewTransition.targetIndexes[0]) * 100
                            }
                            NumberAnimation { properties: "x";from: -view.width; duration: 1000 }
                        }
                    }

                }
                Rectangle{
                    width: 2
                    color: "black"
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                }
                ViewTrans{
                    width: 100
                    height: 300
                }
            }
            Rectangle{
                width: parent.width
                height: 2
                color: "black"
            }
            Row{
                Button{
                    text: "up"
                    onClicked: {
                        var data = root.jsdata.slice(0);
                        data.sort(function(left, right){
                            return (left.skill - right.skill);
                        });
                        root.jsdata = data;
                    }
                }
                Button{
                    text: "down"
                    onClicked: {
                        var data = root.jsdata.slice(0);
                        data.sort(function(left, right){
                            return -left.skill + right.skill;
                        });
                        root.jsdata = data;
                    }
                }
                Button{
                    text: "add"
                    onClicked: {
                        var data = {"desc":"hello", "skill":5}
                        root.jsdata.push(data);
                        root.jsdata = root.jsdata;
                    }
                }
                Button{
                    text: "del_E"
                    onClicked: {
                        root.jsdata.pop();
                        root.jsdata = root.jsdata;
                    }
                }
                Button{
                    text: "del_1"
                    onClicked: {
                        if(root.jsdata.length > 1)
                            root.jsdata.splice(1,1);
                        root.jsdata = root.jsdata;
                    }
                }
            }
        }

        TransMouse{
            anchors.fill: parent
        }
    }
    Component.onCompleted: {
        var data = [];
        data.push({"desc":"god", "skill":20});
        data.push({"desc":"hello", "skill":10});
        data.push({"desc":"god", "skill":30});
        root.jsdata = data;
        // JSarray turn to varlist
        varlist.setVarList(data);
    }
}
