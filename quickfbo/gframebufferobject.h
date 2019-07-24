#ifndef GFRAMEBUFFEROBJECT_H
#define GFRAMEBUFFEROBJECT_H

#include <QQuickFramebufferObject>

class GFrameBufferObject : public QQuickFramebufferObject
{
    Q_OBJECT

public:
    GFrameBufferObject();

    Renderer *createRenderer() const override;

    Q_INVOKABLE void test();

};

#endif // GFRAMEBUFFEROBJECT_H
