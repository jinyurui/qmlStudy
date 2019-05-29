#include "personmodel.h"
#include <QJsonObject>
#include "persondatamap.h"

PersonModel::PersonModel(QObject *parent)
    :QAbstractListModel (parent)
{
    m_personMapData = new PersonDataMap(this);
}

QJsonArray PersonModel::personJsonArray() const
{
    return m_personJsonArray;
}

void PersonModel::setPersonJsonArray(QJsonArray personJsonArray)
{
    if (m_personJsonArray == personJsonArray)
        return;

    m_personJsonArray = personJsonArray;
    emit personJsonArrayChanged(m_personJsonArray);

    QVariantMap data;
    int id = 0;
    for(auto it = personJsonArray.begin(); it != personJsonArray.end(); ++it){
        if(it->isObject()){
            data.insert(QString::number(id++), it->toVariant());// [QString, QVar]
        }
    }
    if(!data.isEmpty()){
        m_personMapData->setMapData(data);
    }
}

PersonDataMap* PersonModel::personMapData() const
{
    return m_personMapData;
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_personJsonArray.size();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if(index.row() > m_personJsonArray.size() || index.row() < 0){
        return  QVariant();
    }
    QJsonValue item = m_personJsonArray.at(index.row());
    if(item.isObject()){
        QJsonObject object = item.toObject();
        switch (role) {
        case name:
            return object.value("name");
        case place:
            return object.value("place");
        case number:
            return object.value("number");
        case rich:
            return object.value("rich");
        default:
            return QVariant();
        }
    }
    return  QVariant();
}

QHash<int, QByteArray> PersonModel::roleNames() const
{
    return  QHash<int, QByteArray>() = {
    {name, "name"},
    {place, "place"},
    {number, "number"},
    {rich, "rich"},
};
}
