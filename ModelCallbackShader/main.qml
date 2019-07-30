import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ShaderEffect{
        id: shaderEff
        anchors.fill: parent
        property var rad: 0.0
        onRadChanged: {
            console.log("rad change :: " + rad)
        }
        property var color: Qt.lighter(rect.color)
        property var oldColor
        onColorChanged: {
            oldColor = color
        }
        vertexShader: "
                          uniform highp mat4 qt_Matrix;
                          attribute highp vec4 qt_Vertex;
                          attribute highp vec2 qt_MultiTexCoord0;
                          varying highp vec2 coord;
                          void main() {
                              coord = qt_MultiTexCoord0;
                              gl_Position = qt_Matrix * qt_Vertex;
                          }"
        fragmentShader: "
                  varying vec2 coord;
                  uniform float rad;
                  uniform vec4 color;
                  void main() {
                      if(distance(vec2(0.0,0.0), coord) < rad){
                          gl_FragColor = color;
                      }else{
                          gl_FragColor = vec4(0,1,1,0.0);
                      }
                  }"
    }

    Rectangle {
        id: rect
        width: 100; height: 100
        border.color: "#001111"
        state: "red_color"
        states: [
            State {
                name: "red_color"
                PropertyChanges { target: rect; color: "red"; radius: 35}
            },
            State {
                name: "blue_color"
                PropertyChanges { target: rect; color: "blue"; radius: 5}
            }
        ]

        transitions: [
            Transition {
                ColorAnimation{duration: 3000}
            }
        ]
        Behavior on radius{
            NumberAnimation {easing.type: Easing.InOutQuad; duration: 3000 }
        }

        Text {
            text: "apply"
            anchors.centerIn: parent
            color: "white"
        }

        MouseArea{
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                radAnimal.restart()
            }
        }
    }

    NumberAnimation{
        id: radAnimal
        target: shaderEff
        properties: "rad"
        to: 2.5
        duration: 1000
        onFinished: {

        }
    }


    Button{
        id: blueBtn
        anchors.right: parent.right
        anchors.top: parent.top
        width: 50
        height: 50
        onClicked: {
            shaderEff.rad = Qt.binding(function(){return 0.0})
            rect.state = "blue_color"
        }
        text: "b"
    }
    Button{
        id: redBtn
        anchors.right: parent.right
        anchors.top: blueBtn.bottom
        width: 50
        height: 50
        onClicked: {
            shaderEff.rad = Qt.binding(function(){return 0.0})
            rect.state = "red_color"
        }
        text: "r"
    }

}
