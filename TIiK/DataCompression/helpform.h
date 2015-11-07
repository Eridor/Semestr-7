#ifndef HELPFORM_H
#define HELPFORM_H

#include <QDialog>
#include <QDialog>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class HelpForm;
}

class HelpForm : public QDialog
{
    Q_OBJECT

public:
    explicit HelpForm(QWidget *parent = 0);
    ~HelpForm();

private slots:
    void on_pushButton_Exit_clicked();

private:
    Ui::HelpForm *ui;
};

#endif // HELPFORM_H
