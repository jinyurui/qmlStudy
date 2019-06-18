#ifndef DATASUM_H
#define DATASUM_H

#include <QObject>
#include "subject.h"
#include "settingobs.h"
#include <memory>
/** node
* @key    test
* @desc
*/
class DataSum:public QObject
{
    Q_OBJECT
public:
    explicit DataSum(QObject *parent = nullptr);
    void onSettingsUpDate();

    // test
    Q_INVOKABLE void testSubjectCallBack();
private:
    std::shared_ptr<Subject> m_pSubject;

    std::shared_ptr<SettingObs> m_pSettingObs;
};

#endif // DATASUM_H
