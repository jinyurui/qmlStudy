#include "servicemanagerimpl.h"
#include <QDebug>

ServiceManagerImpl::ServiceManagerImpl()
{
    qDebug() << __FUNCTION__;

    m_pService = std::make_shared<Service>();
}

void ServiceManagerImpl::start()
{
    auto adapter = std::unique_ptr<Adapter>(new Adapter());
    m_pService->setAdapter(std::move(adapter));
}

void ServiceManagerImpl::stop()
{

}

void ServiceManagerImpl::registerListener(std::weak_ptr<Listener> listener)
{
    qDebug() << __FUNCTION__;

    m_pService->addListener(listener);
}

void ServiceManagerImpl::degisterListener(std::weak_ptr<Listener> listener)
{
    m_pService->removeListener(listener);
}
