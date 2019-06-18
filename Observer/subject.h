#ifndef SUBJECT_H
#define SUBJECT_H

#include <QObject>
#include <memory>

class Observer;
/** node
* @key    主体 维护一个观察者列表，其不主导观察者的生命周期，因此使用 std::weak_ptr
* @desc
*/
class Subject
{
public:
    explicit Subject();

    void registerObserver(std::weak_ptr<Observer> item);

    void deleteObserver(std::weak_ptr<Observer> item);

    void clearAll();

    void notifiObserver();

    // call back , data change.
private:
    std::list<std::shared_ptr<Observer>> obsList;
};

#endif // SUBJECT_H
