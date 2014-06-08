#ifndef FAITHMESSAGE_H
#define FAITHMESSAGE_H

#include <QtCore>
#include "faithcore.h"
#include <QTcpSocket>
#include "faithdata.h"

class FaithMessage
{
private:    
    Faithcore::MessageCode messageCode;
    FaithData *data;

public:
    FaithMessage() {}
    bool send(QTcpSocket*) const;
    bool recive(QTcpSocket*);
    Faithcore::MessageCode getMessageCode() const;
    FaithData* getData() const;
    static FaithMessage &MsgGetLabListOrHostInfo(QString mac);
    static FaithMessage &MsgLabList(QStringList labList);
    static FaithMessage &MsgReserveIp(QString lab);
    static FaithMessage &MsgProposedIp(quint32 ip, QString hostName);
    static FaithMessage &MsgHostInfo(QString lab, QString hostName, quint32 ip);
    static FaithMessage &MsgOk();
    static FaithMessage &MsgError(QString message);
    static FaithMessage &MsgSendFile(QString filePatch);
};

#endif // FAITHMESSAGE_H
