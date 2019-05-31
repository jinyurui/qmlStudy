import QtQuick 2.0
import QtGraphicalEffects 1.12
import QtQuick.Controls 2.5

Item {
    id: element
    width: childrenRect.width
    Image {
        id: opImage
        source: "balls.jpg"
        smooth: true
        visible: false
    }

    BrightnessContrast {
        id: brightGraphical
        anchors.fill: opImage;
        source: opImage;
        brightness: bslider.value;
        contrast: cslider.value;
    }
    Text {
        id: blabel;
        text: "Brightness:"
        anchors.left: opImage.left;
        anchors.top: opImage.bottom;
        anchors.margins: 4;
    }

    Slider {
        id: bslider;
        anchors.left: blabel.right;
        anchors.leftMargin: 8;
        anchors.verticalCenter: blabel.verticalCenter;
        anchors.verticalCenterOffset: 0
        value: 0.5;
        from: -1.0
        to:1.0
    }
    Text {
        id: clabel;
        text: "Contrast:"
        anchors.left: blabel.left;
        anchors.top: bslider.bottom;
        anchors.topMargin: 4;
    }

    Slider {
        id: cslider;
        anchors.left: bslider.left;
        anchors.verticalCenter: clabel.verticalCenter;
        value: 0.5;
        from: -1.0
        to:1.0
    }


    Image {
        id: srcImage
        anchors.left: opImage.right
        anchors.leftMargin: 30
        source: "balloons.jpg"
        smooth: true
        visible: false
    }
    /** quetion
* @key    gamma no effect
* @desc
*/
    //    GammaAdjust{
    //        source: srcImage
    //        anchors.fill: srcImage
    //        gamma: gamma.value
    //    }
    LevelAdjust {
        id: levelGraphical
        anchors.fill: srcImage
        source: srcImage
        minimumOutput: Qt.rgba(0.0, 0.0, 0.0)
        maximumOutput: Qt.rgba(redValue.value, greenValue.value, blueValue.value)
        gamma: Qt.vector3d(0.3, 0.6, 0.9)
    }
    Slider{
        id: redValue
        anchors.left: srcImage.left
        anchors.top: srcImage.bottom
        from: 0
        to: 1
    }
    Slider{
        id: greenValue
        anchors.left: srcImage.left
        anchors.top: redValue.bottom
        from: 0
        to: 1
    }
    Slider{
        id: blueValue
        anchors.left: srcImage.left
        anchors.top: greenValue.bottom
        from: 0
        to: 1
    }

    Blend {
        id:blendGraphical
        anchors.left: srcImage.right
        anchors.leftMargin: 30
        width: srcImage.width
        height: srcImage.height
        source: brightGraphical
        foregroundSource: levelGraphical
        mode: "subtract"
    }

    Rectangle{
        id: srcRect
        width: 100
        height: 30
        radius: 5
        color: "#abcdef"
        anchors.left: blendGraphical.right
        anchors.leftMargin: 30
        anchors.top: parent.top
        anchors.topMargin: 50
    }
    RectangularGlow{
        width: 50
        height: 15
        anchors.centerIn: srcRect
        spread: 0.2
        color: "#55ff55"
        glowRadius:2

    }
    Glow{
        anchors.left: srcRect.left
        anchors.top: srcRect.bottom
        anchors.topMargin: 20
        width: srcRect.width
        height: srcRect.height
        source: srcRect
        color: Qt.lighter("yellow")
        spread: 0.8
        samples: 19
        MouseArea{
            anchors.fill: parent
            onClicked: {
                console.log("click")
            }
        }
    }

}
