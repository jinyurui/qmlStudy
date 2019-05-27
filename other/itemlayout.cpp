#include "itemlayout.h"
#include "layoutseter.h"

ItemLayout::ItemLayout(QQuickItem *parent)
    :QQuickItem (parent)
{
    qDebug() << "    create";
    m_playoutSter = new LayoutSeter(this);
    setFlag(QQuickItem::ItemHasContents, true);
}

ItemLayout::~ItemLayout()
{

}

QString ItemLayout::layoutID() const
{
    return m_layoutID;
}

void ItemLayout::classBegin()
{
    qDebug() << "    classBegin";
    QQuickItem::classBegin();
}

void ItemLayout::componentComplete()
{
    qDebug() << "    componentComplete";
    m_playoutSter->setLayout(m_layoutID);
    bCompleted = true;
    QQuickItem::componentComplete();
}

QSGNode *ItemLayout::updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *updatePaintNodeData)
{
    Q_UNUSED(oldNode)
    Q_UNUSED(updatePaintNodeData)
    qDebug() << "    updatePaintNode   ";
    return QQuickItem::updatePaintNode(oldNode, updatePaintNodeData);
}

void ItemLayout::setLayoutID(QString layoutID)
{
    if (m_layoutID == layoutID)
        return;
    m_layoutID = layoutID;
    if(bCompleted){
        m_playoutSter->setLayout(m_layoutID);
        emit layoutIDChanged(m_layoutID);
    }
}
