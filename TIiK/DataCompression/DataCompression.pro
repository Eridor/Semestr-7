#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T10:06:54
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataCompression
TEMPLATE = app


SOURCES += main.cpp\
        datacompression.cpp \
    helpform.cpp \
    rle.cpp \
    imageviewer.cpp \
    audioviewer.cpp

HEADERS  += datacompression.h \
    helpform.h \
    rle.h \
    imageviewer.h \
    audioviewer.h

FORMS    += datacompression.ui \
    helpform.ui \
    imageviewer.ui \
    audioviewer.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    DataCompression.pro.user
