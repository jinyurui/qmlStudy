#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <thread>
#include <QDebug>
#include <QThread>
#include "pool.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qDebug() << "------------main thread:: " << QThread::currentThreadId();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    auto fun = [](){
        qDebug() << ">>>>>>>>>>>--------------real fun " << QThread::currentThreadId();
    };

    std::shared_ptr<Pool> spPool = std::make_shared<Pool>();
    spPool->postTask(fun);

    return app.exec();
}
