#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "poslisten.h"

void registerData(const char *url){
    qmlRegisterType<PosListen>(url, 1, 0, "PosListen");
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const char *url = "Water";
    registerData(url);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
