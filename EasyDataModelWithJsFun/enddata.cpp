#include "enddata.h"

EndData::EndData(QObject *parent) : QObject(parent)
{
    m_listData.clear();
    //
    QVariantList temp;
    for(int i = 0; i < 10; i++){
        temp.append(QVariant::fromValue(EasyItem(QString::number(i), i%3)));
    }
    setlistData(temp);
}

void EndData::setlistData(QVariantList listData)
{
    if (m_listData == listData)
        return;

    m_listData = listData;
    emit listDataChanged(m_listData);
}

QVariantList EndData::listData() const
{
    return m_listData;
}
