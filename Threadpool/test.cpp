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
    auto ret = pool->postTask([this](){return taskFun(10);});
    qDebug() << "postRet" << ret.result.get();
}

QString Test::taskFun(int a)
{
    qDebug() << __FUNCTION__ << QThread::currentThreadId();
    return  "this is ok";
}
