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

float GFrameBufferObject::posZ() const
{
    return m_posZ;
}

bool GFrameBufferObject::turn() const
{
    return m_turn;
}

void GFrameBufferObject::setPosZ(float posZ)
{
    m_posZ = posZ;
    emit posZChanged(m_posZ);
    update();
}

void GFrameBufferObject::setTurn(bool turn)
{
    if (m_turn == turn)
        return;

    m_turn = turn;
    emit turnChanged(m_turn);
    update();
}
