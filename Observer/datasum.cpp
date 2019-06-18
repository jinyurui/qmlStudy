#include "datasum.h"
#include <QDebug>

DataSum::DataSum(QObject *parent)
    :QObject (parent)
{
    m_pSubject = std::make_shared<Subject>();

    m_pSettingObs = std::make_shared<SettingObs>(this);
    qDebug() << "------" << m_pSettingObs.use_count();
    m_pSubject->registerObserver(m_pSettingObs);
}

void DataSum::onSettingsUpDate()
{
    qDebug() << " get settings update";
}

void DataSum::testSubjectCallBack()
{
    qDebug() << "send data update";
    m_pSubject->notifiObserver();
}
