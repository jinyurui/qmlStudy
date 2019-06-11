#include "placeimp.h"

PlaceImp::PlaceImp()
{
    m_id = 0;
    m_name = "noname";
}

PlaceImp::~PlaceImp()
{

}

PlaceImp::PlaceImp(const PlaceImp &from)
{
    m_id = from.m_id;
    m_name = from.m_name;
}

void PlaceImp::setId(const int id)
{
    m_id = id;
}

int PlaceImp::getId() const
{
    return m_id;
}

void PlaceImp::setName(const QString name)
{
    m_name = name;
}

QString PlaceImp::getName() const
{
    return m_name;
}
