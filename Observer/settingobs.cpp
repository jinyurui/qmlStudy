#include "settingobs.h"
#include "datasum.h"
#include <QDebug>

SettingObs::SettingObs(DataSum *p)
    :m_pDataSum(p)
{

}

SettingObs::~SettingObs()
{

}

void SettingObs::update()
{
    qDebug() << "observer has get the call";
    if(m_pDataSum){
        m_pDataSum->onSettingsUpDate();
    }
}
