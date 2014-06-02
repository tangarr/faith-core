#ifndef FAITHCORE_H
#define FAITHCORE_H

#include <QString>
#include <QtCore>
#include <QMetaEnum>

class Faithcore : public QObject
{
    Q_OBJECT
    Q_ENUMS(MessageCode)

public:
    Faithcore();
    enum MessageCode
    {
        GET_LAB_LIST_OR_HOST_INFO,
        HOST_INFO,
        LAB_LIST,
        RESERVE_IP,
        PROPOSED_IP,
        OK,
        ERROR,
    };
    static quint32 ipFromString(const QString &ip);
    static QString ipFromInt(const quint32 &ip);
    static QString MessageCodeToString(MessageCode code);


};

#endif // FAITHCORE_H
