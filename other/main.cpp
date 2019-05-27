#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "srctext.h"
#include "itemlayout.h"

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

    // import other plugin dll dir [dll/modle/.dll + .qmdir]
    engine.addImportPath("D:/QtProject/qmlStudy/other/dll/");

    // regiter c++ class for qml
    qmlRegisterType<SrcText>("CPLUS", 1, 0, "SrcText");
    qmlRegisterType<ItemLayout>("CPLUS", 1, 0, "ItemLayout");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
