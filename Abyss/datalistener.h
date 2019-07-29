#ifndef DATALISTENER_H
#define DATALISTENER_H

#include <memory>

class DataLister:public std::enable_shared_from_this<DataLister>{
public:
    DataLister() = default;
    ~DataLister() = default;

    void registerForUpdate();
    void onDataChanged(int data);
};

#endif // DATALISTENER_H
