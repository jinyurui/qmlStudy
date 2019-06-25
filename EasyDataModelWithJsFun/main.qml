import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.5

import water 1.0
import "./Functons.js" as SortHelper


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    EndData{
        id: endDataSrc
    }

    ListView{
        id: view
        anchors.fill: parent
        model: endDataSrc.listData  //  QVarlist so , it is data
        delegate: Component{
            Loader{
                property var itemModel: modelData //typeof modelData !== "undefined" ? modelData : endDataSrc.listData
                property int itemIndex: index
                width: view.width
                height: 50
                sourceComponent: loaderCom
            }
        }
        /** quetion
        * @key   the model how to be easy set
        * @desc
        */
//        delegate: Rectangle{
//            width: view.width
//            height: 50
//            color: "yellow"
//            Text{
//                text: index + "____" +
//                      styleData.modelData.desc +  "____" +
//                      styleData.modelData.count
//            }

//        }
    }


    Text {
        anchors.top: parent.top
        anchors.right: parent.right
        text: endDataSrc.listData.length
    }

    Component{
        id: loaderCom
        Rectangle{
            anchors.fill: parent
            Row{
                spacing: 220
                Text {
                    id: descStr
                    text: itemModel.desc
                }
                Text {
                    id: countStr
                    text: itemModel.count
                }
            }
        }
    }

    Component.onCompleted: {

    }

    Button{
        id: sortBtn
        text: "sort"
        anchors.top: parent.top
        anchors.right: parent.right
        onClicked: {
            //qmlCusSort()
            var list = SortHelper.cusSort(endDataSrc.listData);
            endDataSrc.listData = list;
        }
    }

    function qmlCusSort(){
        var list = endDataSrc.listData;
        for(var i = 0 ; i < list.length -1; i++){
            for(var j = 0; j < list.length -1 - i; j++){
                var first = list[j].count;
                var second = list[j+1].count;
                if(first < second){
                    var temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
                }
            }
        }
        endDataSrc.listData = [];
        endDataSrc.listData = list;
    }
}
