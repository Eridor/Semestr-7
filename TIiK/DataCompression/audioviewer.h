#ifndef AUDIOVIEWER_H
#define AUDIOVIEWER_H

#include <QDialog>
#include <QImage>
#include <QMediaPlayer>

namespace Ui {
class AudioViewer;
}

class AudioViewer : public QDialog
{
    Q_OBJECT

public:
    explicit AudioViewer(QWidget *parent = 0);
    ~AudioViewer();

    QString getFilePath() const;
    void setFilePath(const QString &value);

private slots:
    void on_pushButton_Exit_clicked();

    void on_pushButton_StartPause_clicked();

    void on_pushButton_Stop_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::AudioViewer *ui;
    QString FilePath;
    bool Play;
    int MusicVolume;
    QMediaPlayer *MediaPlayer;

    void PlayMusic(int volume = 50);
};

#endif // AUDIOVIEWER_H
