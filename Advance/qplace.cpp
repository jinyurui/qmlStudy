#include "qplace.h"
#include <QJsonObject>
#include "placeimp.h"
#include <QDebug>

QPlace::QPlace()
{
    // seam
    m_data = std::make_shared<PlaceImp>();
}

int QPlace::id() const
{
    return m_data->getId();
}

QString QPlace::name() const
{
    return m_data->getName();
}

void QPlace::showPlaceInfo()
{
    QJsonObject obj = QJsonObject{{"id",m_data->getId()},{"name",m_data->getName()}};
    qDebug() << obj;
}
