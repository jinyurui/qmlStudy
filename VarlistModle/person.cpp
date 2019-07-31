#include "person.h"

Person::Person()
{

}

Person::Person(QString name, int age)
{
    m_name = name;
    m_age = age;
}

QString Person::name() const
{
    return m_name;
}

int Person::age() const
{
    return m_age;
}

void Person::setName(QString name)
{
    m_name = name;
}

void Person::setAge(int age)
{
    m_age = age;
}
