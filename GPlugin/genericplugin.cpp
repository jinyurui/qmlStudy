#include "genericplugin.h"
#include <qqml.h>
#include "testitem.h"

GenericPlugin::GenericPlugin(QObject *parent) :
    QQmlExtensionPlugin(parent)
{
}

void GenericPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<TestItem>(uri, 1, 0, "TestItem");
}


