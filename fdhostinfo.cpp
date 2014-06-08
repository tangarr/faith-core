#include "fdhostinfo.h"
#include "faithcore.h"

FdHostInfo::FdHostInfo()
{
    _lab = _hostname = _mac = "";
    _ip = 0;
}

FdHostInfo::FdHostInfo(QString lab, QString hostname, quint32 ip, QString mac)
{
    _lab = lab;
    _hostname = hostname;
    _ip = ip;
    _mac = mac;
}

QByteArray &FdHostInfo::rawDada() const
{
    QByteArray *raw=new QByteArray();
    QDataStream stream(raw, QIODevice::WriteOnly);
    stream << _ip << _hostname << _lab << _mac;
    return *raw;
}

bool FdHostInfo::readRawData(const QByteArray &raw)
{
    QDataStream stream(raw);
    stream >> _ip >> _hostname >> _lab >> _mac;
    return true;
}

QString FdHostInfo::lab() const
{
    return _lab;
}

QString FdHostInfo::ip_string() const
{
    return Faithcore::ipFromInt(_ip);
}

QString FdHostInfo::mac() const
{
    return _mac;
}

quint32 FdHostInfo::ip() const
{
    return _ip;
}

QString FdHostInfo::hostname() const
{
    return _hostname;
}
