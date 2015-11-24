/********************************************************************************
** Form generated from reading UI file 'audioviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOVIEWER_H
#define UI_AUDIOVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_AudioViewer
{
public:
    QPushButton *pushButton_Exit;
    QLabel *label_Title;
    QPushButton *pushButton_StartPause;
    QPushButton *pushButton_Stop;
    QSlider *horizontalSlider;
    QLabel *label_Volume;

    void setupUi(QDialog *AudioViewer)
    {
        if (AudioViewer->objectName().isEmpty())
            AudioViewer->setObjectName(QStringLiteral("AudioViewer"));
        AudioViewer->resize(250, 90);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AudioViewer->sizePolicy().hasHeightForWidth());
        AudioViewer->setSizePolicy(sizePolicy);
        AudioViewer->setMinimumSize(QSize(250, 90));
        AudioViewer->setMaximumSize(QSize(250, 90));
        pushButton_Exit = new QPushButton(AudioViewer);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(215, 5, 30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/graph/opened33.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Exit->setIcon(icon);
        pushButton_Exit->setIconSize(QSize(25, 25));
        label_Title = new QLabel(AudioViewer);
        label_Title->setObjectName(QStringLiteral("label_Title"));
        label_Title->setGeometry(QRect(5, 5, 125, 30));
        pushButton_StartPause = new QPushButton(AudioViewer);
        pushButton_StartPause->setObjectName(QStringLiteral("pushButton_StartPause"));
        pushButton_StartPause->setGeometry(QRect(5, 45, 35, 35));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/graph/start3.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_StartPause->setIcon(icon1);
        pushButton_StartPause->setIconSize(QSize(32, 32));
        pushButton_Stop = new QPushButton(AudioViewer);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));
        pushButton_Stop->setGeometry(QRect(45, 45, 35, 35));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/graph/stop7.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Stop->setIcon(icon2);
        pushButton_Stop->setIconSize(QSize(32, 32));
        horizontalSlider = new QSlider(AudioViewer);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(85, 50, 150, 30));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_Volume = new QLabel(AudioViewer);
        label_Volume->setObjectName(QStringLiteral("label_Volume"));
        label_Volume->setGeometry(QRect(125, 35, 65, 20));
#ifndef QT_NO_SHORTCUT
        label_Title->setBuddy(pushButton_Exit);
#endif // QT_NO_SHORTCUT

        retranslateUi(AudioViewer);

        QMetaObject::connectSlotsByName(AudioViewer);
    } // setupUi

    void retranslateUi(QDialog *AudioViewer)
    {
        AudioViewer->setWindowTitle(QApplication::translate("AudioViewer", "Audio Viewer", 0));
        pushButton_Exit->setText(QString());
        pushButton_Exit->setShortcut(QApplication::translate("AudioViewer", "Ctrl+Q", 0));
        label_Title->setText(QApplication::translate("AudioViewer", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Audio Tester</span></p></body></html>", 0));
        pushButton_StartPause->setText(QString());
        pushButton_Stop->setText(QString());
        label_Volume->setText(QApplication::translate("AudioViewer", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Volume</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AudioViewer: public Ui_AudioViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOVIEWER_H
