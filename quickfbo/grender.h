#ifndef GRENDER_H
#define GRENDER_H

#include <QQuickFramebufferObject>
#include "apple.h"

class GRender:public QQuickFramebufferObject::Renderer
{
public:
    GRender();

    void render() override;
    QOpenGLFramebufferObject *createFramebufferObject(const QSize &size) override;
    void synchronize(QQuickFramebufferObject *fbo) override;

private:
    Apple *m_pApple;
};

#endif // GRENDER_H
