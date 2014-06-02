#include "faithdatabuilder.h"
#include <QDebug>
#include "fdstring.h"
#include "fdstringlist.h"
#include "fdproposedip.h"
#include "fdhostinfo.h"

FaithDataBuilder::FaithDataBuilder()
{
}

FaithData* FaithDataBuilder::buildFaithData(Faithcore::MessageCode messageCode)
{
    FaithData* val;
    switch (messageCode) {
    case Faithcore::GET_LAB_LIST_OR_HOST_INFO:
        val = 0;
        break;
    case Faithcore::LAB_LIST:
        val = new FdStringList();
        break;
    case Faithcore::RESERVE_IP:
        val = new FdString();
        break;
    case Faithcore::PROPOSED_IP:
        val = new FdProposedIp();
        break;
    case Faithcore::OK:
        val = 0;
        break;
    case Faithcore::ERROR:
        val = new FdString();
        break;
    case Faithcore::HOST_INFO:
        val = new FdHostInfo();
        break;
    default:    
        val = 0;
        qDebug() << "FaithDataBuilder Error: code " << messageCode << " not implemented";
    }
    return val;
}
