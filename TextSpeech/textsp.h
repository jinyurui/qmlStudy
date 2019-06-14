#ifndef TEXTSP_H
#define TEXTSP_H

#include <QObject>
#include <QTextToSpeech>
#include <QVector>

class TextSp:public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(TextSpState state READ state NOTIFY stateChanged)

public:
    TextSp(QObject *p = nullptr);

    enum TextSpState{
        Error,
        Ready,
        Working,
        Paused,
        UnDfined
    };
    Q_ENUM(TextSpState)

    QString text() const;
    int volume() const;
    TextSpState state() const;

    Q_INVOKABLE void start();
    Q_INVOKABLE void stop();
    Q_INVOKABLE void resume();
    Q_INVOKABLE void pause();

public slots:
    void setText(QString text);
    void setVolume(int volume);

signals:
    void textChanged(QString text);
    void volumeChanged(int volume);
    void stateChanged(TextSpState state);

private:
    void turnSateType(QTextToSpeech::State state);

private:
    QTextToSpeech *m_pTextSpeech;
    QString m_text;
    int m_volume;
    TextSpState m_state;
};

#endif // TEXTSP_H
