import QtQuick 2.0
import QtQuick 2.12

Item {
    id: root
    width: 200
    height: width

    property color srcColor: "yellow"        // backGroundColor
    property real speTime: 1000               // animalTime
    property color preColor: Qt.rgba(1,0,0,1)// pressColor
    property string text: "Qt"
    property var textItem: context

    signal itemClick()

    Rectangle{
        id: rectSrc
        width: root.width
        height: width
        radius: width/2
        clip: true
        color: srcColor
        visible: false
    }

    Text{
        id: context
        anchors.centerIn: parent
        text: root.text
        color: "black"
        font.pointSize: 24
        z: shaderEffectSrc.z + 1
    }
    ShaderEffectSource{
        id: shaderEffectSrc
        sourceItem: rectSrc
        anchors.fill: rectSrc
        clip: true

        MouseArea{
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                uperAnimal.restart()
                root.itemClick()
            }
        }

        NumberAnimation {
            id: uperAnimal
            target: shaderEffect
            property: "uper"
            duration: speTime
            to: 1.0
            running: false
            easing.type: Easing.InOutQuad
            onStopped: {
                shaderEffect.uper = 0.0
                shaderEffect.clickX = 0.0
                shaderEffect.clickY = 0.0
            }
        }
        ShaderEffect{
            id: shaderEffect
            anchors.fill: parent
            property variant src: shaderEffectSrc
            property real clickX//: mouseArea.mouseX/200
            property real clickY//: mouseArea.mouseY/200
            property real uper: 0.0
            property color preColor: root.preColor
            fragmentShader:"
uniform float clickX;
uniform float clickY;
uniform float uper;
uniform vec4  preColor;

uniform sampler2D src;
uniform lowp float qt_Opacity;
varying vec2 qt_TexCoord0;

void main()
{
    float s2 = distance(qt_TexCoord0, vec2(clickX, clickY));
    float s1 = distance(qt_TexCoord0, vec2(0.5, 0.5));
    float a1 = 1.0-smoothstep(0.5-0.01, 0.5, s1);
    float a2 = 1.0-smoothstep(uper, 0.01+uper, s2);
    gl_FragColor = vec4(vec3(preColor), a1*a2);
}"
        }

    }
/** node
* @key  more opt bind and release  ,  more bing can view qmlBinding
* @desc
*/
    property url qmlBinding: "https://zhuanlan.zhihu.com/p/56401271"
    Binding{
        target: shaderEffect
        property: "clickX"
        value: mouseArea.mouseX/200
        when: mouseArea.pressed
    }
    Binding{
        target: shaderEffect
        property: "clickY"
        value: mouseArea.mouseY/200
        when: mouseArea.pressed
    }
    Component.onCompleted: {
//        running  Binding
//        shaderEffect.clickX = Qt.binding(function(){
//            return mouseArea.mouseX/200;
//        })
//        shaderEffect.clickY = Qt.binding(function(){
//            return mouseArea.mouseY/200;
//        })
    }
}



