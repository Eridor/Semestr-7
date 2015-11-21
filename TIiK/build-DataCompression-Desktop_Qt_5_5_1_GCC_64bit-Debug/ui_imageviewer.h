/********************************************************************************
** Form generated from reading UI file 'imageviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_ImageViewer
{
public:
    QGraphicsView *graphicsView;
    QLabel *label;
    QSlider *horizontalSlider;
    QPushButton *pushButton_Exit;

    void setupUi(QDialog *ImageViewer)
    {
        if (ImageViewer->objectName().isEmpty())
            ImageViewer->setObjectName(QStringLiteral("ImageViewer"));
        ImageViewer->resize(400, 350);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageViewer->sizePolicy().hasHeightForWidth());
        ImageViewer->setSizePolicy(sizePolicy);
        ImageViewer->setMinimumSize(QSize(400, 350));
        ImageViewer->setMaximumSize(QSize(400, 350));
        graphicsView = new QGraphicsView(ImageViewer);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(5, 39, 390, 261));
        label = new QLabel(ImageViewer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, 5, 50, 30));
        horizontalSlider = new QSlider(ImageViewer);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(60, 5, 200, 30));
        horizontalSlider->setMinimum(-10);
        horizontalSlider->setMaximum(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton_Exit = new QPushButton(ImageViewer);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(365, 5, 30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/graph/opened33.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Exit->setIcon(icon);
        pushButton_Exit->setIconSize(QSize(25, 25));

        retranslateUi(ImageViewer);

        QMetaObject::connectSlotsByName(ImageViewer);
    } // setupUi

    void retranslateUi(QDialog *ImageViewer)
    {
        ImageViewer->setWindowTitle(QApplication::translate("ImageViewer", "Image Viewer", 0));
        label->setText(QApplication::translate("ImageViewer", "Scale:", 0));
        pushButton_Exit->setText(QString());
        pushButton_Exit->setShortcut(QApplication::translate("ImageViewer", "Ctrl+Q", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageViewer: public Ui_ImageViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
