#include "faithmessage.h"
#include <QDataStream>
#include <QFile>
#include "faithdatabuilder.h"
#include "fdstring.h"
#include "fdstringlist.h"

bool FaithMessage::send(QTcpSocket *socket) const
{

    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_2);
    stream << static_cast<quint16>(messageCode);

    if (data==0)
    {
        stream << (int)0;
    }
    else
    {
        QByteArray raw = data->rawDada();
        QByteArray data = qCompress(raw, 9);
        stream << data.size() << data;
    }
    socket->flush();
    return true;
}

bool FaithMessage::recive(QTcpSocket *socket)
{
    quint16 code;
    int length;
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_2);
    stream >> code >> length;
    messageCode = static_cast<Faithcore::MessageCode>(code);
    if (length>0)
    {
        data = FaithDataBuilder::buildFaithData(messageCode);
        if (!data) return false;
        char *buffor = new char[length];
        stream.readRawData(buffor, length);
        QByteArray compressed(buffor, length);
        delete buffor;
        QByteArray raw=qUncompress(compressed);
        return data->readRawData(raw);
    }
    else
    {
        data=0;
        return true;
    }

}

Faithcore::MessageCode FaithMessage::getMessageCode() const
{
    return messageCode;
}

FaithMessage &FaithMessage::MsgGetLabList(QString labName)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::GET_LAB_LIST;
    msg->data = new FdString(labName);
    return *msg;
}
