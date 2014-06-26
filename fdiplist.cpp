#include "fdiplist.h"


FdIpList::FdIpList()
{
}

QByteArray &FdIpList::rawDada() const
{
    QByteArray *raw=new QByteArray();
    QDataStream stream(raw, QIODevice::WriteOnly);
    stream << (int)_list.count();
    for (int i=0;i<_list.count();i++) stream << _list.at(i);
    return *raw;
}

bool FdIpList::readRawData(const QByteArray &raw)
{
    QDataStream stream(raw);
    int count;
    stream >> count;
    for (int i=0;i<count;i++)
    {
        quint32 ip;
        stream >> ip;
        _list.append(ip);
    }
    return true;
}

int FdIpList::count() const
{
    return _list.count();
}

quint32 FdIpList::ip(int index)
{
    if (index>=0 && index<_list.count())
    {
        return _list.at(index);
    }
    else return 0;
}

QString FdIpList::ipString(int index)
{
    if (index>=0 && index<_list.count())
    {
        return Faithcore::ipFromInt(_list.at(index));
    }
    else return "";
}
