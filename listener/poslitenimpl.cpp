#include "poslistenimpl.h"
#include "servicemanager.h"
#include "poslisten.h"

static std::shared_ptr<ServiceManager> pService;

PoslistenImpl::PoslistenImpl(PosListen *ptr)
    :q_ptr(ptr)
{

}

void PoslistenImpl::createService()
{
    pService = std::make_shared<ServiceManager>();
    pService->registerListener(shared_from_this());
    pService->startService();
}

void PoslistenImpl::onContextChanged(QString text)
{
    q_ptr->setContext(text);
}

void PoslistenImpl::onPosValueChanged(int value)
{
    q_ptr->setPosValue(value);
}
