#ifndef GENERICPLUGIN_H
#define GENERICPLUGIN_H

#include <QQmlExtensionPlugin>
#include <QObject>

//  how to plug modul ?????
class GenericPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    GenericPlugin(QObject *parent = nullptr);
    void registerTypes(const char *uri);

};

#endif // GENERICPLUGIN_H
