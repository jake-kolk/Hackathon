/*#ifndef STORYMEDIACONTAINER_H
#define STORYMEDIACONTAINER_H

#include <QObject>
#include <QMediaPlayer>
#include <QUrl>
#include <QFileInfo>

class StoryMediaContainer : public QObject {
    Q_OBJECT

public:
    explicit StoryMediaContainer(QObject *parent = nullptr);
    ~StoryMediaContainer();

    bool loadMedia(const QString &filePath);
    void play();
    void pause();
    void stop();
    QString getFilePath() const;
    qint64 getDuration() const;

signals:
    void mediaLoaded();
    void mediaError(QString error);

private:
    QMediaPlayer *player;
    QString filePath;
};

#endif // STORYMEDIACONTAINER_H
*/
/*
//in main:
StoryMediaContainer mediaContainer;

QObject::connect(&mediaContainer, &StoryMediaContainer::mediaLoaded, []() {
    qDebug() << "Media loaded successfully!";
});

QObject::connect(&mediaContainer, &StoryMediaContainer::mediaError, [](QString error) {
    qDebug() << "Error: " << error;
});

QString filePath = "/path/to/audio.wav";  // Replace with actual path
if (mediaContainer.loadMedia(filePath)) {
    mediaContainer.play();
}
*/
