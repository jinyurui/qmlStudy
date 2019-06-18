#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "datasum.h"
#include <memory>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

/** node
* @key    qml register singnal
* @desc
*/

    qmlRegisterSingletonType<DataSum>("Water", 1, 0 , "GDataSum", [](QQmlEngine *qml, QJSEngine *js)->QObject*{
        Q_UNUSED(qml)
        Q_UNUSED(js)
        return  new DataSum();
    });

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    std::shared_ptr<int> spOrg = std::make_shared<int>(10);
    qDebug() << "orgCount " << spOrg.use_count();

    std::weak_ptr<int> weakPoint = spOrg;
    qDebug() << "orgCount after use weak help " << spOrg.use_count();


    return app.exec();
}
