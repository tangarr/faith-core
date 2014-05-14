#ifndef FAITHMESSAGE_H
#define FAITHMESSAGE_H

#include <QtCore>
#include "faithcore.h"
#include <QTcpSocket>
#include "faithobject.h"


class FaithMessage
{
private:
    FaithMessage() {}
    Faithcore::MessageCode messageCode;
    FaithObject *data;


public:
    bool send(QTcpSocket*) const;
    bool recive(QTcpSocket*);
    Faithcore::MessageCode getMessageCode() const;
    FaithObject* getData() const;
};

#endif // FAITHMESSAGE_H
