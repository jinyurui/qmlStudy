#ifndef SERVICE_H
#define SERVICE_H

#include "listenercontainer.h"
#include <QObject>

class DataLister;

class DataService{
public:
    DataService() = default;
    ~DataService() = default;

    void registerListen(std::weak_ptr<DataLister> listen);

    void unregisterListen(std::weak_ptr<DataLister> listen);

    void dataChange(int data);
private:
    ListenerContainer<DataLister> dataListeners;
};

class SignleServiceManager{
Q_DISABLE_COPY(SignleServiceManager)
private:
    SignleServiceManager(){

    }

public:
    static DataService& getDataService(){
        static DataService obj;
        return obj;
    }
};


#endif // SERVICE_H
