#ifndef PERSON_H
#define PERSON_H

#include <QMetaType>
#include <QString>

class Person
{
    Q_GADGET
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(int age READ age WRITE setAge)

public:
    Person();
    Person(QString name, int age);
    QString name() const;
    int age() const;

public slots:
    void setName(QString name);
    void setAge(int age);

private:
    QString m_name;
    int m_age;
};
Q_DECLARE_METATYPE(Person)

#endif // PERSON_H
