#include "faithmessage.h"
#include <QDataStream>
#include <QFile>
#include "faithdatabuilder.h"
#include "fdstring.h"
#include "fdstringlist.h"
#include "fdproposedip.h"
#include "fdhostinfo.h"

bool FaithMessage::send(QTcpSocket *socket) const
{

    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_2);
    quint16 code = static_cast<quint16>(messageCode);
    stream << code;
    int length = 0;

    if (data==0)
    {
        stream << length;
    }
    else
    {
        QByteArray raw = data->rawDada();
        QByteArray data = qCompress(raw, 9);
        length = data.size();
        stream << length;
        stream << data;
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
        //char *buffor = new char[length];
        //stream.readRawData(buffor, length);
        //QByteArray compressed(buffor, length);
        QByteArray compressed;
        stream >> compressed;
        //delete buffor;
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

FaithData *FaithMessage::getData() const
{
    return data;
}

FaithMessage &FaithMessage::MsgGetLabListOrHostInfo(QString mac)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::GET_LAB_LIST_OR_HOST_INFO;
    msg->data = new FdString(mac);
    return *msg;
}

FaithMessage &FaithMessage::MsgLabList(QStringList labList)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::LAB_LIST;
    msg->data = new FdStringList(labList);
    return *msg;
}

FaithMessage &FaithMessage::MsgReserveIp(QString lab)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::RESERVE_IP;
    msg->data = new FdString(lab);
    return *msg;
}

FaithMessage &FaithMessage::MsgProposedIp(quint32 ip, QString hostName)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::PROPOSED_IP;
    msg->data = new FdProposedIp(ip, hostName);
    return *msg;
}

FaithMessage &FaithMessage::MsgHostInfo(QString lab, QString hostName, quint32 ip)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::HOST_INFO;
    msg->data = new FdHostInfo(lab, hostName, ip);
    return *msg;
}

FaithMessage &FaithMessage::MsgOk()
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::OK;
    msg->data = 0;
    return *msg;
}

FaithMessage &FaithMessage::MsgError(QString message)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::ERROR;
    msg->data = new FdString(message);
    return *msg;
}

FaithMessage &FaithMessage::MsgSendFile(QString filePatch)
{

}
