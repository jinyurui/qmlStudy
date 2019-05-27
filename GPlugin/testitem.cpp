#include "testitem.h"
#include <QDebug>

TestItem::TestItem(QQuickItem *parent)
    :QQuickItem (parent)
{

}

TestItem::~TestItem()
{

}

void TestItem::testHelp()
{
    qDebug() << "testHelp";
}
