#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "test.h"
#include "funvoid.h"

class TestC{
public:
    TestC(){}
    TestC(TestC const &other) = delete ;
};


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    Test one;
    one.postTask();

    return app.exec();
}
