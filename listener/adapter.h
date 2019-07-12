#ifndef ADAPTER_H
#define ADAPTER_H

#include "types.h"
#include <QTimer>
#include <memory>

class Adapter
{
public:
    Adapter();
    void start();
    void stop();

    void setCallbackForContext(ContextCallback callback);
    void setCallbackForPos(PosCallback callback);

private:
    ContextCallback m_contextCallback;
    PosCallback m_posCallback;

    std::unique_ptr<QTimer> m_pTime;
};

#endif // ADAPTER_H
