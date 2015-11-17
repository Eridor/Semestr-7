#include "rle.h"
/**
 * @brief RLE::RLE Unused class constructor
 */
RLE::RLE()
{

}
/**
 * @brief RLE::Compress
 * @param FilePath
 * @return
 */
bool RLE::Compress(QString FilePath)
{
    //Open & Read File
    QFile file(FilePath);
    if (!file.open(QIODevice::ReadOnly))
        return false;
    QByteArray ByteArray = file.readAll();
    file.close();

    //Find 8 bit SIGN
    QMap<quint8, int> IIMap;
    for (quint8 i = 0; i < 255; i++) {
        IIMap.insert(i, 0);
    }
    QMap<quint8, int>::iterator it;
    for(it = IIMap.begin(); it != IIMap.end(); ++it) {
        it.value() = ByteArray.count(static_cast<char>(it.key()));
    }
    quint8 SIGN = 0;
    for(it = IIMap.begin(); it != IIMap.end(); ++it) {
        if (it.value() == 0) {
            SIGN = it.key();
            break;
        }
    }
    IIMap.clear(); //Clear Map

    //IF SIGN exists then compress file else find 16 bit SIGN and compress
    if (SIGN != 0) {
        //QByteArray for output elements
        QByteArray OutByteArray;
        //Add to file size of SIGN (in bytes) and SIGN
        OutByteArray.append(static_cast<char>(1));
        OutByteArray.append(static_cast<char>(SIGN));

        //Create list of Bytes with their repetition
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

        //Write List to OutputByteList
        foreach (Element e, Elements) {
            if (e.value == 1) {
                OutByteArray.append(e.item);
            } else if (e.value == 2) {
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
            } else if (e.value == 3) {
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
            } else {
                if (e.value < 256) {
                    OutByteArray.append(SIGN);
                    OutByteArray.append(e.item);
                    OutByteArray.append(e.value);
                } else {
                    OutByteArray.append(SIGN);
                    OutByteArray.append(SIGN);
                    OutByteArray.append(SIGN);
                    OutByteArray.append(SIGN);
                    OutByteArray.append(e.item);
                    QByteArray TempArray;
                    TempArray = RLE::IntToHex(e.value);
                    OutByteArray.append(TempArray);
                }
            }
        }

        //Save to file and return
        QString ResultFilePath(FilePath);
        ResultFilePath.append(".rlemapa");
        QFile fileOut(ResultFilePath);
        if (!fileOut.open(QIODevice::WriteOnly))
            return false;
        fileOut.write(OutByteArray);
        fileOut.close();

        //Clear All data
        OutByteArray.clear();
        ByteArray.clear();
        Elements.clear();

        //All ended successfully
        return true;

    } else {
    //SIGN have to be 16 bit
        //16 bit SIGN
        QPair<quint8, quint8> SIGN16;
        QSet< QPair<quint8, quint8> > IISet;
        for (int i = 0; i < ByteArray.size()-1; ++i) {
            IISet.insert(QPair<quint8, quint8>(ByteArray.at(i), ByteArray.at(i+1)));
        }

        //To create random int
        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());
        SIGN16.first  = qrand()%256;
        SIGN16.second = qrand()%256;
        while (IISet.contains(SIGN16)) {
            SIGN16.first  = qrand()%256;
            SIGN16.second = qrand()%256;
        }
        IISet.clear();

        //QByteArray for output elements
        QByteArray OutByteArray;
        OutByteArray.append(static_cast<char>(2));
        OutByteArray.append(static_cast<char>(SIGN16.first));
        OutByteArray.append(static_cast<char>(SIGN16.second));

        //Create list of Bytes with their repetition
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

        //Write List to OutputByteList
        foreach (Element e, Elements) {
            if (e.value == 1) {
                OutByteArray.append(e.item);
            } else if (e.value == 2) {
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
            } else if (e.value == 3) {
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
            } else if (e.value == 4) {
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
                OutByteArray.append(e.item);
            } else {
                if (e.value < 256) {
                    OutByteArray.append(SIGN16.first);
                    OutByteArray.append(SIGN16.second);
                    OutByteArray.append(e.item);
                    OutByteArray.append(e.value);
                } else {
                    OutByteArray.append(SIGN16.first);
                    OutByteArray.append(SIGN16.second);
                    OutByteArray.append(SIGN16.first);
                    OutByteArray.append(SIGN16.second);
                    OutByteArray.append(e.item);
                    QByteArray TempArray;
                    TempArray = RLE::IntToHex(e.value);
                    OutByteArray.append(TempArray);
                }
            }
        }

        //Save to file and return
        QString ResultFilePath(FilePath);
        ResultFilePath.append(".rlemapa");
        QFile fileOut(ResultFilePath);
        if (!fileOut.open(QIODevice::WriteOnly))
            return false;
        fileOut.write(OutByteArray);
        fileOut.close();

        //Clear All data
        OutByteArray.clear();
        ByteArray.clear();
        Elements.clear();

        //All ended successfully
        return true;
    }

    //Something went wrong
    return false;
}
/**
 * @brief RLE::Decompress
 * @param FilePath
 * @return
 */
