#ifndef FDHOSTINFO_H
#define FDHOSTINFO_H

#include "faithdata.h"

class FdHostInfo : FaithData
{
    QString _lab, _hostname;
    quint32 _ip;
public:
    FdHostInfo() = default;
    FdHostInfo(QString lab, QString hostname, quint32 ip);

    // FaithData interface
public:
    QByteArray &rawDada() const;
    bool readRawData(const QByteArray &raw);
};

#endif // FDHOSTINFO_H
