#ifndef PERSONDATAMAP_H
#define PERSONDATAMAP_H

#include <QObject>
#include <QVariantMap>
#include <QJsonObject>

// qRegisterMetaType
//Any class or struct that has
//a public default constructor,
//a public copy constructor,
//a public destructor can be registered.

class PersonDataMap : public QObject
{
    Q_OBJECT

public:
    PersonDataMap(QObject *parent = nullptr);
    PersonDataMap(PersonDataMap const &other);
    ~PersonDataMap();

    void setMapData(QVariantMap map);
    // need qmlRegisterType
    Q_INVOKABLE QVariant getValue(QString const &key) const;

private:
    QVariantMap m_data;
};
// var
//Q_DECLARE_METATYPE(PersonDataMap)
//Q_DECLARE_OPAQUE_POINTER(PersonDataMap*)
#endif // PERSONDATAMAP_H
