#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <cstdlib>
#include <iostream>
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

private slots:
    void on_sendButton_clicked();
    void onApiResponseReceived(QString response); // Slot to update UI
    void on_actionFile_triggered();
    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    ApiCaller *apiCaller; // Make ApiCaller persistent
    std::vector<QString> responses;
    std::vector<QString> prompts;
    ApiKeyConfigWindow *apiKeyConfigWindow;
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