bool RLE::Decompress(QString FilePath)
{
    //Open and read file
    QFile file(FilePath);
    if (!file.open(QIODevice::ReadOnly))
        return false;
    QByteArray ByteArray = file.readAll();
    file.close();

    //Read the SIGNSIZE
    quint8 SIGNSIZE = static_cast<quint8>(ByteArray.at(0));
    if (SIGNSIZE == 1) {
        //SIGN is one quint8
        quint8 SIGN = static_cast<quint8>(ByteArray.at(1));

        //Process file
        QByteArray OutByteArray;
        quint8 CurrentByte, ByteCounter;
        for (int i = 2; i < ByteArray.size(); i++) {
            CurrentByte = static_cast<quint8>(ByteArray.at(i));
            if (CurrentByte == SIGN) {
                i++;
                CurrentByte = static_cast<quint8>(ByteArray.at(i));
                if (CurrentByte == SIGN) {
                    i += 3;
                    CurrentByte = static_cast<quint8>(ByteArray.at(i));
                    i++;
                    QByteArray TempArray;
                    TempArray.append(ByteArray.at(i));
                    TempArray.append(ByteArray.at(i+1));
                    TempArray.append(ByteArray.at(i+2));
                    TempArray.append(ByteArray.at(i+3));
                    quint32 Counter = RLE::HexToInt(TempArray);
                    for (quint32 var = 0; var < Counter; ++var) {
                        OutByteArray.append(CurrentByte);
                    }
                } else {
                    i++;
                    ByteCounter = static_cast<quint8>(ByteArray.at(i));
                    for (quint8 j = 0; j < ByteCounter; j++) {
                        OutByteArray.append(CurrentByte);
                    }
                    ByteCounter = 0;
                }
            } else {
                OutByteArray.append(CurrentByte);
            }
        }

        //Save file - exit
        QString ResultFilePath(FilePath);
        ResultFilePath.resize(FilePath.size()-8);
        ResultFilePath.insert(ResultFilePath.lastIndexOf("."), "_2");


        //qDebug() << "File: " << ResultFilePath;
        //ResultFilePath.append(".mapa");
        QFile fileOut(ResultFilePath);
        if (!fileOut.open(QIODevice::WriteOnly))
            return false;
        fileOut.write(OutByteArray);
        fileOut.close();

        //Clear all
        OutByteArray.clear();

        //All succedded
        return true;
    } else if (SIGNSIZE == 2) {
        //SIGN is quint16 or two quint8
        QPair<quint8, quint8> SIGN16;
        SIGN16.first  = static_cast<quint8>(ByteArray.at(1));
        SIGN16.second = static_cast<quint8>(ByteArray.at(2));

        QByteArray OutByteArray;
        quint8 CurrentByte, NextByte, ByteCounter;
        for (int i = 3; i < ByteArray.size()-1; i++) {
            CurrentByte = static_cast<quint8>(ByteArray.at(i));
            NextByte    = static_cast<quint8>(ByteArray.at(i+1));
            if ((CurrentByte == SIGN16.first) && (NextByte == SIGN16.second)) {
                if ((SIGN16.first == static_cast<quint8>(ByteArray.at(i+2))) && (SIGN16.second == static_cast<quint8>(ByteArray.at(i+3)))) {
                    i += 4;
                    CurrentByte = static_cast<quint8>(ByteArray.at(i));
                    i++;
                    QByteArray TempArray;
                    TempArray.append(ByteArray.at(i));
                    TempArray.append(ByteArray.at(i+1));
                    TempArray.append(ByteArray.at(i+2));
                    TempArray.append(ByteArray.at(i+3));
                    quint32 Counter = RLE::HexToInt(TempArray);
                    for (quint32 var = 0; var < Counter; ++var) {
                        OutByteArray.append(CurrentByte);
                    }
                    i += 3;
                } else {
                    i += 2;
                    CurrentByte = static_cast<quint8>(ByteArray.at(i));
                    i++;
                    ByteCounter = static_cast<quint8>(ByteArray.at(i));
                    for (quint8 var = 0; var < ByteCounter; var++) {
                        OutByteArray.append(CurrentByte);
                    }
                    ByteCounter = 0;
                }
            } else {
                OutByteArray.append(CurrentByte);
            }
        }

        //Save file - exit
        QString ResultFilePath(FilePath);
        ResultFilePath.resize(FilePath.size()-8);
        ResultFilePath.insert(ResultFilePath.lastIndexOf("."), "_2");
        //qDebug() << "File: " << ResultFilePath;
        //ResultFilePath.append(".mapa");
        QFile fileOut(ResultFilePath);
        if (!fileOut.open(QIODevice::WriteOnly))
            return false;
        fileOut.write(OutByteArray);
        fileOut.close();

        //Clear all
        OutByteArray.clear();

        //All succedded
        return true;
    } else {
        //ERROR Wrong File or wrong byte read
        qDebug() << "DECOMPRESS ERROR! - " << FilePath;
        qDebug() << ByteArray;
        qDebug() << "END";
        return false;
    }

    //If not executed -> Wrong resoult => FALSE
    return false;
}
/**
 * @brief RLE::HexToInt
 * @param B
 * @return
 */
quint32 RLE::HexToInt(QByteArray B)
{
    quint32 Res = 0;
    Res |= (static_cast<unsigned char>(B.at(0)) << 24);
    Res |= (static_cast<unsigned char>(B.at(1)) << 16);
    Res |= (static_cast<unsigned char>(B.at(2)) << 8);
    Res |= static_cast<unsigned char>(B.at(3));
    return Res;
}
/**
 * @brief RLE::IntToHex
 * @param Num
 * @return
 */
QByteArray RLE::IntToHex(quint32 Num)
{
    QByteArray Temp;
    std::vector<unsigned char> arrayOfByte(4);
    for (int i = 0; i < 4; i++)
        arrayOfByte[3 - i] = (Num >> (i * 8));
    //for (int i = 0; i < arrayOfByte.size(); ++i)
    //    qDebug() << arrayOfByte[i];
    for (int i = 0; i < arrayOfByte.size(); ++i)
        Temp.append(arrayOfByte[i]);
    return Temp;
}
