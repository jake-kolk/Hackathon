#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , apiCaller(new ApiCaller(this)) // Persistent instance
{
    ui->setupUi(this);
    //let the main window know when apicaller gets response
    connect(apiCaller, &ApiCaller::responseReceived, this, &MainWindow::onApiResponseReceived);
    //set response box color
    ui->responseBox->setStyleSheet(
        "QTextBrowser { "
        "   background-color: black; "
        "   color: white; "
        "   border-radius: 10px; "
        "   padding: 8px; "
        "   border: 2px solid gray; "
        "} "
        "QTextBrowser::selection { background-color: darkgray; color: black; }");

    ui->sendButton->setStyleSheet("QPushButton {"
                                  "   border-radius: 35px; " // Half of the width/height
                                  "   background-color: #3498db;"
                                  "   color: white;"
                                  "   font-size: 18px;"
                                  "}"
                                  "QPushButton:pressed {"
                                  "   background-color: #2980b9;"
                                  "}");
    ApiCaller *caller = new ApiCaller(this);
    apiCaller = caller;
    connect(apiCaller, &ApiCaller::responseReceived, this, &MainWindow::onApiResponseReceived);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendButton_clicked()
{
    QString prompt = ui->promptTextBox->toPlainText();
    QString userDialog = "\nYou: ";
    userDialog.append(prompt);
    userDialog.append("\n");
    //Put entered text into the chat window
    ui->responseBox->append(userDialog);
    // Call OpenRouter API
    apiCaller->makeRequest(prompt);
}

void MainWindow::onApiResponseReceived(QString response)
{ //append response to dialog box
    ui->responseBox->append(response);
    qDebug() << "-------------------------response printed----------------------------";
}

void MainWindow::on_actionFile_triggered() {}
