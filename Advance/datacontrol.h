#ifndef DATACONTROL_H
#define DATACONTROL_H

#include <QObject>

/** node
* @key    this container with other c++ class, is not a view item.
* @desc
*/
class DataControlImp;
class DataControl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString desc READ desc WRITE setDesc NOTIFY descChanged)

public:
    explicit DataControl(QObject *parent = nullptr);
    ~DataControl();

    enum DataType{
        QPlace,
    };
    Q_ENUM(DataType)

    QString desc() const;

    Q_INVOKABLE void controlObject(DataType type);

signals:
    void descChanged(QString desc);

public slots:
    void setDesc(QString desc);

private:
    QString m_desc;

private:
    DataControlImp* m_pDataControlImp;
};

#endif // DATACONTROL_H
