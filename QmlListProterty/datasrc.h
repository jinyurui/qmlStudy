#ifndef DATASRC_H
#define DATASRC_H

#include <QObject>
#include <QQmlListProperty>

class Car:public QObject{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(float price READ price WRITE setPrice NOTIFY priceChanged)
public:
    Car(){}
    QString name() const
    {
        return m_name;
    }
    float price() const
    {
        return m_price;
    }

public slots:
    void setName(QString name)
    {
        if (m_name == name)
            return;

        m_name = name;
        emit nameChanged(m_name);
    }
    void setPrice(float price)
    {
        if (qFuzzyCompare(m_price, price))
            return;

        m_price = price;
        emit priceChanged(m_price);
    }

signals:
    void nameChanged(QString name);
    void priceChanged(float price);

private:
    QString m_name;
    float m_price;
};

class DataSrc: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Car> cars READ cars) // qmllist , you can edit on qml and c++;
                                                     // this diff list<T> only by c+++

private:
    QList<Car*> m_carsData;            //  data
    QQmlListProperty<Car> *m_cars;     //  proterty

public:
    DataSrc(QObject *parent = nullptr);
    QQmlListProperty<Car> cars();

private:
    void createCars();

public:
    static void appendFunction(QQmlListProperty<Car> * cars, Car* car);
    static int countFunction(QQmlListProperty<Car> *cars);
    static Car* atFunction(QQmlListProperty<Car> *cars, int pos);
    static void clearFunction(QQmlListProperty<Car> *cars);
};

#endif // DATASRC_H
