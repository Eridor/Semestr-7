#ifndef RLE_H
#define RLE_H

#include <QDebug>
#include <QMap>
#include <QFile>
#include <QByteArray>
#include <QTime>
#include <QString>

class RLE
{
public:
    RLE();
    void Compress(QString FilePath);
    void Decompress(QString FilePath);
private:
    struct Element
    {
        quint8 item;
        int value;
    };
};

#endif // RLE_H
