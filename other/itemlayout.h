#ifndef ITEMLAYOUT_H
#define ITEMLAYOUT_H

#include <QObject>
#include <QQuickItem>

class LayoutSeter;
class QSGNode;

class ItemLayout: public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString layoutID READ layoutID WRITE setLayoutID NOTIFY layoutIDChanged)

private:
    QString m_layoutID = "";
    LayoutSeter *m_playoutSter;
    bool bCompleted = false;

public:
    ItemLayout(QQuickItem *parent = nullptr);
    ~ItemLayout();
    QString layoutID() const;

protected:
    virtual void classBegin();
    virtual void componentComplete();


    virtual QSGNode *
    updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData);


public slots:
    void setLayoutID(QString layoutID);

signals:
    void layoutIDChanged(QString layoutID);
};

#endif // ITEMLAYOUT_H
