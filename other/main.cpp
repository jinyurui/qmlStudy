#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "srctext.h"
#include "itemlayout.h"


extern char **environ;
void logEnviron()
{
    char *s = *environ;

    qInfo() << "Dump envrionment variables:";
    for (int i = 1 ; s; i++)
    {
        printf("%s\n", s);
        qInfo() << s;
        s = *(environ+i);
    }
}

int main(int argc, char *argv[])
{
    //qputenv("QSG_VISUALIZE", "overdraw");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //logEnviron();

    QQmlApplicationEngine engine;

    qmlRegisterType<SrcText>("CPLUS", 1, 0, "SrcText");
    qmlRegisterType<ItemLayout>("CPLUS", 1, 0, "ItemLayout");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
