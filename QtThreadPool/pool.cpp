#include "pool.h"
#include <QtConcurrent>
#include <QObject>

Pool::Pool()
{
    pool = std::make_shared<QThreadPool>();
    pool->setMaxThreadCount(5);

    // vector resize diff reserve
    loops = std::make_shared<std::vector<std::shared_ptr<QEventLoop>>>();
    loops->resize(5);

    workers = std::make_shared<std::vector<std::shared_ptr<Worker>>>();
    workers->reserve(5);

    int i = 0;
    for(i = 0; i < 5; i++){
        auto fun = [&](int index){
            qDebug() << "current index : " << index << "thred id : " << QThread::currentThreadId();
            std::shared_ptr<QEventLoop> loop = std::make_shared<QEventLoop>();
            std::shared_ptr<Worker> work = std::make_shared<Worker>();
            workers->push_back(work);
            loops->push_back(loop);
            loop->exec();
        };

        QtConcurrent::run(pool.get(), fun, i);
    }
}

Pool::~Pool()
{
    for(auto &one : *loops){
        QMetaObject::invokeMethod( one.get(), "quit" );
    }
    pool->waitForDone();
}

void Pool::postTask(const std::function<void()> &f)
{
    // diao du na ge woker
    workers->at(0)->startWork(f);
}
