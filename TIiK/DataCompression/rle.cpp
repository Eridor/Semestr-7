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
    file.close();


    QMap<quint8, int> IIMap;
    for (quint8 i = 0; i < 255; i++) {
        IIMap.insert(i, 0);
    }
    QMap<quint8, int>::iterator it;
    for(it = IIMap.begin(); it != IIMap.end(); ++it) {
        it.value() = ByteArray.count(static_cast<char>(it.key()));
    }


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
    //qDebug() << "ZNAK: " << QString("%0").arg(SIGN, 1, 16);

    QByteArray OutByteArray;
    OutByteArray.append(static_cast<char>(SIGN));

    QList<Element> Elements;
    quint8 CurrentByte;
    for (int i = 0; i < ByteArray.size(); ++i) {
        CurrentByte = static_cast<quint8>(ByteArray.at(i));
        if (Elements.empty()) {
            Element e;
            e.item = CurrentByte;
            e.value = 1;
            Elements.append(e);
        } else if (Elements.last().item == CurrentByte) {
            Elements.last().value++;
        } else {
            Element e;
            e.item = CurrentByte;
            e.value = 1;
            Elements.append(e);
        }
    }


    foreach (Element e, Elements) {
        if (e.value == 1) {
            OutByteArray.append(e.item);
        } else if (e.value > 3) {
            OutByteArray.append(SIGN);
            OutByteArray.append(e.item);
            OutByteArray.append(e.value);
        } else {
            if (e.value == 2) {
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
            } else {
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
            }
        }
    }

    //qDebug() << "Before:";
    //qDebug() << ByteArray;
    //qDebug() << "After:";
    //qDebug() << OutByteArray;


    QString ResultFilePath(FilePath);
    ResultFilePath.append(".rlemapa");
    QFile fileOut(ResultFilePath);
    if (!fileOut.open(QIODevice::WriteOnly))
        return;
    fileOut.write(OutByteArray);
    fileOut.close();
}

void RLE::Decompress(QString FilePath)
{
    QFile file(FilePath);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QByteArray ByteArray = file.readAll();
    file.close();

    quint8 SIGN = static_cast<quint8>(ByteArray.at(0));
    QByteArray OutByteArray;
    quint8 CurrentByte, ByteCounter;
    for (int i = 1; i < ByteArray.size(); i++) {
        CurrentByte = static_cast<quint8>(ByteArray.at(i));
        if (CurrentByte == SIGN) {
            i++;
            CurrentByte = static_cast<quint8>(ByteArray.at(i));
            i++;
            ByteCounter = static_cast<quint8>(ByteArray.at(i));
            for (quint8 j = 0; j < ByteCounter; j++) {
                OutByteArray.append(CurrentByte);
            }
            ByteCounter = 0;
        } else {
            OutByteArray.append(CurrentByte);
        }
    }

    //qDebug() << "Before:";
    //qDebug() << ByteArray;
    //qDebug() << "After:";
    //qDebug() << OutByteArray;


    QString ResultFilePath(FilePath);
    ResultFilePath.resize(FilePath.size()-8);
    ResultFilePath.append(".mapa");
    QFile fileOut(ResultFilePath);
    if (!fileOut.open(QIODevice::WriteOnly))
        return;
    fileOut.write(OutByteArray);
    fileOut.close();
}

