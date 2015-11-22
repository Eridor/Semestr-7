#include "audioviewer.h"
#include "ui_audioviewer.h"

AudioViewer::AudioViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AudioViewer)
{
    ui->setupUi(this);
    MusicVolume = -1;
    Play = false;
    NumStart = 0;
}

AudioViewer::~AudioViewer()
{
    if (MediaPlayer != NULL)
        MediaPlayer = NULL;

    delete ui;
}

void AudioViewer::on_pushButton_Exit_clicked()
{
    if (MediaPlayer != NULL) {
        MediaPlayer->stop();
    }
    this->close();
}

QString AudioViewer::getFilePath() const
{
    return FilePath;
}

void AudioViewer::setFilePath(const QString &value)
{
    FilePath = value;
}

void AudioViewer::on_pushButton_StartPause_clicked()
{
    PlayMusic();
}

void AudioViewer::on_pushButton_Stop_clicked()
{
    MediaPlayer->stop();
    Play = false;
    ui->pushButton_StartPause->setIcon( QIcon(":/graph/start3.png"));
}

void AudioViewer::on_horizontalSlider_valueChanged(int value)
{
    if (MediaPlayer != NULL) {
        MediaPlayer->setVolume(value);
    } else {
        MusicVolume = value;
    }
}

void AudioViewer::PlayMusic(int volume)
{
    if (MediaPlayer == NULL || NumStart == 0) {
        MediaPlayer = new QMediaPlayer;
        MediaPlayer->setMedia(QUrl::fromLocalFile(FilePath));

        if (MusicVolume == -1) {
            MediaPlayer->setVolume(volume);
        } else {
            MediaPlayer->setVolume(MusicVolume);
        }

        MediaPlayer->play();

        ui->pushButton_StartPause->setIcon( QIcon(":/graph/pause2.png"));
        Play = true;
        NumStart++;
    } else {
        if (Play) {
            MediaPlayer->pause();
            ui->pushButton_StartPause->setIcon( QIcon(":/graph/start3.png"));
            Play = false;
        } else {
            MediaPlayer->play();
            ui->pushButton_StartPause->setIcon( QIcon(":/graph/pause2.png"));
            Play = true;
        }
    }
}

