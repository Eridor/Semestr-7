#ifndef KOMPRESJADANYCH_H
#define KOMPRESJADANYCH_H

#include <QMainWindow>

namespace Ui {
class KompresjaDanych;
}

class KompresjaDanych : public QMainWindow
{
    Q_OBJECT

public:
    explicit KompresjaDanych(QWidget *parent = 0);
    ~KompresjaDanych();

private:
    Ui::KompresjaDanych *ui;
};

#endif // KOMPRESJADANYCH_H
