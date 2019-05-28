import QtQuick 2.0
import QtQuick.Shapes 1.12

Item {
    id: element
    property real radius: element.width > element.height ? element.height/2 : element.width/2
    /***
    opengl fbo texture or samples
    layer.enabled: true
    layer.smooth: true
    layer.textureSize: Qt.size(element.width * 2, element.height * 2)
    layer.samples: 8
    ***/

    Shape{
        anchors.fill: parent
        ShapePath {
            id: blueBig
            strokeColor: "blue"
            strokeWidth: 5
            fillColor: "blue"
            capStyle: ShapePath.RoundCap
            joinStyle: ShapePath.BevelJoin
            startX: element.width/2 + element.radius
            startY: element.height/2
            PathArc {
                x: element.width/2 - element.radius
                y: element.height/2
                radiusX: element.radius ; radiusY: element.radius
                useLargeArc: true
            }
        }
        ShapePath{
            id: redGig
            strokeColor: "red"
            strokeWidth: 5
            fillColor: "red"
            capStyle: ShapePath.RoundCap
            joinStyle: ShapePath.BevelJoin
            startX: element.width/2 - element.radius
            startY: element.height/2
            PathArc {
                x: element.width/2 + element.radius
                y: element.height/2
                radiusX: element.radius; radiusY: element.radius
                useLargeArc: true
            }
        }
        ShapePath {
            id: blueSmall
            strokeColor: "blue"
            strokeWidth: 1
            fillColor: "blue"
            capStyle: ShapePath.RoundCap
            joinStyle: ShapePath.BevelJoin
            startX: element.width/2 - element.radius
            startY: element.height/2
            PathArc {
                x: element.width/2
                y: element.height/2
                radiusX: element.radius / 2; radiusY: element.radius / 2
                useLargeArc: true
            }
        }
        ShapePath{
            id: redSamll
            strokeColor: "red"
            strokeWidth: 1
            fillColor: "red"
            capStyle: ShapePath.RoundCap
            joinStyle: ShapePath.BevelJoin
            startX: element.width/2
            startY: element.height/2
            PathArc {
                x: element.width/2 + element.radius
                y: element.height/2
                radiusX: element.radius / 2; radiusY: element.radius / 2
                useLargeArc: true
                direction: PathArc.Counterclockwise
            }
        }
    }
    Timer{
        id: time
        running: true
        interval: 100
        repeat: true
        onTriggered: {
            element.rotation += 15
        }
    }
}
