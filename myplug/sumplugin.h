#ifndef SUMPLUGIN_H
#define SUMPLUGIN_H

#include <QObject>
#include "testinterface.h"

class SumPlugin: public QObject,
                 public TestInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "my.plugin" )
    Q_INTERFACES(TestInterface)

public:
    virtual void testHelpFun() override;

};

#endif // SUMPLUGIN_H
