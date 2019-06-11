#ifndef DATACONTROLIMP_H
#define DATACONTROLIMP_H

#include <QObject>
#include <memory>
#include "datacontrol.h"

class QPlace;

class DataControlImp: public QObject
{
    Q_OBJECT
public:
    DataControlImp(QObject *p = nullptr);

    void controlObject(DataControl::DataType type);

private:
    std::shared_ptr<QPlace> m_pQPlace;
};

#endif // DATACONTROLIMP_H
