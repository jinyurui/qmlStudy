#ifndef POSLISTEN_H
#define POSLISTEN_H

#include <QObject>
#include <memory>

class PoslistenImpl;
class PosListen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString context READ context WRITE setContext NOTIFY contextChanged)
    Q_PROPERTY(int posValue READ posValue WRITE setPosValue NOTIFY posValueChanged)

public:
    PosListen(QObject *p = nullptr);
    ~PosListen();

    Q_INVOKABLE void createServiec();

    QString context() const;
    int posValue() const;

public slots:
    void setContext(QString context);
    void setPosValue(int posValue);

signals:
    void contextChanged(QString text);
    void posValueChanged(int value);

private:
    std::shared_ptr<PoslistenImpl> m_pPosListenImpl;
    QString m_context;
    int m_posValue;
};

#endif // POSLISTEN_H
