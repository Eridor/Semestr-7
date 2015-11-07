#include "rle.h"

RLE::RLE()
{

}

void RLE::Compress(QString FilePath)
{
    QFile file(FilePath);
    if (!file.open(QIODevice::ReadOnly))
        return;
    QByteArray blob = file.readAll();

    QMap<quint8, int> mapa;

    for (int i = 0; i < 257; ++i) {
        mapa.insert((short) i, 0);
    }


    QMap<quint8, int>::iterator it;
    for(it = mapa.begin(); it != mapa.end(); ++it)
    {
        quint8 Qtemp = it.key();
        it.value() = blob.count(Qtemp);
    }
}
