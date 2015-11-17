/********************************************************************************
** Form generated from reading UI file 'datacompression.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATACOMPRESSION_H
#define UI_DATACOMPRESSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataCompression
{
public:
    QAction *actionAdd;
    QAction *actionRemove;
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionInfo;
    QAction *actionCompress;
    QAction *actionDecompress;
    QWidget *centralWidget;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_Compression;
    QPushButton *pushButton_Decompression;
    QPushButton *pushButton_Exit;
    QTableView *tableView_FileList;
    QPushButton *pushButton_Info;
    QPushButton *pushButton_Help;
    QMenuBar *menuBar;
    QMenu *menuCompression_Decompression_DAta;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *DataCompression)
    {
        if (DataCompression->objectName().isEmpty())
            DataCompression->setObjectName(QStringLiteral("DataCompression"));
        DataCompression->setEnabled(true);
        DataCompression->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DataCompression->sizePolicy().hasHeightForWidth());
        DataCompression->setSizePolicy(sizePolicy);
        DataCompression->setMinimumSize(QSize(600, 400));
        DataCompression->setMaximumSize(QSize(600, 400));
        actionAdd = new QAction(DataCompression);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/graph/add204.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon);
        actionRemove = new QAction(DataCompression);
        actionRemove->setObjectName(QStringLiteral("actionRemove"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/graph/round.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon1);
        actionExit = new QAction(DataCompression);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionExit->setCheckable(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/graph/opened33.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionHelp = new QAction(DataCompression);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/graph/question58.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon3);
        actionInfo = new QAction(DataCompression);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/graph/info28.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon4);
        actionCompress = new QAction(DataCompression);
        actionCompress->setObjectName(QStringLiteral("actionCompress"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/graph/four37.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCompress->setIcon(icon5);
        actionDecompress = new QAction(DataCompression);
        actionDecompress->setObjectName(QStringLiteral("actionDecompress"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/graph/arrow480.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDecompress->setIcon(icon6);
        centralWidget = new QWidget(DataCompression);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_Add = new QPushButton(centralWidget);
        pushButton_Add->setObjectName(QStringLiteral("pushButton_Add"));
        pushButton_Add->setGeometry(QRect(10, 0, 361, 30));
        pushButton_Compression = new QPushButton(centralWidget);
        pushButton_Compression->setObjectName(QStringLiteral("pushButton_Compression"));
        pushButton_Compression->setGeometry(QRect(390, 40, 200, 30));
        pushButton_Decompression = new QPushButton(centralWidget);
        pushButton_Decompression->setObjectName(QStringLiteral("pushButton_Decompression"));
        pushButton_Decompression->setGeometry(QRect(390, 80, 200, 30));
        pushButton_Exit = new QPushButton(centralWidget);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(560, 0, 30, 30));
        pushButton_Exit->setIcon(icon2);
        pushButton_Exit->setIconSize(QSize(24, 24));
        tableView_FileList = new QTableView(centralWidget);
        tableView_FileList->setObjectName(QStringLiteral("tableView_FileList"));
        tableView_FileList->setGeometry(QRect(10, 41, 360, 311));
        tableView_FileList->setMaximumSize(QSize(360, 500));
        tableView_FileList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableView_FileList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableView_FileList->setDragEnabled(true);
        tableView_FileList->horizontalHeader()->setDefaultSectionSize(300);
        tableView_FileList->horizontalHeader()->setMinimumSectionSize(250);
        pushButton_Info = new QPushButton(centralWidget);
        pushButton_Info->setObjectName(QStringLiteral("pushButton_Info"));
        pushButton_Info->setGeometry(QRect(520, 0, 30, 30));
        pushButton_Info->setIcon(icon4);
        pushButton_Info->setIconSize(QSize(24, 24));
        pushButton_Help = new QPushButton(centralWidget);
        pushButton_Help->setObjectName(QStringLiteral("pushButton_Help"));
        pushButton_Help->setGeometry(QRect(485, 0, 30, 30));
        pushButton_Help->setIcon(icon3);
        pushButton_Help->setIconSize(QSize(24, 24));
        DataCompression->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DataCompression);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 25));
        menuCompression_Decompression_DAta = new QMenu(menuBar);
        menuCompression_Decompression_DAta->setObjectName(QStringLiteral("menuCompression_Decompression_DAta"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        DataCompression->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DataCompression);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DataCompression->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuCompression_Decompression_DAta->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuCompression_Decompression_DAta->addSeparator();
        menuCompression_Decompression_DAta->addAction(actionAdd);
        menuCompression_Decompression_DAta->addAction(actionRemove);
        menuCompression_Decompression_DAta->addSeparator();
        menuCompression_Decompression_DAta->addAction(actionExit);
        menuEdit->addAction(actionCompress);
        menuEdit->addAction(actionDecompress);
        menuHelp->addAction(actionHelp);
        menuHelp->addAction(actionInfo);

        retranslateUi(DataCompression);

        QMetaObject::connectSlotsByName(DataCompression);
    } // setupUi

    void retranslateUi(QMainWindow *DataCompression)
    {
        DataCompression->setWindowTitle(QApplication::translate("DataCompression", "Data Compression", 0));
        actionAdd->setText(QApplication::translate("DataCompression", "Add", 0));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("DataCompression", "Add file / files", 0));
#endif // QT_NO_TOOLTIP
        actionAdd->setShortcut(QApplication::translate("DataCompression", "Ctrl+A", 0));
        actionRemove->setText(QApplication::translate("DataCompression", "Remove", 0));
#ifndef QT_NO_TOOLTIP
        actionRemove->setToolTip(QApplication::translate("DataCompression", "Remove selected file", 0));
#endif // QT_NO_TOOLTIP
        actionRemove->setShortcut(QApplication::translate("DataCompression", "Ctrl+R", 0));
        actionExit->setText(QApplication::translate("DataCompression", "Exit", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("DataCompression", "Exit program", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("DataCompression", "Ctrl+Q", 0));
        actionHelp->setText(QApplication::translate("DataCompression", "Help", 0));
#ifndef QT_NO_TOOLTIP
        actionHelp->setToolTip(QApplication::translate("DataCompression", "Show help", 0));
#endif // QT_NO_TOOLTIP
        actionHelp->setShortcut(QApplication::translate("DataCompression", "Ctrl+H", 0));
        actionInfo->setText(QApplication::translate("DataCompression", "Info", 0));
#ifndef QT_NO_TOOLTIP
        actionInfo->setToolTip(QApplication::translate("DataCompression", "Show informations about project", 0));
#endif // QT_NO_TOOLTIP
        actionInfo->setShortcut(QApplication::translate("DataCompression", "Ctrl+I", 0));
        actionCompress->setText(QApplication::translate("DataCompression", "Compress", 0));
#ifndef QT_NO_TOOLTIP
        actionCompress->setToolTip(QApplication::translate("DataCompression", "Compress file / files", 0));
#endif // QT_NO_TOOLTIP
        actionCompress->setShortcut(QApplication::translate("DataCompression", "Ctrl+C", 0));
        actionDecompress->setText(QApplication::translate("DataCompression", "Decompress", 0));
#ifndef QT_NO_TOOLTIP
        actionDecompress->setToolTip(QApplication::translate("DataCompression", "Decompress file / Files", 0));
#endif // QT_NO_TOOLTIP
        actionDecompress->setShortcut(QApplication::translate("DataCompression", "Ctrl+D", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Add->setToolTip(QApplication::translate("DataCompression", "<html><head/><body><p>Add file / files to Compress / Decompress</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Add->setText(QApplication::translate("DataCompression", "Add files", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Compression->setToolTip(QApplication::translate("DataCompression", "<html><head/><body><p>Compress file / files</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Compression->setText(QApplication::translate("DataCompression", "Compress", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Decompression->setToolTip(QApplication::translate("DataCompression", "<html><head/><body><p>Decompress file / files</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Decompression->setText(QApplication::translate("DataCompression", "Decomperss", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_Exit->setToolTip(QApplication::translate("DataCompression", "<html><head/><body><p>Exit program</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Exit->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Info->setToolTip(QApplication::translate("DataCompression", "<html><head/><body><p>Show information about program</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Info->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButton_Help->setToolTip(QApplication::translate("DataCompression", "<html><head/><body><p>Show help</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButton_Help->setText(QString());
        menuCompression_Decompression_DAta->setTitle(QApplication::translate("DataCompression", "File", 0));
        menuEdit->setTitle(QApplication::translate("DataCompression", "Action", 0));
        menuHelp->setTitle(QApplication::translate("DataCompression", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class DataCompression: public Ui_DataCompression {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATACOMPRESSION_H
