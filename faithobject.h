#ifndef FAITHOBJECT_H
#define FAITHOBJECT_H

#include "faithcore.h"
#include <QByteArray>

class FaithObject
{
public:
    FaithObject() {}
    virtual ~FaithObject() {}
    virtual Faithcore::DataType dataType() const = 0;
    virtual QByteArray rawDada() const = 0;
    virtual bool readRawData(const QByteArray) = 0;
};

#endif // FAITHOBJECT_H
