import QtQuick 2.12
import QtQuick.Window 2.12
import Water 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    DataSrc{
        id: rootData
        // append
        cars: [
            Car{name: "DQ"; price: 76},
            Car{name: "PKF"; price: 123}
        ]
    }

    Component.onCompleted: {
        console.log("car count >>  " + rootData.cars[0].name)
    }
}
