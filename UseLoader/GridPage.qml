import QtQuick 2.6


Item {
    id: root

    property int rowCount: 3

    property int columnCount: 4

    property int spacing: 5

    property alias model: repeaterItem.model

    property Component delegate

    property int animationDurationOnX: 500

    property int currentPage: 0

    property int pageCount: Math.ceil(repeaterItem.count/gridView.itemsPerPage)

    property bool hasNextPage: root.currentPage + 1 < root.pageCount

    property bool hasPreviousPage: root.currentPage

    property alias interactive: gridView.interactive

    Flickable {
        id: gridView

        property int itemsPerPage: rowCount * columnCount

        property double itemWidth: (width - (columnCount - 1) * spacing) / columnCount

        property double itemHeight: (height  - (rowCount - 1) * spacing) / rowCount

        property bool resetingModel: false

        property bool rowCountChanging: false

        anchors.fill: parent
        clip: true
        contentWidth: pageCount * (width + spacing)
        contentHeight: height

        Repeater {
            id: repeaterItem

            Loader {
                id: loader

                property int xOffset: Math.floor(index / (gridView.itemsPerPage)) * (root.width + spacing)

                property int currentColumn: index % columnCount

                property int currentRow: Math.floor(index / columnCount) % rowCount

                property var itemModel:  model//typeof modelData !== "undefined" ? modelData : model

                property int itemIndex: index

                x: xOffset + currentColumn * (gridView.itemWidth + (currentColumn === 0 ? 0 : spacing))
                y: currentRow * (gridView.itemHeight + (currentRow === 0 ? 0 : spacing))
                width: gridView.itemWidth
                height: gridView.itemHeight
                sourceComponent: delegate
            }

            onModelChanged: {
                gridView.resetingModel = true;
                currentPage = 0;
                gridView.contentX = 0;
                gridView.resetingModel = false;
            }
        }

        onMovingChanged: {
            if(!gridView.moving) {
                var potentialCurrentPage = Math.round(gridView.contentX / (gridView.width + spacing));
                if (potentialCurrentPage >= pageCount) {
                    currentPage = pageCount - 1;
                } else if (potentialCurrentPage < 0) {
                    currentPage = 0;
                } else {
                    currentPage = potentialCurrentPage;
                }
                gridView.contentX = currentPage * (gridView.width + spacing);
            }
        }

        Behavior on contentX {
            enabled: !gridView.dragging && !gridView.resetingModel && !gridView.rowCountChanging

            NumberAnimation {
                duration: animationDurationOnX
            }
        }
    }

    onRowCountChanged: {
        gridView.rowCountChanging = true;
        currentPage = 0;
        gridView.contentX = currentPage * (gridView.width + spacing);
        gridView.rowCountChanging = false;
    }


    function nextPage() {
        if(hasNextPage) {
            gridView.contentX = gridView.contentX + (gridView.width + spacing);
            currentPage ++;
        }
    }

    function previousPage() {
        if(hasPreviousPage) {
            gridView.contentX = gridView.contentX - (gridView.width + spacing);
            currentPage --;
        }
    }
}
