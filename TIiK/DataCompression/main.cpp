#include "datacompression.h"
#include <QApplication>
/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataCompression w;
    w.show();

    return a.exec();
}
