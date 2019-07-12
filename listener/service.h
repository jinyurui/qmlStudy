#ifndef SERVICE_H
#define SERVICE_H

#include <memory>
#include <functional>
#include <QString>
#include "adapter.h"
#include <vector>
#include <mutex>

class Listener;

/* @desc 透传服务*/
class Service
{
public:
    Service();
    ~Service();

    /* @desc 服务通过适配器获取回调信息并转发*/
    void setAdapter(std::unique_ptr<Adapter> adapter);

    /* @desc 提供给适配器的注册函数，转发实体*/
    void notifyContextUpdate(QString text);
    void notifyPosValueUpdate(int value);

    /* @desc 添加监听者*/
    void addListener(std::weak_ptr<Listener> listener);

    /* @desc 删除监听者*/
    void removeListener(std::weak_ptr<Listener> listener);

private:

    /* @desc 上层适配器*/
    std::shared_ptr<Adapter> m_adapter;

    /* @desc 监听者*/
    std::vector<std::weak_ptr<Listener>> m_listeners;

    /* @desc Listeners access mutex*/
    std::mutex m_listenersMutex;

};

#endif // SERVICE_H
