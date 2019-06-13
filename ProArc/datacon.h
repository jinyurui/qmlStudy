#ifndef DATACON_H
#define DATACON_H

#include <QObject>
#include <memory>
#include <QVariantList>

/** node
* @key  dataPublic pointer , use qml
* @desc
*/

class DataImp;
class DataCon : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList dataList READ dataList NOTIFY dataListChanged)

public:
    explicit DataCon(QObject *parent = nullptr);
    ~DataCon();

    QVariantList dataList() const;

signals:
    void dataListChanged();

private:
    std::unique_ptr<DataImp> Q_Dd;
};

#endif // DATACON_H
