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
    static FaithMessage &MsgGetLabList(QString labName);
};

#endif // FAITHMESSAGE_H
