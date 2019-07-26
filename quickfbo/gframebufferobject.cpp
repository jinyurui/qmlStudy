#include "gframebufferobject.h"
#include "grender.h"
#include "viewcontrol.h"
#include <QDebug>
#include <QQuickWindow>
#include <QScreen>

GFrameBufferObject::GFrameBufferObject()
{
    connect(this, &QQuickItem::windowChanged, this, [this](QQuickWindow* window){
        qDebug() << "window changed, ptr::" << window;
        m_selWin = window;
    });

//    connect(m_selWin, &QQuickWindow::screenChanged, this, [this](QScreen *screen){
//        qDebug() << "window screen changed";
//    });
//    connect(m_selWin, &QQuickWindow::heightChanged, this, [this](int height){
//        qDebug() << "window height changed :: " << height;
//    });
//    connect(m_selWin, &QQuickWindow::widthChanged, this, [this](int width){
//        qDebug() << "window width changed :: " << width;
//    });

    connect(this, &QQuickItem::widthChanged, this, [this](){
        update();
    });

    connect(this, &QQuickItem::heightChanged, this, [this](){
        update();
    });

}

QQuickFramebufferObject::Renderer *GFrameBufferObject::createRenderer() const
{
    return new GRender();
}

void GFrameBufferObject::createViewControl()
{
    viewControl = std::make_shared<ViewControl>(this);
}

float GFrameBufferObject::posZ() const
{
    return m_posZ;
}

bool GFrameBufferObject::turn() const
{
    return m_turn;
}

QQuickWindow *GFrameBufferObject::topWin() const
{
    return m_topWin;
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

void GFrameBufferObject::setTopWin(QQuickWindow *win)
{
    m_topWin = win;
}
