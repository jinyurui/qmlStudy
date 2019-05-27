import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    id: root

    Component{
        id:comScrollView
        ScrollView{
            id: scrollView
            anchors.centerIn: parent
            Column{
                Slider{
                    id: easySlider
                    from: 0
                    to: 100
                    value: 20
                }

                Slider{
                    id: customSlider
                    from: -10.00
                    to: 10.00
                    value: easySlider.visualPosition*20 - 10
                    width: 500
                    height: 110
                    background: Rectangle{
                        x:customSlider.leftPadding
                        y:customSlider.topPadding + customSlider.availableHeight/2 - height / 2
                        height: 100
                        width: customSlider.availableWidth
                        color: "#00ffff"
                        radius: 10
                        border.color: "black"
                        border.width: 5
                        Rectangle{
                            height: 100
                            width: customSlider.visualPosition * parent.width
                            color: customSlider.pressed ? "#C435F6" : "#84C461"
                            radius: 10
                        }

                    }
                    handle: Rectangle{
                        x: customSlider.leftPadding + customSlider.visualPosition * (customSlider.availableWidth - width)
                        y: customSlider.topPadding + customSlider.availableHeight / 2 - height / 2
                        width: 50
                        height: 50
                        radius: 25
                        color: customSlider.pressed ? "red" : "black"
                        border.color: !customSlider.pressed ? "red" : "black"
                    }
                    onMoved: {
                        console.log(customSlider.value)
                    }
                    onValueChanged: {
                        console.log(customSlider.visualPosition)
                    }
                }

                Rectangle{
                    id: rect
                    color: "#00ffff"
                    width: parent.width
                    height: 50

                    Text{
                        property string highlightColor: "red"
                        property string highlightText: "Hello"
                        property string originText: "Hello world 123"
                        text: coloredText()

                        function coloredText() {
                            var re = new RegExp(highlightText,"gi");
                            return originText.replace(re, function(word){
                                return "<font color='" + highlightColor + "'>" + word + "</font>";} )
                        }
                    }
                }
            }
        }
    }

    Loader{
        id: scrollViewLoader
        sourceComponent: comScrollView
        active: true
    }

    Component{
        id:comBall
        Ball{
        }
    }

    Loader{
        id: ballLoader
        sourceComponent: comBall
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            console.log("clicked")
            //            var com = Qt.createComponent("./Ball.qml")
            //            //Component.Error, see Component::errorString() f
            //            if(com.status == Component.Error ){
            //                console.log("err : " + com.errorString())
            //            }
            //            if(!com && com.status == Component.Ready ){
            //                console.log("com ok")
            //                var obj = com.createObject(com, {"color": Qt.rgba(
            //                                                              0 + Math.round(Math.random()*255),
            //                                                              0 + Math.round(Math.random()*255),
            //                                                              0 + Math.round(Math.random()*255)
            //                                                              )})
            //                if(!obj){
            //                    console.log("create obj")
            //                }
            //            }
            //
            ballLoader.x = mouseX
            ballLoader.y = mouseY
            ballLoader.item = Qt.binding(function(){
                return Qt.rgba(
                            0 + Math.round(Math.random()*1),
                            0 + Math.round(Math.random()*1),
                            0 + Math.round(Math.random()*1))
            })
        }
    }



    //    no use
    //    Component.onCompleted: {
    //        rect.width = Qt.binding(function(){return this.height*3})
    //    }

}
