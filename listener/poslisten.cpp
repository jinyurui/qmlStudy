#include "poslisten.h"
#include "poslistenimpl.h"

PosListen::PosListen(QObject *p)
    :QObject (p),
     m_pPosListenImpl(std::make_shared<PoslistenImpl>(this))
{
    m_context = "";
    m_posValue = -1;
}

PosListen::~PosListen()
{

}

void PosListen::createServiec()
{
    m_pPosListenImpl->createService();
}

QString PosListen::context() const
{
    return m_context;
}

int PosListen::posValue() const
{
    return m_posValue;
}

void PosListen::setContext(QString context)
{
    if (m_context == context)
        return;

    m_context = context;
    emit contextChanged(m_context);
}

void PosListen::setPosValue(int posValue)
{
    if (m_posValue == posValue)
        return;

    m_posValue = posValue;
    emit posValueChanged(m_posValue);
}
