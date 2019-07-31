#ifndef BACKENDDATA_H
#define BACKENDDATA_H

#include <QObject>
#include <QVariantList>

class BackEndData:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList data READ data WRITE setData NOTIFY dataChanged)

public:
    BackEndData(QObject *parent = nullptr);

    QVariantList data() const;

public slots:
    void setData(QVariantList data);

signals:
    void dataChanged(QVariantList data);

private:
    QVariantList m_data;

};

#endif // BACKENDDATA_H
