#include "faithmessage.h"
#include <QDataStream>
#include <QFile>

bool FaithMessage::send(QTcpSocket *socket) const
{
    /*
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_2);
    stream << static_cast<quint16>(messageCode);

    if (text.size()==0)
    {
        stream << text.size();
    }
    else
    {
        QByteArray raw;
        raw.append(text);
        QByteArray data = qCompress(raw, 9);
        stream << data.size() << data;
    }
    //QByteArray data =

    //stream << data.size();
    //if (data.size()>0) stream << data;
    */
}

bool FaithMessage::recive(QTcpSocket *socket)
{

}

Faithcore::MessageCode FaithMessage::getMessageCode() const
{
    return messageCode;
}
