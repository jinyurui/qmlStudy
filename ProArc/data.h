#ifndef DATA_H
#define DATA_H

#include <memory>
#include <QMetaType>
#include "srcdata.h"

/** node
* @key    page struct with easy Qt, support with the help of meta.
* @desc
*/

class Data
{
    Q_GADGET
    Q_PROPERTY(QString name READ getName)
    Q_PROPERTY(int count READ getCount)

public:
    Data();
    Data(std::shared_ptr<srcData> p);
    ~Data();

    QString getName() const;
    int getCount() const;

private:
    std::shared_ptr<srcData> m_pSrcData;
};
Q_DECLARE_METATYPE(Data)

#endif // DATA_H
