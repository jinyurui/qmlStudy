#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QAbstractTableModel>

struct INFO
{
    QString desc;
    QString skill;
    int rich;
    INFO(){
        desc = "";
        skill = "";
        rich = 0;
    }
    INFO(QString d,QString s,int r) {
        desc = d;skill =s; rich = r;
    }
};
Q_DECLARE_METATYPE(INFO)

class TableModel:public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TableModel(QObject *parent = nullptr);

    enum dataRole{
        desc = Qt::UserRole,
        skill,
        rich,
    };
    Q_ENUM(dataRole)

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    void initData();

private:
    QList<INFO> m_dataList;
};

#endif // TABLEMODEL_H
