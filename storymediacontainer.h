#ifndef STORYMEDIACONTAINER_H
#define STORYMEDIACONTAINER_H

#include <vector>
#include <QString>
#include <QImage>
#include <QDebug>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
class StoryMediaContainer {
public:
    // Constructor
    StoryMediaContainer() = default;
    std::vector<QGraphicsScene*> pixmaps;
    std::vector<QString*> pageTexts;
    // Add an image with an optional caption
    void addMedia(const QImage &image);


    // Get image by index
    QImage getImage(int index);

    QString getPageTextByIndex(int index);
    // Get the total number of media items
    int getSize();

    QImage* scanImage(QString filepath);
    std::vector<QImage> images;
    std::vector<QString> pageText;
    void addQString(QString string);

private:


};

#endif  STORYMEDIACONTAINER
