#include "backenddata.h"
#include <person.h>

BackEndData::BackEndData(QObject *parent)
    :QObject (parent)
{
    for(int i = 0; i < 10; i++){
        m_data.append(QVariant::fromValue(Person("hello", i%4)));
    }
}

QVariantList BackEndData::data() const
{
    return m_data;
}

void BackEndData::setData(QVariantList data)
{
    if (m_data == data)
        return;

    m_data = data;
    emit dataChanged(m_data);
}
