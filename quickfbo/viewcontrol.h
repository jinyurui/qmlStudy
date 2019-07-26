#ifndef VIEWCONTROL_ex_H
#define VIEWCONTROL_ex_H

#include <QObject>
#include "gframebufferobject.h"

class QScreen;
class QQuickWindow;
class QQuickItem;

class ViewControl :public QObject
{
    Q_OBJECT

public:
    ViewControl(GFrameBufferObject *const fbo, QObject *parent = nullptr);

private:
    GFrameBufferObject *quickFbo;
};

#endif // VIEWCONTROL_H
