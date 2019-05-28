#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QJsonArray>

class PersonModel:public QAbstractListModel
{
    Q_OBJECT
public:
    PersonModel(QObject *parent = nullptr);
    enum userole{
        name = Qt::DisplayRole,
        place = Qt::UserRole,
        number,
        rich,
    };
    Q_ENUM(userole)

    Q_INVOKABLE void setJsonArray(QJsonArray const & other);

public:
    // Inherited form QAbstractListModel
    Q_INVOKABLE int        rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant               data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QJsonArray m_jsonArray;
};

#endif // PERSONMODEL_H
