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
    QLabel *label_Text;

    void setupUi(QDialog *HelpForm)
    {
        if (HelpForm->objectName().isEmpty())
            HelpForm->setObjectName(QStringLiteral("HelpForm"));
        HelpForm->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HelpForm->sizePolicy().hasHeightForWidth());
        HelpForm->setSizePolicy(sizePolicy);
        HelpForm->setMinimumSize(QSize(400, 300));
        HelpForm->setMaximumSize(QSize(400, 300));
        pushButton_Exit = new QPushButton(HelpForm);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));
        pushButton_Exit->setGeometry(QRect(370, 0, 30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/graph/opened33.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Exit->setIcon(icon);
        pushButton_Exit->setIconSize(QSize(24, 24));
        label_title = new QLabel(HelpForm);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(5, 0, 80, 40));
        label_Text = new QLabel(HelpForm);
        label_Text->setObjectName(QStringLiteral("label_Text"));
        label_Text->setGeometry(QRect(5, 45, 390, 350));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(39);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Text->sizePolicy().hasHeightForWidth());
        label_Text->setSizePolicy(sizePolicy1);
        label_Text->setMinimumSize(QSize(390, 350));
        label_Text->setMaximumSize(QSize(390, 350));
        label_Text->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        retranslateUi(HelpForm);

        QMetaObject::connectSlotsByName(HelpForm);
    } // setupUi

    void retranslateUi(QDialog *HelpForm)
    {
        HelpForm->setWindowTitle(QApplication::translate("HelpForm", "Dialog", 0));
        pushButton_Exit->setText(QString());
        pushButton_Exit->setShortcut(QApplication::translate("HelpForm", "Ctrl+Q", 0));
        label_title->setText(QApplication::translate("HelpForm", "<html><head/><body><p><span style=\" font-size:20pt; font-weight:600;\">Help!</span></p></body></html>", 0));
        label_Text->setText(QApplication::translate("HelpForm", "<html><head/><body><p><span style=\" font-weight:600;\">How To Use Program?</span></p><p><span style=\" font-size:10pt;\">1. Seclect file / files for Compression / Decompression.</span></p><p><span style=\" font-size:10pt;\">2. Compress / Decompress file / files.</span></p><p><span style=\" font-size:10pt;\">3. Resoult file / files will appear in the same directory, as the selected file / files.</span></p><p><span style=\" font-weight:600;\">Key Shourtucts:</span></p><table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" cellspacing=\"2\" cellpadding=\"0\"><tr><td><p><span style=\" font-weight:600;\">ctrl</span>+<span style=\" font-weight:600;\">A</span></p></td><td><p>Add File</p></td><td><p><span style=\" font-weight:600;\">ctrl</span>+<span style=\" font-weight:600;\">R</span></p></td><td><p>Remove File</p></td></tr><tr><td><p><span style=\" font-weight:600;\">ctrl</span>+<span style=\" font-weight:600;\">Q</span></p></td><td><p>Compress</p></td><td><p><span sty"
                        "le=\" font-weight:600;\">ctrl</span>+<span style=\" font-weight:600;\">D</span></p></td><td><p>Decompress</p></td></tr><tr><td><p><span style=\" font-weight:600;\">ctrl</span>+<span style=\" font-weight:600;\">H</span></p></td><td><p>Show help</p></td><td><p><span style=\" font-weight:600;\">ctrl</span>+<span style=\" font-weight:600;\">I</span></p></td><td><p>Show Info</p></td></tr><tr><td><p><span style=\" font-weight:600;\">ctrl</span>+<span style=\" font-weight:600;\">Q</span></p></td><td><p>Exit program</p></td><td/><td/></tr></table><p><span style=\" font-weight:600;\">Authors:</span></p><table border=\"0\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px;\" width=\"410\" cellspacing=\"2\" cellpadding=\"0\"><tr><td><p><span style=\" font-weight:600;\">Micha\305\202 Majka:</span></p></td><td><p>112679</p></td><td><p><span style=\" font-weight:600;\">Piotr Parysek:</span></p></td><td><p>106100</p></td></tr></table></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class HelpForm: public Ui_HelpForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPFORM_H
