#ifndef DATACOMPRESSION_H
#define DATACOMPRESSION_H

#include <QMainWindow>
#include <QDebug>
#include <QSet>
#include <QStringList>
#include <QFileDialog>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>
#include <QPalette>
#include <QFont>
#include <QFileInfo>

#include "helpform.h"
#include "rle.h"
#include "imageviewer.h"
#include "audioviewer.h"

namespace Ui {
class DataCompression;
}

class DataCompression : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataCompression(QWidget *parent = 0);
    ~DataCompression();

private slots:
    void on_actionExit_triggered();

    void on_pushButton_Add_clicked();

    void on_actionAdd_triggered();

    void on_pushButton_Exit_clicked();

    void on_actionInfo_triggered();

    void on_pushButton_Info_clicked();

    void on_actionHelp_triggered();

    void on_pushButton_Help_clicked();

    void on_pushButton_Compression_clicked();

    void on_actionCompress_triggered();

    void on_pushButton_Decompression_clicked();

    void on_actionDecompress_triggered();

    void on_actionRemove_triggered();

    void on_tableView_FileList_doubleClicked(const QModelIndex &index);

private:
    Ui::DataCompression *ui;
    //Private variables
    QSet<QString> FileSet;
    QStandardItemModel *TableModel;

    //Private methods
    void FileChoose();
    void SetTable();
    void ShowInfo();
    void ShowHelp();
    void CompressData(QString val);
    void DeCompressData(QString val);
    void RemoveData(QString val);
    bool CheckData();
};

#endif // DATACOMPRESSION_H
