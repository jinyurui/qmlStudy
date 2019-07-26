#ifndef GFRAMEBUFFEROBJECT_H
#define GFRAMEBUFFEROBJECT_H

#include <memory>
#include <QObject>
#include <QQuickFramebufferObject>
class ViewControl;
class QQuickWindow;
class QQuickItem;

class GFrameBufferObject : public QQuickFramebufferObject//, public std::enable_shared_from_this<GFrameBufferObject>
{
    Q_OBJECT

    Q_PROPERTY(float posZ READ posZ WRITE setPosZ NOTIFY posZChanged)
    Q_PROPERTY(bool turn READ turn WRITE setTurn NOTIFY turnChanged)
    Q_PROPERTY(QQuickWindow* topWin READ topWin WRITE setTopWin)

public:
    GFrameBufferObject();

    Renderer *createRenderer() const override;

    Q_INVOKABLE void createViewControl();

    float posZ() const;
    bool turn() const;
    QQuickWindow* topWin() const;

public slots:
    void setPosZ(float posZ);
    void setTurn(bool turn);
    void setTopWin(QQuickWindow *win);

signals:
    void posZChanged(float posZ);
    void turnChanged(bool turn);

private:
    float m_posZ = 0.0f;
    bool m_turn = true;
    std::shared_ptr<ViewControl> viewControl;
    QQuickWindow* m_topWin;
    QQuickWindow* m_selWin;
};

#endif // GFRAMEBUFFEROBJECT_H
