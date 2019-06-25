#include "easyitem.h"

EasyItem::EasyItem(QString str, int c)
    :m_desc(str),m_count(c)
{

}

QString EasyItem::desc() const
{
    return m_desc;
}
int EasyItem::count() const
{
    return m_count;
}

void EasyItem::setDesc(QString desc)
{
    if (m_desc == desc)
        return;

    m_desc = desc;

}
void EasyItem::setCount(int count)
{
    if (m_count == count)
        return;

    m_count = count;

}
