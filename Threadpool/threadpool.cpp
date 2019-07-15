#include "threadpool.h"
#include <QDebug>
#include <QThread>

ThreadPool::ThreadPool(int count)
{
    qDebug() << "threadpool create" << QThread::currentThreadId();
    m_stop = false;
    for(int i = 0; i < count; i++){
        m_workerThread.emplace_back(
                    std::thread(std::bind(&ThreadPool::runWorkThread, this, i)));
    }
}

void ThreadPool::runWorkThread(int index)
{
    while (!m_stop) {
        std::unique_lock<std::mutex> uniqueLock(m_mutex);
        m_condition.wait(uniqueLock, [this]() { return !m_taskDeque.empty() || m_stop; });
        if (!m_stop)
        {
            auto task = std::move(m_taskDeque.front());
            m_taskDeque.pop_front();
            uniqueLock.unlock();
            task();
        }
        qDebug() << "runing workThread -- " << index << QThread::currentThreadId();

    }
}

ThreadPool::~ThreadPool()
{
    initiateStop();
    join();
}

void ThreadPool::initiateStop()
{
    std::lock_guard<std::mutex> guard(m_mutex);
    m_stop = true;
    m_condition.notify_all();
}

void ThreadPool::join()
{
    for (auto& thread : m_workerThread)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }
}


