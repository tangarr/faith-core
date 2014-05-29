#include "faithcore.h"
#include <QtCore>
#include <QString>

Faithcore::Faithcore() : QObject(0)
{
}

quint32 Faithcore::ipFromString(const QString& ip)
{
    quint8 tab[4];
    QStringList str = ip.split(".");
    for (int i=0; i<4; i++)
    {
        tab[i] = str[i].toUInt();
    }
    quint32 val = tab[0] << 24 | tab[1] << 16 | tab[2] <<8 | tab[3];
    return val;
}
QString Faithcore::ipFromInt(const quint32& ip)
{
    quint8 a,b,c,d;
    a = (quint8) (ip >> 24);
    b = (quint8) (ip >> 16);
    c = (quint8) (ip >> 8);
    d = (quint8) ip;
    return QString("%1.%2.%3.%4").arg(a).arg(b).arg(c).arg(d);
}

QString Faithcore::MessageCodeToString(Faithcore::MessageCode code)
{
    QMetaObject obj = Faithcore::staticMetaObject;
    QMetaEnum en = obj.enumerator(0);
    return QLatin1String(en.valueToKey((int)code));
}
