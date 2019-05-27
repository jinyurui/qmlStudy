#ifndef SRCTEXT_H
#define SRCTEXT_H

#include <QObject>
#include <QQuickItem>
#include <QTimer>

class SrcText:public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    SrcText(QQuickItem *parent = nullptr);
    ~SrcText();

    QString name() const;

public slots:
    void setName(QString name);

signals:
    void nameChanged(QString name);

private:
    QString m_name;
    QTimer *m_pTimer;
};

#endif // SRCTEXT_H
