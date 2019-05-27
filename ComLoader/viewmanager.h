#ifndef VIEWMANAGER_H
#define VIEWMANAGER_H

#include <QObject>
#include <QQuickItem>
class QQmlComponent;
class ViewManager:public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(int count READ Count NOTIFY CountChanged)

public:
    ViewManager(QQuickItem *p = nullptr);

    Q_INVOKABLE bool addCom(QQmlComponent *com, QObject *obj = nullptr);
    int Count() const;

signals:
    void CountChanged(int count);

private:
    QVector<QQuickItem *> m_vecViews;
    int m_count;
};

#endif // VIEWMANAGER_H
