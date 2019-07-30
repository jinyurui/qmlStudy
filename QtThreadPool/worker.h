#ifndef WORKER_H
#define WORKER_H

#include <functional>
#include <QObject>
#include <memory>
#include <QMutex>
#include <QMutexLocker>

class Worker: public QObject
{
    Q_OBJECT
public:
    Worker(QObject* parent = nullptr);

    void startWork(const std::function<void()> &f);

public slots:
    void runing();

private:
    std::function<void()> varfun = nullptr;
    QMutex mutex;
};

#endif // WORKER_H
