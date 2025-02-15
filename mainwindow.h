#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <cstdlib>
#include <QGraphicsScene>
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QProcess>
#include "storymediacontainer.h"
#include "apicaller.h"
#include "apikeyconfigwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void nextImage();
    void prevImage();
    void nextText();
    void prevText();
    void updateImage();
    int vectorPos = 0;;
    int vectorLen = 0;

private slots:
    void on_sendButton_clicked();
    void onApiResponseReceived(QString response); // Slot to update UI
    void on_actionFile_triggered();
    void on_saveButton_clicked();
    void imageHandler(StoryMediaContainer &container);



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    ApiCaller *apiCaller; // Make ApiCaller persistent
    std::vector<QString> responses;
    std::vector<QString> prompts;
    ApiKeyConfigWindow *apiKeyConfigWindow;
    void clearResponseWindow();
    StoryMediaContainer mediaContainer; // Store images & text
    int currentIndex = 0;
    QGraphicsScene* scene;
};

#endif // MAINWINDOW_H


//cpp
/*
 * #include "enterapikeywindow.h"
#include "ui_enterapikeywindow.h"
#include <QLabel>
#include <QVBoxLayout>

enterAPIKeyWindow::enterAPIKeyWindow(QWidget *parent)
  : QWidget{parent}
{
    // Set up the new window layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *label = new QLabel("API Key config", this);
    layout->addWidget(label);

    setLayout(layout);
    setWindowTitle("API Key config");
}

/hpp
#ifndef ENTERAPIKEYWINDOW_H
#define ENTERAPIKEYWINDOW_H

#include <QWidget>
#include "ui_enterapikeywindow.h"
class enterAPIKeyWindow : public QWidget
{
    Q_OBJECT
public:
    explicit enterAPIKeyWindow(QWidget *parent = nullptr);
    QString getApiKey();
signals:
};

#endif // ENTERAPIKEYWINDOW_H
*/

