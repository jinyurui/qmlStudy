#include "datacontrolimp.h"
#include "qplace.h"
#include <QDebug>

DataControlImp::DataControlImp(QObject *p)
    :QObject (p)
{
    m_pQPlace = std::make_shared<QPlace>();
}

void DataControlImp::controlObject(DataControl::DataType type)
{
    switch (type) {
    case DataControl::QPlace:{
        m_pQPlace->showPlaceInfo();
        qDebug() << "place proterty get info : "<<m_pQPlace->id() << m_pQPlace->name();
        break;
    }
    default:{
        break;
    }
    }
}
