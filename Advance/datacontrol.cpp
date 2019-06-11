#include "datacontrol.h"
#include "datacontrolimp.h"
#include <QDebug>

DataControl::DataControl(QObject *parent) : QObject(parent)
{
    m_pDataControlImp = new DataControlImp(this);
}

DataControl::~DataControl()
{

}

QString DataControl::desc() const
{
    return m_desc;
}

void DataControl::controlObject(DataControl::DataType type)
{
    m_pDataControlImp->controlObject(type);
}

void DataControl::setDesc(QString desc)
{
    if (m_desc == desc)
        return;

    m_desc = desc;
    emit descChanged(m_desc);
}
