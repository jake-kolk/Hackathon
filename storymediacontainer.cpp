#include "storymediacontainer.h"

void StoryMediaContainer::addMedia(const QImage &image) {
    images.push_back(image);
 }

    // Get image by index
QImage StoryMediaContainer::getImage(int index) {
    if (index >= 0 && index < images.size()) {
        return images[index];
    }
    return QImage(); // Return an empty QImage if index is invalid
}

    // Get the total number of media items
int StoryMediaContainer::StoryMediaContainer::getSize()
{
    return images.size();
}

QString StoryMediaContainer::getPageTextByIndex(int index)
{
    if(this->pageText.size() > index && index >= 0)
    {
        return this->pageText[index];
    }
    else return QString("");
}
QImage* StoryMediaContainer::scanImage(QString filepath)
{
    QImage* image = new QImage;
    if(!image->load(filepath))
    {
        qDebug() << "Image failed to scan!";
    }
    return image;
}

void StoryMediaContainer::addQString(QString inputString){
    this->pageText.push_back(inputString);
    return;
}
