/********************************************************************************
** Form generated from reading UI file 'kompresjadanych.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KOMPRESJADANYCH_H
#define UI_KOMPRESJADANYCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KompresjaDanych
{
public:
    QAction *actionAdd;
    QAction *actionRemove;
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionInfo;
    QAction *actionCompress;
    QAction *actionDeCompress;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuCompression_Decompression_DAta;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *KompresjaDanych)
    {
        if (KompresjaDanych->objectName().isEmpty())
            KompresjaDanych->setObjectName(QStringLiteral("KompresjaDanych"));
        KompresjaDanych->resize(600, 400);
        actionAdd = new QAction(KompresjaDanych);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/graph/add204.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon);
        actionRemove = new QAction(KompresjaDanych);
        actionRemove->setObjectName(QStringLiteral("actionRemove"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/graph/round.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon1);
        actionExit = new QAction(KompresjaDanych);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setCheckable(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/graph/opened33.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionHelp = new QAction(KompresjaDanych);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/graph/question58.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon3);
        actionInfo = new QAction(KompresjaDanych);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/graph/info28.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon4);
        actionCompress = new QAction(KompresjaDanych);
        actionCompress->setObjectName(QStringLiteral("actionCompress"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/graph/four37.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompress->setIcon(icon5);
        actionDeCompress = new QAction(KompresjaDanych);
        actionDeCompress->setObjectName(QStringLiteral("actionDeCompress"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/graph/arrow480.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeCompress->setIcon(icon6);
        centralWidget = new QWidget(KompresjaDanych);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        KompresjaDanych->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KompresjaDanych);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        menuCompression_Decompression_DAta = new QMenu(menuBar);
        menuCompression_Decompression_DAta->setObjectName(QStringLiteral("menuCompression_Decompression_DAta"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        KompresjaDanych->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KompresjaDanych);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        KompresjaDanych->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuCompression_Decompression_DAta->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCompression_Decompression_DAta->addSeparator();
        menuCompression_Decompression_DAta->addAction(actionAdd);
        menuCompression_Decompression_DAta->addAction(actionRemove);
        menuCompression_Decompression_DAta->addSeparator();
        menuCompression_Decompression_DAta->addAction(actionExit);
        menuEdit->addAction(actionCompress);
        menuEdit->addAction(actionDeCompress);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionInfo);

        retranslateUi(KompresjaDanych);

        QMetaObject::connectSlotsByName(KompresjaDanych);
    } // setupUi

    void retranslateUi(QMainWindow *KompresjaDanych)
    {
        KompresjaDanych->setWindowTitle(QApplication::translate("KompresjaDanych", "KompresjaDanych", 0));
        actionAdd->setText(QApplication::translate("KompresjaDanych", "Add", 0));
        actionAdd->setShortcut(QApplication::translate("KompresjaDanych", "Ctrl+A", 0));
        actionRemove->setText(QApplication::translate("KompresjaDanych", "Remove", 0));
        actionRemove->setShortcut(QApplication::translate("KompresjaDanych", "Ctrl+R", 0));
        actionExit->setText(QApplication::translate("KompresjaDanych", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("KompresjaDanych", "Ctrl+Q", 0));
        actionHelp->setText(QApplication::translate("KompresjaDanych", "Help", 0));
        actionHelp->setShortcut(QApplication::translate("KompresjaDanych", "Ctrl+H", 0));
        actionInfo->setText(QApplication::translate("KompresjaDanych", "Info", 0));
#ifndef QT_NO_TOOLTIP
        actionInfo->setToolTip(QApplication::translate("KompresjaDanych", "Info", 0));
#endif // QT_NO_TOOLTIP
        actionInfo->setShortcut(QApplication::translate("KompresjaDanych", "Ctrl+I", 0));
        actionCompress->setText(QApplication::translate("KompresjaDanych", "Compress", 0));
        actionCompress->setShortcut(QApplication::translate("KompresjaDanych", "Ctrl+C", 0));
        actionDeCompress->setText(QApplication::translate("KompresjaDanych", "DeCompress", 0));
        actionDeCompress->setShortcut(QApplication::translate("KompresjaDanych", "Ctrl+D", 0));
        menuCompression_Decompression_DAta->setTitle(QApplication::translate("KompresjaDanych", "File", 0));
        menuEdit->setTitle(QApplication::translate("KompresjaDanych", "Action", 0));
        menuHelp->setTitle(QApplication::translate("KompresjaDanych", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class KompresjaDanych: public Ui_KompresjaDanych {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KOMPRESJADANYCH_H
