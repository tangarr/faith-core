#ifndef FAITHMESSAGE_H
#define FAITHMESSAGE_H

#include <QtCore>
#include "faithcore.h"
#include <QTcpSocket>


class FaithMessage
{
private:
    FaithMessage() {}
    Faithcore::MessageCode messageCode;


public:
    bool send(QTcpSocket*) const;
    bool recive(QTcpSocket*);
    Faithcore::MessageCode getMessageCode() const;
};

#endif // FAITHMESSAGE_H
