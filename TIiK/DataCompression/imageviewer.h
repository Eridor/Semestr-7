#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QDebug>
#include <QDialog>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QtMath>

namespace Ui {
class ImageViewer;
}

class ImageViewer : public QDialog
{
    Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = 0);
    ~ImageViewer();

    QString getFilePath() const;
    void setFilePath(const QString &value);

private slots:
    void on_pushButton_Exit_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::ImageViewer *ui;
    QString FilePath;

    void SetImage(int scale = 0);
};

#endif // IMAGEVIEWER_H
