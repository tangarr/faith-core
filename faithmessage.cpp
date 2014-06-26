#include "faithmessage.h"
#include <QDataStream>
#include <QFile>
#include "faithdatabuilder.h"
#include "fdstring.h"
#include "fdstringlist.h"
#include "fdproposedip.h"
#include "fdhostinfo.h"
#include "fdfile.h"
#include "fdiplist.h"

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
    socket->waitForReadyRead();
    quint16 code;
    int length;
    QDataStream stream(socket);
    stream.setVersion(QDataStream::Qt_5_2);
    stream >> code >> length;
    messageCode = static_cast<Faithcore::MessageCode>(code);
    if (messageCode==Faithcore::EMPTY)
    {
        qWarning() << "ERROR: Recived EMPTY message";
    }
    if (length>0)
    {
        data = FaithDataBuilder::buildFaithData(messageCode);
        if (!data) return false;
        QByteArray compressed;
        stream >> compressed;
        QByteArray raw=qUncompress(compressed);
        bool readen = data->readRawData(raw);
        return readen;
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

FaithMessage &FaithMessage::MsgAcceptIp(QString lab, QString hostName, quint32 ip, QString mac)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::ACCEPT_IP;
    msg->data = new FdHostInfo(lab, hostName, ip, mac);
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

FaithMessage &FaithMessage::MsgSendFile(QString filePath)
{
    FaithMessage* msg = new FaithMessage();
    FdFile *file = new FdFile();
    file->readFile(filePath);
    msg->messageCode = Faithcore::SEND_FILE;
    msg->data = file;
    return *msg;
}

FaithMessage &FaithMessage::MsgGetFileList()
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::GET_FILE_LIST;
    msg->data=0;
    return *msg;
}

FaithMessage &FaithMessage::MsgFileList(QStringList fileList)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::FILE_LIST;
    msg->data=new FdStringList(fileList);
    return *msg;
}

FaithMessage &FaithMessage::MsgGetFile(QString filename)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::GET_FILE;
    msg->data=new FdString(filename);
    return *msg;
}

FaithMessage &FaithMessage::MsgRequestInstall(QList<quint32> hosts)
{
    FaithMessage* msg = new FaithMessage();
    msg->messageCode = Faithcore::REQUEST_INSTALL;
    msg->data=new FdIpList(hosts);
    return *msg;
}
