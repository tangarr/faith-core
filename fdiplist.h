#ifndef FDIPLIST_H
#define FDIPLIST_H

#include "faithdata.h"

class FdIpList : public FaithData
{
    QList<quint32> _list;
public:
    FdIpList();
public:
    QByteArray &rawDada() const;
    bool readRawData(const QByteArray &);
    int count() const;
    quint32 ip(int index);
    QString ipString(int index);
};

#endif // FDIPLIST_H
