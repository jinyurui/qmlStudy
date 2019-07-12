#include "servicemanager.h"
#include "servicemanagerimpl.h"
#include <QDebug>

ServiceManager::ServiceManager()
{
    qDebug() << __FUNCTION__;
    m_impl.reset(new ServiceManagerImpl);
}

ServiceManager::~ServiceManager()
{

}

void ServiceManager::registerListener(std::weak_ptr<Listener> listener)
{
    qDebug() << __FUNCTION__;
    m_impl->registerListener(listener);
}

void ServiceManager::degisterListener(std::weak_ptr<Listener> listener)
{
    m_impl->degisterListener(listener);
}

void ServiceManager::startService()
{
    m_impl->start();
}

void ServiceManager::stopService()
{
    m_impl->stop();
}
