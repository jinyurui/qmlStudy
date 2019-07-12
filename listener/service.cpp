#include "service.h"
#include "listener.h"
#include <QDebug>

Service::Service()
{
    qDebug() << __FUNCTION__;

    m_adapter = nullptr;
}

Service::~Service()
{

}

void Service::setAdapter(std::unique_ptr<Adapter> adapter)
{
    if(m_adapter){
        m_adapter->stop();
    }
    m_adapter = std::move(adapter);
    m_adapter->setCallbackForContext(
                std::bind(&Service::notifyContextUpdate, this, std::placeholders::_1));
    m_adapter->setCallbackForPos(
                std::bind(&Service::notifyPosValueUpdate, this, std::placeholders::_1));
    m_adapter->start();
}

void Service::notifyContextUpdate(QString text)
{
    std::lock_guard<std::mutex> lk(m_listenersMutex);

    for(auto &listener : m_listeners){
        auto lockedListener = listener.lock();
        if(lockedListener){
            lockedListener->onContextChanged(text);
        }
    }
}

void Service::notifyPosValueUpdate(int value)
{
    std::lock_guard<std::mutex> lk(m_listenersMutex);

    for(auto &listener : m_listeners){
        auto lockedListener = listener.lock();
        if(lockedListener){
            lockedListener->onPosValueChanged(value);
        }
    }
}

void Service::addListener(std::weak_ptr<Listener> listener)
{
    qDebug() << __FUNCTION__;

    m_listeners.emplace_back(listener); //  diff bush_pack , is no construct
}

void Service::removeListener(std::weak_ptr<Listener> listener)
{
    auto sp = listener.lock();
    auto it = std::find_if(m_listeners.begin(), m_listeners.end(),
                           [sp](std::weak_ptr<Listener> item){
            auto spItem = item.lock();
            if(spItem){
            return sp == spItem;
            }
            return false;
        });

    if(it!= m_listeners.end()){
        m_listeners.erase(it);
    }
}


