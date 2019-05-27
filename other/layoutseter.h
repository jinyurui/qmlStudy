#ifndef LAYOUTSETER_H
#define LAYOUTSETER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDir>
class QQuickItem;
class LayoutSeter:public QObject
{
    Q_OBJECT
public:
    LayoutSeter(QQuickItem *destItem, QObject *parent = nullptr);
    ~LayoutSeter();
    void setLayout(QString const &layoutID);

private:
    void setProterty(QJsonObject const &object);
    QQuickItem *getChildItem(QString const &name);

private:
    static QString  const layoutDir;
    static QStringList const useKeys;
    QQuickItem *item;

};

#endif // LAYOUTSETER_H
