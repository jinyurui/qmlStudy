#include "persondatamap.h"

PersonDataMap::PersonDataMap(QObject *parent)
    : QObject(parent)
{

}

PersonDataMap::PersonDataMap(const PersonDataMap &other)
{
    this->m_data = other.m_data;
}

PersonDataMap::~PersonDataMap()
{

}

void PersonDataMap::setMapData(QVariantMap map)
{
    m_data = map;

}

QVariant PersonDataMap::getValue(const QString &key) const
{
    return m_data.value(key);
}


