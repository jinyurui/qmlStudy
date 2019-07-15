#include "test.h"
#include <QDebug>
#include <QThread>

Test::Test()
{
    pool = std::make_shared<ThreadPool>(5);
}

void Test::postTask()
{
    qDebug() << __FUNCTION__ << QThread::currentThreadId();
    pool->postTask([this](){taskFun(10);});
}

void Test::taskFun(int a)
{
    qDebug() << __FUNCTION__ << QThread::currentThreadId() << a;
}
