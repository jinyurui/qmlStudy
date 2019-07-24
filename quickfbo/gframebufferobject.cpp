#include "gframebufferobject.h"
#include "grender.h"
#include <QDebug>

GFrameBufferObject::GFrameBufferObject()
{

}

QQuickFramebufferObject::Renderer *GFrameBufferObject::createRenderer() const
{
    return new GRender();
}

void GFrameBufferObject::test()
{
    qDebug() << "hello render";

}


