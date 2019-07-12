#ifndef LISTENER_H
#define LISTENER_H

#include <QString>
class Listener
{
public:
    virtual ~Listener() = default;
    virtual void onContextChanged(QString text) = 0;
    virtual void onPosValueChanged(int value) = 0;
};

#endif // LISTENER_H
