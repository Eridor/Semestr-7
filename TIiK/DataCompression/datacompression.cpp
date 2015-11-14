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
    QStringList FilesList = QFileDialog::getOpenFileNames(this, "Select one or more files",
                                              "/home/parys/PROJEKTY/Semestr-7/TIiK/TestData",
                                              "To Compress (*.bmp *.gif *.png *.raw *.tiff *.flac *.wav *.wma);;To Decompress (*.rlemapa);;AllFiles (*.*)");

    if (FileSet.empty()) {
        FileSet = QSet<QString>::fromList(FilesList);
    } else {
        foreach (const QString &val, FilesList) {
            FileSet.insert(val);
        }
    }

    //qDebug() << "Look: ";
    //foreach (const QString &val, FileSet) {
    //    qDebug() << val;
    //}
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
        if (val.contains(".rlemapa", Qt::CaseInsensitive)) {
            QColor rowColor = Qt::lightGray;
            item1->setData(rowColor, Qt::BackgroundRole);
        } else {
            QColor rowColor = Qt::green;
            item1->setData(rowColor, Qt::BackgroundRole);
        }
        TableModel->setItem(i, 0, item1);
        i++;
    }

    ui->tableView_FileList->setVisible(false);
    ui->tableView_FileList->setModel(TableModel);
    ui->tableView_FileList->setColumnWidth(0, ui->tableView_FileList->width());
    ui->tableView_FileList->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView_FileList->setVisible(true);
}

void DataCompression::RemoveData(QString val)
{
    FileSet.remove(val);
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
    if (CheckData()) {
        foreach (const QString &val, FileSet)
        {
            CompressData(val);
        }
    } else {
        QMessageBox::critical(this, "ERROR", "ERROR WRONG DATA!");
    }
}

void DataCompression::on_actionCompress_triggered()
{
    if (CheckData()) {
        foreach (const QString &val, FileSet)
        {
            CompressData(val);
        }
    } else {
        QMessageBox::critical(this, "ERROR", "ERROR WRONG DATA!");
    }
}

void DataCompression::CompressData(QString val)
{
    if (RLE::Compress(val))
        RemoveData(val);
    SetTable();
}

void DataCompression::on_pushButton_Decompression_clicked()
{
    if (CheckData()) {
        foreach (const QString &val, FileSet)
        {
            DeCompressData(val);
        }
    } else {
        QMessageBox::critical(this, "ERROR", "ERROR WRONG DATA!");
    }
}

void DataCompression::on_actionDecompress_triggered()
{
    if (CheckData()) {
        foreach (const QString &val, FileSet)
        {
            DeCompressData(val);
        }
    } else {
        QMessageBox::critical(this, "ERROR", "ERROR WRONG DATA!");
    }    
}

void DataCompression::DeCompressData(QString val)
{
    if (RLE::Decompress(val))
        RemoveData(val);
    SetTable();
}

bool DataCompression::CheckData()
{
    bool Data = false, DataCompres = false;
    foreach (const QString &val, FileSet) {
        if (val.contains(".rlemapa")) {
            DataCompres = true;
        } else if (!val.contains(".rlemapa")) {
            Data = true;
        }
    }
    return ((Data && !DataCompres) || (!Data && DataCompres));
}

void DataCompression::on_actionRemove_triggered()
{
    QString TempPath = "/home/parys/PROJEKTY/Semestr-7/";
    QItemSelection selection(ui->tableView_FileList->selectionModel()->selection());
    if (!selection.empty()) {
        foreach (const QModelIndex &in, selection.indexes()) {

            QString Dane = ui->tableView_FileList->model()->data(in).toString();
            FileSet.remove(Dane.prepend(TempPath));
            //ui->tableView_FileList->model()->removeRow(in.row());
            SetTable();
        }
    } else {
        QMessageBox::critical(this, "No data selected!", "To remove row, you have to select one to remove!!");
    }
}

