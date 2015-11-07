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
    ui->tableView_FileList->setModel(NULL);

    TableModel = NULL;
    TableModel = new QStandardItemModel(FileSet.size(), 1);
    TableModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Path")));

    QString TempPath = "/home/parys/PROJEKTY/Semestr-7/";
    int i = 0;
    foreach (const QString &val, FileSet) {
        QStandardItem *item1 = new QStandardItem(val.mid(TempPath.size()));
        TableModel->setItem(i, 0, item1);
        i++;
    }

    ui->tableView_FileList->setVisible(false);
    ui->tableView_FileList->setModel(TableModel);
    ui->tableView_FileList->setColumnWidth(0, this->width());
    ui->tableView_FileList->setVisible(true);
}

void DataCompression::on_actionInfo_triggered()
{
    ShowInfo();
}

void DataCompression::on_pushButton_Info_clicked()
{
    ShowInfo();
}

void DataCompression::ShowInfo()
{
    QMessageBox::information(this, "Authors", "Michał Majka: 112679\nPiotr Parysek: 106100\nProject created in QT 5.5");
}

void DataCompression::on_actionHelp_triggered()
{
    ShowHelp();
}

void DataCompression::on_pushButton_Help_clicked()
{
    ShowHelp();
}

void DataCompression::ShowHelp()
{
    HelpForm HF;
    HF.setModal(true);
    HF.exec();
}

void DataCompression::on_pushButton_Compression_clicked()
{
    RLE r;
    foreach (const QString &val, FileSet) {
        r.Compress(val);
    }
}
