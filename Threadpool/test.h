#ifndef TEST_H
#define TEST_H
#include "threadpool.h"
#include <memory>

class Test
{
public:
    Test();

    void postTask();
    // this will be remove other thread
    QString taskFun(int a);

private:
    std::shared_ptr<ThreadPool> pool;
};

#endif // TEST_H
