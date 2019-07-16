#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <memory>
#include <vector>
#include <deque>
#include <functional>
#include <thread>
#include <mutex>
#include "taskpack.h"
#include <QDebug>

template <typename ResultType>
struct ExecutorResult
{
    std::future<ResultType> result;
};

class ThreadPool
{

public:
    ThreadPool(int count);
    ~ThreadPool();
    ThreadPool(const ThreadPool&) = delete;
    ThreadPool(ThreadPool&&)      = delete;

    void initiateStop();
    void join();

    template <typename Fun>
    ExecutorResult<decltype(ResultType(&Fun::operator()))> postTask(Fun f)
    {

        static_assert(std::is_copy_constructible<Fun>::value, "tasks requires copying");
        using ReturnType = decltype(ResultType(&Fun::operator()));
        qDebug() << "you function return type is: ";
        qDebug() << "\t returnType: " << typeid(ReturnType).name();
        std::shared_ptr<PackagedTask<ReturnType()>> packaged_task;

        ExecutorResult<ReturnType> result = post(f, packaged_task);
        {
            std::lock_guard<std::mutex> guard(m_mutex);
            m_taskDeque.emplace_back([packaged_task]() { (*packaged_task)(); });
        }
        m_condition.notify_one();
        return result;
    }

private:
    // 函数返回类型
    template <typename Class, typename R, typename... Args>
    static R ResultType(R (Class::*)(Args...) const)
    {
        return R();
    }

    // 一般函数打包
    template <typename Fun, typename ReturnType>
    ExecutorResult<decltype(ResultType(&Fun::operator()))> post(
        Fun f, std::shared_ptr<PackagedTask<ReturnType()>>& packagedTask)
    {
        // std::packaged_task is not copyable and c++11 does not support lambda capture by move
        packagedTask = std::make_shared<PackagedTask<ReturnType()>>(std::bind(f));

        std::future<ReturnType>    future = packagedTask->getFuture();
        ExecutorResult<ReturnType> result;
        result.result           = std::move(future);
        return result;
    }

private:
    void runWorkThread(int index);

private:
    mutable std::mutex m_mutex;
    std::vector<std::thread> m_workerThread;
    std::deque<std::function<void()>> m_taskDeque;
    bool m_stop;
    std::condition_variable m_condition;

};

#endif // THREADPOOL_H
