#ifndef SETTINGOBS_H
#define SETTINGOBS_H

#include "observer.h"

class DataSum;
/** node
* @key    具体的 观察者
* @desc
*/
class SettingObs:public Observer
{
public:
    SettingObs(DataSum *p);
    ~SettingObs() override;
    virtual void update() override;

private:
    DataSum* m_pDataSum;
};

#endif // SETTINGOBS_H
