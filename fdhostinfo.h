#ifndef FDHOSTINFO_H
#define FDHOSTINFO_H

#include "faithdata.h"

class FdHostInfo : public FaithData
{
    QString _lab, _hostname, _mac;
    quint32 _ip;
public:
    FdHostInfo();
    FdHostInfo(QString lab, QString hostname, quint32 ip, QString mac="");

    // FaithData interface
public:
    QByteArray &rawDada() const;
    bool readRawData(const QByteArray &raw);
    QString lab() const;
    QString hostname() const;
    QString ip_string() const;
    QString mac() const;
    quint32 ip() const;
};

#endif // FDHOSTINFO_H
