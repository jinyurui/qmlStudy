#include "worker.h"
#include <QDebug>
#include <QThread>

Worker::Worker(QObject *parent)
    :QObject (parent)
{
    qDebug() << "create worker" << QThread::currentThreadId();
}

void Worker::startWork(const std::function<void()> &f)
{
    QMutexLocker locker(&mutex);
    qDebug() << "@@@@@@@@@@work thread" << QThread::currentThreadId();
    varfun = f;
    qDebug() << QMetaObject::invokeMethod(this, "runing", Qt::QueuedConnection);
}

void Worker::runing()
{
    QMutexLocker locker(&mutex);
    qDebug() << "$$$$$$$$$$run thread" << QThread::currentThreadId();
    if(varfun){
        varfun();
    };
}
