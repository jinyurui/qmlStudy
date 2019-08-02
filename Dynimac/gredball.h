#ifndef GREDBALL_H
#define GREDBALL_H

#include <QQuickItem>
#include <QSGNode>
#include <QSGSimpleRectNode>

class GRedball: public QQuickItem
{
public:
    GRedball(QQuickItem *parent = nullptr);
    ~GRedball();

    QSGNode *updatePaintNode(QSGNode *node, UpdatePaintNodeData *);
};

#endif // GREDBALL_H
