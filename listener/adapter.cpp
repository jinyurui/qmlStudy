#include "adapter.h"

static int g_index = 0;

Adapter::Adapter()
{
    m_pTime.reset(new QTimer(nullptr));
    QObject::connect(m_pTime.get(), &QTimer::timeout, [this](){
        m_contextCallback(QString::number(g_index));
        m_posCallback(g_index++);
    });
}

void Adapter::start()
{
    // 模拟回调
    m_pTime->start(2000);
}

void Adapter::stop()
{
    m_pTime->stop();
}

void Adapter::setCallbackForContext(ContextCallback callback)
{
    m_contextCallback = callback;
}

void Adapter::setCallbackForPos(PosCallback callback)
{
    m_posCallback = callback;
}
