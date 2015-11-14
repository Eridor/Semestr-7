#ifndef RLE_H
#define RLE_H

#include <QDebug>
#include <QMap>
#include <QFile>
#include <QByteArray>
#include <QTime>
#include <QString>
#include <QPair>
#include <QSet>

class RLE
{
public:
    RLE();
    static bool Compress(QString FilePath);
    static bool Decompress(QString FilePath);

private:
    struct Element
    {
        quint8 item;
        quint32 value;
    };
    static quint32 HexToInt(QByteArray B);
    static QByteArray IntToHex(quint32 Num);
};

#endif // RLE_H
