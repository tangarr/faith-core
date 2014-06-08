#include "fdfile.h"
#include <QFile>

FdFile::FdFile()
{
}

FdFile::FdFile(QString filename, QByteArray data)
{
    _filename = filename;
    _data = data;
}

QByteArray &FdFile::rawDada() const
{
    QByteArray *raw=new QByteArray();
    QDataStream stream(raw, QIODevice::WriteOnly);
    stream << _filename << _data;
    return *raw;
}

bool FdFile::readRawData(const QByteArray &raw)
{
    QDataStream stream(raw);
    stream >> _filename >> _data;
    return true;
}

QString FdFile::filename() const
{
    return _filename;
}

QByteArray FdFile::data() const
{
    return _data;
}

bool FdFile::readFile(QString filePath)
{
    QFile f(filePath);
    if (!f.open(QIODevice::ReadOnly)) return false;
    _data = f.readAll();
    _filename = f.fileName().section("/",-1,-1);
    return true;
}

bool FdFile::saveFile(QString filePath) const
{
    QFile f(filePath);
    if (!f.open(QIODevice::WriteOnly)) return false;
    f.write(_data);
    return true;
}
