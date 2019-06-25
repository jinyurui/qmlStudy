#ifndef EASYITEM_H
#define EASYITEM_H

#include <QMetaType>
#include <QString>

class EasyItem
{
    Q_GADGET //but they cannot have signals or slots
    Q_PROPERTY(QString desc READ desc WRITE setDesc)
    Q_PROPERTY(int count READ count WRITE setCount)

public:
    EasyItem(QString str = "", int c = 0);
    QString desc() const;
    int count() const;

    void setDesc(QString desc);
    void setCount(int count);
private:
    QString m_desc;
    int m_count;
};
Q_DECLARE_METATYPE(EasyItem)

#endif // EASYITEM_H
