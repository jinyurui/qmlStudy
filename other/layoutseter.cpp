#include "layoutseter.h"
#include <QDebug>
#include <QQuickItem>

QString const LayoutSeter::layoutDir = "D:/QtProject/qmlStudy/other/";
QStringList const LayoutSeter::useKeys =
        QStringList() << "anchors.topMargin" // item->setProterty>> false not ok
                      <<"anchors.leftMargin"
                      <<"anchors.rightMargin"
                      <<"anchors.bottomMargin"
                      <<"width"
                      <<"height";
LayoutSeter::LayoutSeter(QQuickItem *destItem, QObject *parent)
    :QObject (parent),item(destItem)
{
}

LayoutSeter::~LayoutSeter()
{

}

void LayoutSeter::setLayout(const QString &layoutID)
{
    if(layoutID.isEmpty()){
        qDebug() << "id is null";
        return;
    }
    // if use qrc file, you should build pro when change file; so i use absPath
    QFile file(layoutDir + layoutID + ".json");
    if(!file.exists()){
        qDebug() << "file don't exit";
        return;
    }
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "file can not open";
        return ;
    }
    QByteArray byteArray = file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(byteArray, &jsonError);  // 转化为 JSON 文档
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (doucment.isObject()) { // JSON 文档为对象
            QJsonObject object = doucment.object();  // 转化为对象
            qDebug() << object;
            setProterty(object);
        }
    }else{
        qDebug() << jsonError.errorString();
    }

}

void LayoutSeter::setProterty(const QJsonObject &object)
{
    QStringList keys = object.keys();
    qDebug() << keys;
    for(QString key : keys){
        if(useKeys.contains(key)){
            qDebug() << "root set:: " << item->setProperty(key.toLocal8Bit().data(),object.value(key).toVariant().toInt());
        }
    }

    if(object.contains("children")){
        QJsonValue value = object.value("children");
        if(value.isObject()){
            QJsonObject parentItem = value.toObject();
            QStringList childrenNames = parentItem.keys();
            for(QString name : childrenNames){
                QQuickItem *child = getChildItem(name);
                if(child){
                    QJsonValue childContext = parentItem.value(name);
                    if(childContext.isObject()){
                        QJsonObject childObj = childContext.toObject();
                        QStringList sonkeys = childObj.keys();
                        for(QString key : sonkeys){
                            if(useKeys.contains(key)){
                                qDebug() << "child set for ::" + name <<"::"<< child->setProperty(key.toLocal8Bit().data(),childObj.value(key).toVariant().toInt());
                            }
                        }
                    }
                }
            }
        }

    }
}

QQuickItem *LayoutSeter::getChildItem(const QString &name)
{
    QList<QQuickItem*> childrenItems = item->childItems();
    for(QQuickItem *&one: childrenItems){
        if(one->objectName() == name){
            return one;
        }
    }
    return nullptr;
}
