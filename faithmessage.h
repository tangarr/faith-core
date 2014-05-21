#ifndef FAITHMESSAGE_H
#define FAITHMESSAGE_H

#include <QtCore>
#include "faithcore.h"
#include <QTcpSocket>
#include "faithdata.h"


class FaithMessage
{
private:
    FaithMessage() {}
    Faithcore::MessageCode messageCode;
    FaithData *data;


public:
    bool send(QTcpSocket*) const;
    bool recive(QTcpSocket*);
    Faithcore::MessageCode getMessageCode() const;
    FaithData* getData() const;
};

#endif // FAITHMESSAGE_H
