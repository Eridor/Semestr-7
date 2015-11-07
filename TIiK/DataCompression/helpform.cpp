#include "helpform.h"
#include "ui_helpform.h"

HelpForm::HelpForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpForm)
{
    ui->setupUi(this);
}

HelpForm::~HelpForm()
{
    delete ui;
}

void HelpForm::on_pushButton_Exit_clicked()
{
    this->close();
}
