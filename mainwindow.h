#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "apicaller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sendButton_clicked();
    void onApiResponseReceived(QString response); // Slot to update UI

    void on_actionFile_triggered();

private:
    Ui::MainWindow *ui;
    ApiCaller *apiCaller; // Make ApiCaller persistent
    std::vector<QString> responses;
    std::vector<QString> prompts;
};

#endif // MAINWINDOW_H

