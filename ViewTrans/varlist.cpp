#include "varlist.h"
#include <QDebug>

Varlist::Varlist()
{

}

void Varlist::setVarList(QVariantList list)
{
    qDebug() <<list;
}
