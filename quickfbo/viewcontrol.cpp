#include "viewcontrol.h"
#include <QScreen>
#include <QQuickWindow>
#include <QQuickItem>
#include <QDebug>

ViewControl::ViewControl(GFrameBufferObject *const fbo, QObject *parent)
    :QObject (parent)
{
    quickFbo = fbo;
    qDebug() << "topWin ptr" << quickFbo->topWin();

//    connect(quickFbo, &QQuickItem::windowChanged, this, [this](QQuickWindow* window){
//        qDebug() << "window changed, ptr::" << window;

//        connect(window, &QQuickWindow::screenChanged, this, [this](QScreen *screen){
//            qDebug() << "window screen changed";
//        });
//        connect(window, &QQuickWindow::heightChanged, this, [this](int height){
//            qDebug() << "window height changed :: " << height;
//        });
//        connect(window, &QQuickWindow::widthChanged, this, [this](int width){
//            qDebug() << "window width changed :: " << width;
//        });
//    });
}

