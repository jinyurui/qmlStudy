#include "viewmanager.h"
#include <QDebug>
#include <QQmlContext>
//#include <private/qquickitem_p.h>

ViewManager::ViewManager(QQuickItem *p)
{

}

bool ViewManager::addCom(QQmlComponent *com, QObject *obj)
{
    if(!com){
        qDebug() << "com is error";
        return  false;
    }

    QQuickItem *item = nullptr;

    if(!obj){
        QQmlContext *comConText = com->creationContext();
        if(!comConText){
            qDebug() << "com's context no creat";
            comConText = qmlContext(this);
            qDebug() << "use parent comContext";
        }
        item = qobject_cast<QQuickItem*>(com->create(comConText));
        qDebug() << "com create obj in c++";
    }else{
        item = qobject_cast<QQuickItem*>(obj);
        if(!item){
            qDebug() << "errr, obj is not item from qml";
        }
        else{
            qDebug() << "com create obj in qml, this is item";
        }
    }

    if(!item)
    {
        qDebug() << "errr is very much";
        return  false;
    }

    //
    //if (!QQuickItemPrivate::get(item)->widthValid)
    //{
    //    item->setWidth(10);
    //}
    //if (!QQuickItemPrivate::get(item)->heightValid)
    //{
    //    item->setHeight(10);
    //}
    // key
    item->setParentItem(this);
    m_vecViews.push_back(item);
    emit CountChanged(m_vecViews.count());
    return true;

}

int ViewManager::Count() const
{
    return m_vecViews.count();
}
