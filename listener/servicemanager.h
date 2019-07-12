#ifndef SERVICEMANAGER_H
#define SERVICEMANAGER_H

#include <memory>

class Listener;
class ServiceManagerImpl;
class ServiceManager
{
public:
    ServiceManager();
    ~ServiceManager();

    void registerListener(std::weak_ptr<Listener> listener);
    void degisterListener(std::weak_ptr<Listener> listener);

    void startService();
    void stopService();

private:
    std::unique_ptr<ServiceManagerImpl> m_impl;
};

#endif // SERVICEMANAGER_H
