#ifndef GFRAMEBUFFEROBJECT_H
#define GFRAMEBUFFEROBJECT_H

#include <QQuickFramebufferObject>

class GFrameBufferObject : public QQuickFramebufferObject
{
    Q_OBJECT

    Q_PROPERTY(float posZ READ posZ WRITE setPosZ NOTIFY posZChanged)
    Q_PROPERTY(bool turn READ turn WRITE setTurn NOTIFY turnChanged)

public:
    GFrameBufferObject();

    Renderer *createRenderer() const override;

    Q_INVOKABLE void test();

    float posZ() const;
    bool turn() const;

public slots:
    void setPosZ(float posZ);
    void setTurn(bool turn);

signals:
    void posZChanged(float posZ);

    void turnChanged(bool turn);

private:
    float m_posZ = 0.0f;
    bool m_turn = true;
};

#endif // GFRAMEBUFFEROBJECT_H
