#include "kompresjadanych.h"
#include "ui_kompresjadanych.h"

KompresjaDanych::KompresjaDanych(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KompresjaDanych)
{
    ui->setupUi(this);
}

KompresjaDanych::~KompresjaDanych()
{
    delete ui;
}
