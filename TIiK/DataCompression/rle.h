#ifndef RLE_H
#define RLE_H

#include <QFile>
#include <QDebug>
#include <QMap>
#include <QByteArray>
#include <QtGlobal>
#include <QTime>

typedef unsigned char BYTE; //byte definition

class RLE
{
public:
    RLE();
    void Compress(QString FilePath);
};

#endif // RLE_H
