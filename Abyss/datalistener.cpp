#include "datalistener.h"
#include "service.h"
#include <QDebug>

void DataLister::registerForUpdate(){
    DataService& service = SignleServiceManager::getDataService();
    service.registerListen(shared_from_this());
}

void DataLister::onDataChanged(int data){
    qDebug() << "data changed" << data;
}
