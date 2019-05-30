import QtQuick 2.0
import QtQuick 2.4
import QtGraphicalEffects 1.12

/** quetion
* @key   src rotation not effect to shadereffectsourc
* @desc  src rotation not effect to shadereffectsourc
*/
/** quetion
* @key    ShaderEffect use data
* @desc    eg mvpmat
*/
Item {
    id: element
    anchors.fill: parent
    Rectangle{
        id: srcTextImage
        width: 200
        height: 200
        radius: 100
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 0
        color: mouseArea.containsPress ? "#456789" : "#aabbcc"
        Text {
            id: strShow
            anchors.centerIn: parent
            color: mouseArea.containsPress ? "#000000" : "yellow"
            text: "3D-Text"
            font.pointSize: 20
        }

        DropShadow{
            anchors.fill: strShow
            color: "#000000"
            source: strShow
            horizontalOffset: 25   // off_x_y
            verticalOffset: 15
            radius: 5              // blu up when radius up ; samples = 1 + 2*radius
            spread: 0.3            // color up 0->1
        }

        MouseArea{
            id: mouseArea
            anchors.fill: parent
        }
        Timer{
            id: time
            repeat: true
            interval: 200
            running: true
            onTriggered: {
                srcTextImage.rotation += 15
            }
        }
    }

    ShaderEffectSource{
        id: iamgeSrc
        width: 150
        height: 150
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        sourceItem: srcTextImage
        sourceRect: Qt.rect(0, 0, srcTextImage.width, srcTextImage.height)
        //hideSource: true
    }
    ShaderEffect {
        id: shaderEffect
        width: 100
        height: 100
        clip: false
        supportsAtlasTextures: true
        anchors.verticalCenterOffset: 0
        anchors.right: parent.right
        anchors.rightMargin: 94
        anchors.verticalCenter: parent.verticalCenter
        property variant src: iamgeSrc
        vertexShader: "
                     uniform highp mat4 qt_Matrix;
                     attribute highp vec4 qt_Vertex;
                     attribute highp vec2 qt_MultiTexCoord0;
                     varying highp vec2 coord;
                     void main() {
                         coord = qt_MultiTexCoord0;
                         gl_Position = qt_Matrix *qt_Vertex;
                     }"
        fragmentShader: "
                     varying highp vec2 coord;
                     uniform sampler2D src;
                     void main() {
                         gl_FragColor = texture2D(src, vec2(coord.y, coord.x));
                     }"
    }

    Text {
        id: element1
        width: 100
        height: 30
        text: qsTr("src")
        anchors.horizontalCenter: srcTextImage.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        font.pixelSize: 12
    }

    Text {
        id: element2
        width: 100
        height: 30
        text: qsTr("shaderEffectSource")
        anchors.horizontalCenter: iamgeSrc.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        font.pixelSize: 12
    }

    Text {
        id: element3
        width: 100
        height: 30
        text: qsTr("shaderEffect")
        anchors.horizontalCenter: shaderEffect.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        font.pixelSize: 12
    }

}

