#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QJsonArray>

class PersonModel:public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QJsonArray personJsonArray READ personJsonArray WRITE setPersonJsonArray NOTIFY personJsonArrayChanged)

public:
    PersonModel(QObject *parent = nullptr);
    enum userole{
        name = Qt::UserRole,
        place ,
        number,
        rich,
    };
    Q_ENUM(userole)

public:
    // Inherited form QAbstractListModel
    Q_INVOKABLE int        rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant               data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    QJsonArray personJsonArray() const;


public slots:
    void setPersonJsonArray(QJsonArray personJsonArray);

signals:
    void personJsonArrayChanged(QJsonArray personJsonArray);

private:
    QJsonArray m_personJsonArray;
};

#endif // PERSONMODEL_H
