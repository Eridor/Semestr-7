#include "kompresjadanych.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KompresjaDanych w;
    w.show();

    return a.exec();
}
