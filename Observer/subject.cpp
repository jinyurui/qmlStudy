#include "subject.h"
#include "observer.h"
#include <QDebug>

Subject::Subject()
{

}

void Subject::registerObserver(std::weak_ptr<Observer> item)
{
    obsList.push_back(item.lock());
    qDebug() << "========" << obsList.begin()->use_count();
}

void Subject::deleteObserver(std::weak_ptr<Observer> item)
{
    obsList.remove(item.lock());
}

void Subject::clearAll()
{
    obsList.clear();
}

void Subject::notifiObserver()
{
    foreach (auto one, obsList) {
//        if(!one.expired()){
//            one.lock()->update();
//        }
        one->update();
    }
}
