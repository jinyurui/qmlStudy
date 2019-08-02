#include "gredball.h"
#include <QDebug>

GRedball::GRedball(QQuickItem *parent)
    :QQuickItem (parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
    qDebug() << "create";
}

GRedball::~GRedball()
{
    qDebug() << "del";
}

QSGNode *GRedball::updatePaintNode(QSGNode *node, QQuickItem::UpdatePaintNodeData *)
{
    qDebug() << "render";
    QSGSimpleRectNode *n = static_cast<QSGSimpleRectNode *>(node);
    if (!n) {
        n = new QSGSimpleRectNode();
        n->setColor(Qt::red);
    }
    n->setRect(boundingRect());
    return n;
}
