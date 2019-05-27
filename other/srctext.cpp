#include "srctext.h"


SrcText::SrcText(QQuickItem *parent)
    :QQuickItem (parent)
{
    m_pTimer = new QTimer(this);
    connect(m_pTimer, &QTimer::timeout, this, [this](){
        static int i = 0;
        this->setName(QString::number(i++));
    });
    m_pTimer->start(2000);
}

SrcText::~SrcText()
{

}

QString SrcText::name() const
{
    return m_name;
}

void SrcText::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(m_name);
}
