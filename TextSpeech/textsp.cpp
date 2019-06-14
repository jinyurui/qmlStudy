#include "textsp.h"
#include <QDebug>

TextSp::TextSp(QObject *p)
    :QObject (p)
{
    m_state = UnDfined;

    QStringList engines = QTextToSpeech::availableEngines();
    qDebug() << "engines : " << engines;
    for (auto engine : engines) {

    }

    m_pTextSpeech = new QTextToSpeech(this);
    turnSateType(m_pTextSpeech->state());

    auto locales = m_pTextSpeech->availableLocales();
    qDebug() << "locales : " << locales;
    for (auto locale : locales) {

    }
    m_pTextSpeech->setLocale(QLocale(QLocale::Chinese));


    connect(m_pTextSpeech, &QTextToSpeech::stateChanged, this, [this](QTextToSpeech::State state){
        turnSateType(state);
        emit stateChanged(m_state);
    });
}

QString TextSp::text() const
{
    return m_text;
}

void TextSp::start()
{
    if(m_text.isEmpty()){
        return;
    }
    m_pTextSpeech->say(m_text);
}

void TextSp::stop()
{
    m_pTextSpeech->stop();
}

void TextSp::resume()
{
    m_pTextSpeech->resume();
}

void TextSp::pause()
{
    m_pTextSpeech->pause();
}

int TextSp::volume() const
{
    return m_volume;
}

TextSp::TextSpState TextSp::state() const
{
    return  m_state;
}

void TextSp::setText(QString text)
{
    if (m_text == text)
        return;

    m_text = text;
    emit textChanged(m_text);
}

void TextSp::setVolume(int volume)
{
    if (m_volume == volume)
        return;

    m_volume = volume;
    emit volumeChanged(m_volume);
}

void TextSp::turnSateType(QTextToSpeech::State state)
{
    if(state == QTextToSpeech::BackendError) {
        m_state = Error;
    }

    if(state == QTextToSpeech::Ready) {
        m_state = Ready;
    }

    if(state == QTextToSpeech::Speaking) {
        m_state = Working;
    }

    if(state == QTextToSpeech::Paused) {
        m_state = Paused;
    }
}
