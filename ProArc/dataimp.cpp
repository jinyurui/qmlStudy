#include "dataimp.h"
#include "data.h"
#include <QVariant>
#include <QDebug>

DataImp::DataImp(DataCon *p)
    :Q_Qp(p)
{
    testHelp(0);
}

QVariantList DataImp::dataList() const
{
    return list;
}

void DataImp::testHelp(int callBackListData)
{
    Q_UNUSED(callBackListData)

    list.clear();
    for(int i = 0; i < 3; ++i){
        list.append(QVariant::fromValue(Data(std::make_shared<srcData>())));
    }
}

