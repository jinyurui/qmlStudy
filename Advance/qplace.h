#ifndef QPLACE_H
#define QPLACE_H

#include <QMetaType>
#include <memory>
#include <QString>
/** node
* @key    Q_GADGETs can have
*               Q_ENUM,
*               Q_PROPERTY
*               Q_INVOKABLE,
*               but they cannot have signals or slots
*               , so you shuold use READ ..in Q_PROPERTY
* @desc   this is easy object,you need
*/

class PlaceImp;

class QPlace
{
    Q_GADGET
    Q_PROPERTY(int id READ id )
    Q_PROPERTY(QString name READ name)
public:
    QPlace();
    int id() const;
    QString name() const;

    enum AddressType{
        Home,
        Work,
        Foot,
        Fun,
    };
    Q_ENUM(AddressType)

/** errinfo
* @key   err use sig and slot , you should use Q_OBJECT
* @desc
*/
/*
public slots:
    void setId(int id);
    void setName(QString name);

signals:
    void idChanged(int id);
    void nameChanged(QString name);
*/
public:
    Q_INVOKABLE void showPlaceInfo();

private:
    std::shared_ptr<PlaceImp> m_data;
};
// META_SYS
Q_DECLARE_METATYPE(QPlace)

#endif // QPLACE_H
