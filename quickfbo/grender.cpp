#include "grender.h"
#include <QOpenGLFramebufferObjectFormat>
#include "gframebufferobject.h"

GRender::GRender()
{
    m_pApple = new Apple();
    m_pApple->initData();
}

void GRender::render()
{
    m_pApple->render();
    update();
}

QOpenGLFramebufferObject *GRender::createFramebufferObject(const QSize &size)
{
    QOpenGLFramebufferObjectFormat format;
    format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
    format.setSamples(4);
    return new QOpenGLFramebufferObject(size, format);
}

void GRender::synchronize(QQuickFramebufferObject *fbo)
{
    GFrameBufferObject *fboItem = static_cast<GFrameBufferObject *>(fbo);
    m_pApple->setCameraPosZ(fboItem->posZ());
    m_pApple->setTurn(fboItem->turn());
    m_pApple->setViewWH(fboItem->width(), fboItem->height());
}
