#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMatrix4x4>
#include <QDebug>
#include <QVector3D>
#include <QQmlContext>
#include <QVariant>
#include <QMatrix3x3>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //qputenv("QSG_VISUALIZE", "overdraw");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    static float vecs[][3] = {
        {-1.0f, 1.0f, 0.0f},
        {-1.0f, -1.0f, 0.0f},
        {1.0f, -1.0f, 0.0f},
        {1.0f, 1.0f, 0.0f},
    };
    Q_UNUSED(vecs)

    // mvp mat
    QMatrix4x4 modelMat;
    modelMat.setToIdentity();
    modelMat.rotate(45, QVector3D(0.0f, 1.0f, 0.0f));
    QMatrix4x4 viewMat;
    viewMat.setToIdentity();
    //viewMat.lookAt(QVector3D(0.0f, 0.0f, 1.0f), QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 1.0f, 0.0f));
    QMatrix4x4 proMat;
    proMat.setToIdentity();
    //proMat.perspective(90.0f, 680/380, 0.0f, 1000.0f);

    QMatrix4x4 mvpMat =  proMat * viewMat * modelMat;
    Q_UNUSED(mvpMat)

    //engine.rootContext()->setContextProperty("mvpMat", mvpMat);
    //engine.rootContext()->setContextProperty("vecs", QVariant::fromValue(vecs));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
