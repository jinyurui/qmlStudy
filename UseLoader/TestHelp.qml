import QtQuick 2.0

Item {
    property Component comDelegate
    property color backColor
    property int otherHelp
    width: childrenRect.width
    height: childrenRect.height
    // loader set com some proterties
    // so explicitly set the required information as a property of the Loader
    // (this works because the Loader sets itself as the context object for the component it is loading).
    Loader{
        id: loader
        property color useColor: backColor    // Loader add the seam protery, it is used by com
        width: 100
        height: 100
        sourceComponent: comDelegate
    }
}
