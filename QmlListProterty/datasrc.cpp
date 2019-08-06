#include "datasrc.h"
#include <QDebug>

DataSrc::DataSrc(QObject *parent)
    :QObject (parent)
{
    createCars();

    m_cars = new QQmlListProperty<Car>(this, nullptr,
                                          &DataSrc::appendFunction,
                                          &DataSrc::countFunction,
                                          &DataSrc::atFunction,
                                          &DataSrc::clearFunction);
}

QQmlListProperty<Car> DataSrc::cars()
{
    return *(m_cars);
}

void DataSrc::createCars()
{
    for(int i = 0; i < 3; ++i){
        Car *item = new Car();
        item->setName(QString("car_%1").arg(i+1));
        item->setPrice(100*i);
        m_carsData.append(item);
    }
}

void DataSrc::appendFunction(QQmlListProperty<Car> *cars, Car *car)
{
    qDebug() << "append";
    DataSrc *obj = qobject_cast<DataSrc*>(cars->object);
    if(obj){
        car->setParent(obj);
        obj->m_carsData.append(car);
    }
}

int DataSrc::countFunction(QQmlListProperty<Car> *cars)
{
    qDebug() << "count";
    DataSrc *obj = qobject_cast<DataSrc*>(cars->object);
    if(obj){
        return obj->m_carsData.count();
    }
}

Car *DataSrc::atFunction(QQmlListProperty<Car> *cars, int pos)
{
    qDebug() << "at";
    DataSrc *obj = qobject_cast<DataSrc*>(cars->object);
    if(obj){
        return obj->m_carsData.at(pos);
    }
}

void DataSrc::clearFunction(QQmlListProperty<Car> *cars)
{
    qDebug() << "clear";
    DataSrc *obj = qobject_cast<DataSrc*>(cars->object);
    if(obj){
        return obj->m_carsData.clear();
    }
}

