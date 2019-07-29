#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "datalistener.h"
#include "service.h"
#include "registry.h"

class GMainInfo{
public:
    GMainInfo() = default;
    ~GMainInfo() = default;
    void testHelp(){qDebug() << "get and use ok";}
};


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    std::unique_ptr<Registry<std::shared_ptr>> dataContainer(new Registry<std::shared_ptr>());
    std::shared_ptr<GMainInfo> spMainInfo = std::make_shared<GMainInfo>();
    bool ret = dataContainer->registerInstance(spMainInfo);
    qDebug() << "add ret :: " << ret;
    auto mainInfo = dataContainer->getInstance<GMainInfo>();
    mainInfo->testHelp();
    std::shared_ptr<DataLister> listen = std::make_shared<DataLister>();
    listen->registerForUpdate();
    SignleServiceManager::getDataService().dataChange(100);




    return app.exec();
}
