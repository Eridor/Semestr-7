#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T10:06:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataCompression
TEMPLATE = app


SOURCES += main.cpp\
        datacompression.cpp \
    helpform.cpp

HEADERS  += datacompression.h \
    helpform.h

FORMS    += datacompression.ui \
    helpform.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    DataCompression.pro.user
