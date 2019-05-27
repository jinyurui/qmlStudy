#ifndef TESTITEM_H
#define TESTITEM_H

#include <QObject>
#include <QQuickItem>

class TestItem: public QQuickItem
{
    Q_OBJECT
public:
    TestItem(QQuickItem *parent = nullptr);
    ~TestItem();

    Q_INVOKABLE void testHelp();
};

#endif // TESTITEM_H
