#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "gredball.h"
#include <memory>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<GRedball>("Water", 1, 0, "GRedball");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    std::shared_ptr<int> sp = std::make_shared<int>(10);
    std::shared_ptr<const int> spEx = std::make_shared<const int>(*sp);
    auto pt = sp.get();
    *pt  = 20;
    auto ptr = spEx.get();
    qDebug() << *pt << *ptr;


    return app.exec();
}
