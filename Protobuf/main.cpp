#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "./proto_out/addressbook.pb.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    Person person = Person();
    qDebug() << "INFO:  " << person.id() <<
    QString::fromStdString(person.name()) <<
    QString::fromStdString(person.email());

    return app.exec();
}
