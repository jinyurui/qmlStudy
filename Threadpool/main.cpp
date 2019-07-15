#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "test.h"
#include <QDebug>
#include "funvoid.h"
#include <QList>


struct StruTest{
    bool operator()(int a) const{
        return a < 10;
    }
};
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

    auto renType = FunVoid::ResultType(&StruTest::operator());
    qDebug() << typeid(renType).name();

    return app.exec();
}
