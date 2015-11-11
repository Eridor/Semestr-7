#include "rle.h"

RLE::RLE()
{

}

void RLE::Compress(QString FilePath)
{
    QFile file(FilePath);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QByteArray ByteArray = file.readAll();

    QMap<quint8, int> IIMap;

    for (short int i = 0; i < 256; ++i) {
        IIMap.insert(static_cast<quint8>(i), 0);
    }


    qDebug() << "Całość:";
    qDebug() << ByteArray;

    QMap<quint8, int>::iterator it;
    for(it = IIMap.begin(); it != IIMap.end(); ++it)
    {
        it.value() = ByteArray.count(static_cast<char>(it.key()));
    }

    for (it = IIMap.begin(); it != IIMap.end(); it++)
    {
        qDebug() << it.key() << ", " << it.value();
    }

    //const BYTE* CharTable = (const BYTE*) ByteArray.constData();
    //int size = ByteArray.size();
    //for (int var = 0; var < size; ++var) {
    //    qDebug() << QString::number(CharTable[var], 16);
    //}

    //Choose ASCII sign
    quint8 SIGN = 0;
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());
    while (true)
    {
        quint8 rand = qrand() % 224 + 32;
        if (IIMap.value(rand) == 0 && rand > 128) {
            SIGN = rand;
            break;
        }
    }

    qDebug() << "ZNAK: " << SIGN;

    QByteArray OutByteArray;
    int End = ByteArray.size();
    int Counter = 0;
    int RunCount = 0;
    quint8 CurrentByte, PreviousByte, TempByte;

    OutByteArray.append(static_cast<char>(SIGN));
    PreviousByte = static_cast<quint8>(ByteArray.at(Counter));
    Counter++;
    while (Counter < End)
    {
        CurrentByte = static_cast<quint8>(ByteArray.at(Counter));
        Counter++;
        if (Counter == End) {
            if (RunCount == 0) {
                OutByteArray.append(static_cast<char>(CurrentByte));
                break;
            } else {

            }
        }
    }
}
