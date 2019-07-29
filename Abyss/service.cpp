#include "service.h"
#include "datalistener.h"

void DataService::registerListen(std::weak_ptr<DataLister> listen){
    dataListeners.add(listen);
}

void DataService::unregisterListen(std::weak_ptr<DataLister> listen){
    dataListeners.remove(listen);
}

void DataService::dataChange(int data){
    dataListeners.notifyCallbacks([&data](const std::shared_ptr<DataLister> listen){
        listen->onDataChanged(data);
    });
}

