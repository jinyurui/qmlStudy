#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "srctext.h"
#include "itemlayout.h"
#include <QDebug>

// get app environ
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
    // qml SG render
    //qputenv("QSG_VISUALIZE", "overdraw");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qDebug() << APP_VERSION;
    qDebug() << APP_PRODUCT;
    qDebug() << APP_COMPANY;
    qDebug() << APP_COPYRIGHT;
#ifdef SYNC_TARGET_LOCATION_QMLPLUGINS
#define xstr(s) str(s)
#define str(s) #s
    // import other plugin dll dir [dll/debug or release/modle/.dll + .qmdir]
    QString qmlPluginPath = QStringLiteral(xstr(SYNC_TARGET_LOCATION_QMLPLUGINS));
    qDebug() << "dll path" << qmlPluginPath;
    engine.addImportPath(qmlPluginPath);
#endif

    // regiter c++ class for qml
    qmlRegisterType<SrcText>("CPLUS", 1, 0, "SrcText");
    qmlRegisterType<ItemLayout>("CPLUS", 1, 0, "ItemLayout");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
