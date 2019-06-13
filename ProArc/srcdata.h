#ifndef SRCDATA_H
#define SRCDATA_H

#include <QString>
/** node
* @key  easy struct set get only
* @desc
*/
class srcData
{
public:
    srcData();

    int getCount() const;
    QString getName() const;

private:
    int count;
    QString name;
};

#endif // SRCDATA_H
