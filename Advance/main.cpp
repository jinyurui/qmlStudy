#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "datacontrol.h"

void registerType(const char *url){
    qmlRegisterType<DataControl>(url, 1, 0, "DataControl");
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    const char *url = "Advance";
    registerType(url);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
