#include "helpform.h"
#include "ui_helpform.h"

/**
 * @brief HelpForm::HelpForm
 * @param parent
 */
HelpForm::HelpForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpForm)
{
    ui->setupUi(this);
}
/**
 * @brief HelpForm::~HelpForm
 */
HelpForm::~HelpForm()
{
    delete ui;
}
/**
 * @brief HelpForm::on_pushButton_Exit_clicked
 */
void HelpForm::on_pushButton_Exit_clicked()
{
    this->close();
}
