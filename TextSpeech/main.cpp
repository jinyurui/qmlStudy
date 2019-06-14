#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "textsp.h"
#include "filereader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<TextSp>("TextToSpeech", 1, 0, "TextSp");
    qmlRegisterType<FileReader>("TextToSpeech", 1, 0, "FileReader");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
