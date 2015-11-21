#include "imageviewer.h"
#include "ui_imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageViewer)
{
    ui->setupUi(this);
}

ImageViewer::~ImageViewer()
{
    ui->graphicsView->close();
    delete ui;
}

QString ImageViewer::getFilePath() const
{
    return FilePath;
}

void ImageViewer::setFilePath(const QString &value)
{
    FilePath = value;
    SetImage();
}

void ImageViewer::on_pushButton_Exit_clicked()
{
    this->close();
}

void ImageViewer::SetImage(int scale)
{
    QImage image(FilePath);
    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    QPixmap Pixmap;
    if (scale == 0) {
        Pixmap = QPixmap::fromImage(image);
    } else if (scale < 0) {
        Pixmap = QPixmap::fromImage(image).scaledToHeight(static_cast<int>(image.height() * qPow(qFabs(scale), -1)));
    } else {
        Pixmap = QPixmap::fromImage(image).scaledToHeight((image.height()) * scale);
    }

    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(Pixmap);
    scene->addItem(item);
    ui->graphicsView->show();
}

void ImageViewer::on_horizontalSlider_valueChanged(int value)
{
    SetImage(value);
}
