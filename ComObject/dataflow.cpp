#include "dataflow.h"
#include <QDebug>

DataFlow::DataFlow(QQuickItem *parent)
    :QQuickItem (parent)
{

}

void DataFlow::dataAnalysis(QQmlComponent *com, QObject *obj)
{
    if(!com){
        qDebug() << "the com not ok";
        return;
    }
    if(!obj){
        qDebug() << "com not create obj";
        return;
    }

    QQmlContext *context = com->creationContext();
    if(context){
        qDebug() << "the com create by qml, and create context for the com";
    }

    QQuickItem *item = qobject_cast<QQuickItem*>(obj);
    if(!item){
        qDebug() << "the com create obj, but not item";
        if(!context){
            qDebug() << "create context for com from c++";
            context = qmlContext(this);
        }
        item = qobject_cast<QQuickItem*>(com->create(context));
    }

    // 对于可视化的 需要设置可视化父级对象 这不同于 QObject::setParent
    // qml 中{id:root{id:node}}, node 的 parentItem 为 root
    item->setParentItem(this);

    item->setX((this->parentItem()->width()-item->width())/2);
    item->setY((this->parentItem()->height()-item->height())/2);
}

QObject *DataFlow::createItem(QString url)
{
    QQmlEngine *engine = qmlEngine(this);
    if(!engine){
        qDebug() << "-----  not get engine  -----";
    }
    QQmlComponent component(engine, QUrl(url));
    if(component.status() == QQmlComponent::Ready){
        QQmlContext *context = component.creationContext();
        if(!context){
            qDebug() << "com not create by qml, no use this";
        }
        context = qmlContext(this);
        // com->create(nullptr); 默认使用root->context();
        // this diff qml; can load proterties, then later
        QQuickItem *childItem = qobject_cast<QQuickItem*>(component.create(context));
        childItem->setParentItem(this);
        childItem->setX(30);
        childItem->setY(30);
        qDebug() << "set property text ret : " << childItem->setProperty("text", "c++");
        return  childItem;
    }else {
        qDebug() << "com state : " << component.status();
        return nullptr;
    }
}
