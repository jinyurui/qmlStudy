#ifndef DATAFLOW_H
#define DATAFLOW_H

#include <QQuickItem>
#include <QQmlContext>
#include <QQmlComponent>

// [Dynimic qml] qml 创建com 和 对象的过程，
class DataFlow: public QQuickItem
{
    Q_OBJECT
public:
    DataFlow(QQuickItem *parent = nullptr);

    // 解析 由 qml 创建的 com object
    Q_INVOKABLE void dataAnalysis(QQmlComponent *com, QObject *obj);

    // c++ 创建 com object
    Q_INVOKABLE QObject* createItem(QString url);

};

#endif // DATAFLOW_H
