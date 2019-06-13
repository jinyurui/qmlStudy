#include "datacon.h"
#include "dataimp.h"

DataCon::DataCon(QObject *parent) : QObject(parent)
{
    Q_Dd = nullptr;
    Q_Dd.reset(new DataImp(this));
}

DataCon::~DataCon()
{

}

QVariantList DataCon::dataList() const
{
    return Q_Dd->dataList();
}
