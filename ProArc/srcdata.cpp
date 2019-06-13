#include "srcdata.h"

srcData::srcData()
{
    count = __LINE__;
    name = __FUNCTION__;
}

int srcData::getCount() const
{
    return count;
}

QString srcData::getName() const
{
    return name;
}
