#ifndef TESTINTERFACE_H
#define TESTINTERFACE_H

#include <QtPlugin>

class TestInterface
{
public:
    virtual ~TestInterface(){}
    virtual void testHelpFun() = 0;
};
Q_DECLARE_INTERFACE(TestInterface, "my.testinterface")

#endif // TESTINTERFACE_H
