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
    QStringList FilesList = QFileDialog::getOpenFileNames(this, "Select one, two, three, but not four, five or more files to compress",
                                              "/home/parys/PROJEKTY/Semestr-7/TIiK/TestData",
                                              "Images (*.bmp *.gif *.png *.raw *.tiff);;Audio (*.flac *.wav *.wma);;AllFiles (*.*)");

    if (FileSet.empty()) {
        FileSet = QSet<QString>::fromList(FilesList);
    } else {
        foreach (const QString &val, FilesList) {
            FileSet.insert(val);
        }
    }

    qDebug() << "Look: ";
    foreach (const QString &val, FileSet) {
        qDebug() << val;
    }
    SetTable();
}

void DataCompression::on_pushButton_Add_clicked()
{
    FileChoose();
}

void DataCompression::on_actionAdd_triggered()
{
    FileChoose();
}

void DataCompression::on_pushButton_Exit_clicked()
{
    QApplication::quit();
}

void DataCompression::SetTable()
{

}
