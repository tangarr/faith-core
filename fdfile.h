#ifndef FDFILE_H
#define FDFILE_H

#include "faithdata.h"
#include <QByteArray>
#include <QString>

class FdFile : public FaithData
{
    QString _filename;
    QByteArray _data;
public:
    FdFile();
    FdFile(QString filename, QByteArray data);
    QByteArray &rawDada() const;
    bool readRawData(const QByteArray &);
    QString filename() const;
    QByteArray data() const;
    bool readFile(QString filePath);
    bool saveFile(QString filePath) const;

};

#endif // FDFILE_H
