#ifndef POSLISTENIMPL_H
#define POSLISTENIMPL_H

#include <memory>
#include "listener.h"

class PosListen;
class PoslistenImpl:public Listener, public std::enable_shared_from_this<PoslistenImpl>
{
public:
    PoslistenImpl(PosListen *ptr);

    void createService();

private:
    void onContextChanged(QString text) override ;
    void onPosValueChanged(int value) override;

private:
    PosListen *q_ptr;
};

#endif // POSLISTENIMPL_H
