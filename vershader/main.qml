import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 300
    title: qsTr("Hello World")

    Rectangle{
        width: 400
        height: 300
        anchors.fill: parent
        color: "#00ff99"
        Row{
            anchors.fill: parent
            anchors.margins: 20
            spacing: 0
            Image {
                id: imageSrc
                source: "./apple.svg"
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: parent.width/2
            }

            ShaderEffectSource{
                id: shaderSrc
                sourceItem: imageSrc
                visible: false
            }

            ShaderEffect{
                id: vanishShader
                anchors.top: parent.top
                anchors.bottom: parent.bottom
                width: parent.width/2

                property variant source: shaderSrc
                property real vertexBend: 0
                property real vertexMinimize: 0
                property real vertexSide: vanishSlider.value
                SequentialAnimation on vertexBend {
                    loops: Animation.Infinite
                    NumberAnimation { to: 1; duration: 700; easing.type: Easing.InOutSine }
                    PauseAnimation { duration: 1600 }
                    NumberAnimation { to: 0; duration: 700; easing.type: Easing.InOutSine }
                    PauseAnimation { duration: 1000 }
                }
                SequentialAnimation on vertexMinimize {
                    loops: Animation.Infinite
                    PauseAnimation { duration: 300 }
                    NumberAnimation { to: 1; duration: 700; easing.type: Easing.InOutSine }
                    PauseAnimation { duration: 1000 }
                    NumberAnimation { to: 0; duration: 700; easing.type: Easing.InOutSine }
                    PauseAnimation { duration: 1300 }
                }

                mesh: Qt.size(10, 10)

                vertexShader:
                "uniform highp mat4 qt_Matrix;
                uniform highp float vertexBend;
                uniform highp float vertexMinimize;
                uniform highp float vertexSide;
                uniform highp float width;
                uniform highp float height;
                attribute highp vec4 qt_Vertex;
                attribute highp vec2 qt_MultiTexCoord0;
                varying highp vec2 qt_TexCoord0;

                void main() {
                    qt_TexCoord0 = qt_MultiTexCoord0;
                    highp vec4 pos = qt_Vertex;
                    pos.y = mix(qt_Vertex.y, height, vertexMinimize);
                    highp float t = pos.y / height;
                    t = (3. - 2. * t) * t * t;
                    pos.x = mix(qt_Vertex.x, vertexSide * width, t * vertexBend);
                    gl_Position = qt_Matrix * pos;
                }"
            }
        }

        Slider{
            id: vanishSlider
            value: 0
            from: 0
            to: 10
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.margins: 30
            width: 100
            height: 30
        }
    }
}
