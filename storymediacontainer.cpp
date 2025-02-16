//#include "storymediacontainer.h"
//#include "StoryMediaContainer.h"
/*
StoryMediaContainer::StoryMediaContainer(QObject *parent)
    : QObject(parent), player(new QMediaPlayer(this)) {
    connect(player, &QMediaPlayer::mediaStatusChanged, this, [this](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::LoadedMedia) {
            emit mediaLoaded();
        }
    });

    connect(player, &QMediaPlayer::errorOccurred, this, [this]() {
        emit mediaError(player->errorString());
    });
}

StoryMediaContainer::~StoryMediaContainer() {
    delete player;
}

bool StoryMediaContainer::loadMedia(const QString &filePath) {
    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists() || fileInfo.suffix().toLower() != "wav") {
        emit mediaError("Invalid file or file does not exist.");
        return false;
    }

    this->filePath = filePath;
    player->setSource(QUrl::fromLocalFile(filePath));
    return true;
}

void StoryMediaContainer::play() {
    if (player->source().isEmpty()) return;
    player->play();
}

void StoryMediaContainer::pause() {
    player->pause();
}

void StoryMediaContainer::stop() {
    player->stop();
}

QString StoryMediaContainer::getFilePath() const {
    return filePath;
}

qint64 StoryMediaContainer::getDuration() const {
    return player->duration();
}
*/
