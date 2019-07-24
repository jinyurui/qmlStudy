#include "grender.h"
#include <QOpenGLFramebufferObjectFormat>

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
