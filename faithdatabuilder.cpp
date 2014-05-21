#include "faithdatabuilder.h"
#include <QDebug>

FaithDataBuilder::FaithDataBuilder()
{
}

FaithData* FaithDataBuilder::buildFaithData(Faithcore::MessageCode messageCode)
{
    FaithData* val;
    switch (messageCode) {
    default:
        val = 0;
        qDebug() << "FaithDataBuilder Error: code " << messageCode << " not implemented";
    }
    return val;
}
