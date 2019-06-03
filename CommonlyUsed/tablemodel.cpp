#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    :QAbstractTableModel (parent)
{
    initData();
}

int TableModel::rowCount(const QModelIndex &) const
{
    return m_dataList.length();
}

int TableModel::columnCount(const QModelIndex &) const
{
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0){
        return QVariant();
    }
    if(index.row() > m_dataList.length()){
        return QVariant();
    }
    INFO item = m_dataList.at(index.row());
    switch (role) {
    case desc:
        return item.desc;
    case skill:
        return item.skill;
    case rich:
        return item.rich;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    return QHash<int, QByteArray>{
        {desc,"desc"},
        {skill,"skill"},
        {rich,"rich"},
    };
}

void TableModel::initData()
{
    m_dataList.clear();
    for(int i = 0; i < 10; ++i){
        INFO item = {
            QString::number(i*3),
            QString::number(i*6),i*9
        };

        m_dataList << item;
    }
}
