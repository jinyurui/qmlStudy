#ifndef DATAIMP_H
#define DATAIMP_H

#include <QVariantList>

/** node
* @key    data privite pointer
* @desc
*/

class DataCon;

class DataImp
{

public:
    DataImp(DataCon *p);

    QVariantList dataList() const;

private:
    void testHelp(int callBackListData);

private:
    QVariantList  list;
    DataCon *Q_Qp;
};


#endif // DATAIMP_H
