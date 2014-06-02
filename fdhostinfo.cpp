#include "fdhostinfo.h"

FdHostInfo::FdHostInfo(QString lab, QString hostname, quint32 ip)
{
    _lab = lab;
    _hostname = hostname;
    _ip = ip;
}

QByteArray &FdHostInfo::rawDada() const
{
    QByteArray *raw=new QByteArray();
    QDataStream stream(raw, QIODevice::WriteOnly);
    stream << _ip << _hostname << _lab;
    return *raw;
}

bool FdHostInfo::readRawData(const QByteArray &raw)
{
    QDataStream stream(raw);
    stream >> _ip >> _hostname >> _lab;
    return true;
}
