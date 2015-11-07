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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HelpForm
{
public:
    QPushButton *pushButton_Exit;

    void setupUi(QDialog *HelpForm)
    {
        if (HelpForm->objectName().isEmpty())
            HelpForm->setObjectName(QStringLiteral("HelpForm"));
        HelpForm->resize(320, 240);
        pushButton_Exit = new QPushButton(HelpForm);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(0, 0, 30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/graph/opened33.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Exit->setIcon(icon);
        pushButton_Exit->setIconSize(QSize(24, 24));

        retranslateUi(HelpForm);

        QMetaObject::connectSlotsByName(HelpForm);
    } // setupUi

    void retranslateUi(QDialog *HelpForm)
    {
        HelpForm->setWindowTitle(QApplication::translate("HelpForm", "Dialog", 0));
        pushButton_Exit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HelpForm: public Ui_HelpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPFORM_H
