#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QResource>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

#define xstr(s) str(s)
#define str(s) #s

    // rcc -binary .\org.qrc -o org.rcc
    QString rccPath = QStringLiteral(xstr(CUS_RCC_PATH)) + "/org.rcc";
    qDebug() << rccPath;
    QResource::registerResource(rccPath);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
