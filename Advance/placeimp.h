#ifndef PLACEIMP_H
#define PLACEIMP_H

//#include "***.pd.h" [craete :Place.proto build by proto.exe]

#include <QString>

class PlaceImp
{
public:
    PlaceImp();
    ~PlaceImp();

    PlaceImp(const PlaceImp& from);

    void setId(const int id);
    int getId() const;

    void setName(const QString name);
    QString getName() const;

private:
    /** node
    * @key    this data can be set from protobuf, so you can expend with protobuf
    * @desc   you need add  std::shared_ptr<Place> m_placeData as number of this class
    *         then, all data can bind to proto
    */
    int m_id;
    QString m_name;
};

#endif // PLACEIMP_H
