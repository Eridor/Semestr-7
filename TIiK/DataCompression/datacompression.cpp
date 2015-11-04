#include "datacompression.h"
#include "ui_datacompression.h"

DataCompression::DataCompression(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataCompression)
{
    ui->setupUi(this);
}

DataCompression::~DataCompression()
{
    delete ui;
}


void DataCompression::on_actionExit_triggered()
{
    QApplication::quit();
}


void DataCompression::FileChoose()
{
    QStringList FilesList;
    FilesList = QFileDialog::getOpenFileNames(this, "Select one, two, three, but not four, five or more files to compress",
                                              "/home/parys/PROJEKTY/Semestr-7/TIiK/TestData",
                                              "Images (*.bmp *.gif *.png *.raw *.tiff);;FAX (*.fax);;Audio(*.flac *.wav *.wma");

    FileSet += QSet<QString>::fromList(FilesList);

    qDebug() << "Look: ";
    foreach (const QString &val, FileSet) {
        qDebug() << val;
    }
}

void DataCompression::on_pushButton_Add_clicked()
{
    FileChoose();
}

void DataCompression::on_actionAdd_triggered()
{
    FileChoose();
}
