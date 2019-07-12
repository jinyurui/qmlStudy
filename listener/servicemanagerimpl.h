#ifndef SERVICEMANAGERIMPL_H
#define SERVICEMANAGERIMPL_H
#include "service.h"
#include "adapter.h"
#include <memory>

class ServiceManagerImpl
{
public:
    ServiceManagerImpl();

    void start();
    void stop();

    void registerListener(std::weak_ptr<Listener> listener);
    void degisterListener(std::weak_ptr<Listener> listener);

private:
    std::shared_ptr<Service> m_pService;
};

#endif // SERVICEMANAGERIMPL_H
