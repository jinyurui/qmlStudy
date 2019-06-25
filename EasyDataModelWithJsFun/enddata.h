#ifndef ENDDATA_H
#define ENDDATA_H

#include <QObject>
#include <QVariantList>
#include "easyitem.h"

class EndData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList listData READ listData WRITE setlistData NOTIFY listDataChanged)

private:
    QVariantList m_listData;

public:
    explicit EndData(QObject *parent = nullptr);
    QVariantList listData() const;

signals:
    void listDataChanged(QVariantList listData);

public slots:
    void setlistData(QVariantList listData);
};

#endif // ENDDATA_H
