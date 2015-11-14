/********************************************************************************
** Form generated from reading UI file 'helpform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPFORM_H
#define UI_HELPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HelpForm
{
public:
    QPushButton *pushButton_Exit;
    QLabel *label_title;

    void setupUi(QDialog *HelpForm)
    {
        if (HelpForm->objectName().isEmpty())
            HelpForm->setObjectName(QStringLiteral("HelpForm"));
        HelpForm->resize(320, 240);
        pushButton_Exit = new QPushButton(HelpForm);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(290, 0, 30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/graph/opened33.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Exit->setIcon(icon);
        pushButton_Exit->setIconSize(QSize(24, 24));
        label_title = new QLabel(HelpForm);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(5, 0, 80, 40));

        retranslateUi(HelpForm);

        QMetaObject::connectSlotsByName(HelpForm);
    } // setupUi

    void retranslateUi(QDialog *HelpForm)
    {
        HelpForm->setWindowTitle(QApplication::translate("HelpForm", "Dialog", 0));
        pushButton_Exit->setText(QString());
        pushButton_Exit->setShortcut(QApplication::translate("HelpForm", "Ctrl+Q", 0));
        label_title->setText(QApplication::translate("HelpForm", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600;\">Help!</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class HelpForm: public Ui_HelpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPFORM_H
