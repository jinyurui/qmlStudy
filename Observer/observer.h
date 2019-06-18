#ifndef OBSERVER_H
#define OBSERVER_H
/** node
* @key    抽象 观察者
* @desc
*/
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update() = 0;
};

#endif // OBSERVER_H
