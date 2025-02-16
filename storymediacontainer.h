#ifndef STORYMEDIACONTAINER_H
#define STORYMEDIACONTAINER_H

#include <QDebug>
#include <QImage>
#include <QString>
#include <vector>
class StoryMediaContainer
{
public:
    // Constructor
    StoryMediaContainer() = default;

    // Add an image with an optional caption
    void addMedia(const QImage &image);

    // Get image by index
    QImage getImage(int index);

    QString getPageTextByIndex(int index);
    // Get the total number of media items
    int getSize();

    QImage *scanImage(QString filepath);

    void addQString(QString string);

private:
    std::vector<QImage> images;
    std::vector<QString> pageText;
};

#endif STORYMEDIACONTAINER
