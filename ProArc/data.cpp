#include "data.h"

Data::Data()
{
    m_pSrcData = std::make_shared<srcData>();
}

Data::Data(std::shared_ptr<srcData> p)
    :m_pSrcData(p)
{

}

Data::~Data()
{

}

QString Data::getName() const
{
    return  m_pSrcData->getName();
}

int Data::getCount() const
{
    return m_pSrcData->getCount();
}
