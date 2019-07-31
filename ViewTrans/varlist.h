#ifndef VARLIST_H
#define VARLIST_H

#include <QVariantList>
#include <QObject>

class Varlist:public QObject
{
    Q_OBJECT
public:
    Varlist();

    Q_INVOKABLE void setVarList(QVariantList list);
};

#endif // VARLIST_H
