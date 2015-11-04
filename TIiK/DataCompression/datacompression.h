#ifndef DATACOMPRESSION_H
#define DATACOMPRESSION_H

#include <QMainWindow>
#include <QDebug>
#include <QSet>
#include <QStringList>
#include <QFileDialog>

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

private:
    Ui::DataCompression *ui;
    //Private variables
    QSet<QString> FileSet;

    //Private methods
    void FileChoose();
};

#endif // DATACOMPRESSION_H
