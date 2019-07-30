#ifndef POOL_H
#define POOL_H

#include <QThreadPool>
#include <QEventLoop>
#include <memory>
#include <vector>
#include "worker.h"
#include <deque>

class Pool
{
public:
    Pool();
    ~Pool();

    void postTask(const std::function<void()> &f);

private:
    std::shared_ptr<QThreadPool> pool;
    std::shared_ptr<std::vector<std::shared_ptr<QEventLoop>>> loops;
    std::shared_ptr<std::vector<std::shared_ptr<Worker>>> workers;
    std::deque<std::function<void()>> tasks;

};

#endif // POOL_H
