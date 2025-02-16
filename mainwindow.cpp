#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

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

        "QTextBrowser::selection { background-color: darkgray; color: black; }"
        );

    ui->sendButton->setStyleSheet(
        "QPushButton {"
        "   border-radius: 35px; "  // Half of the width/height
        "   background-color: #3498db;"
        "   color: white;"
        "   font-size: 18px;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #2980b9;"
        "}"
        );
    //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
    /*
    if (_putenv("API_KEY=") == 0) {
        qDebug() << "Environment variable set successfully.\n";
    } else {
        qDebug() << "Failed to set environment variable.\n";
    }
*/
    QString apiKey = std::getenv("API_KEY") ? QString::fromUtf8(std::getenv("API_KEY")) : QString();
    if (apiKey.isEmpty() != true) {
        qDebug() << "API Key:" << apiKey;
    } else {
        qDebug() << "No API key";
        apiKeyConfigWindow = new ApiKeyConfigWindow(this);

        // Connect the signal from ApiKeyConfigWindow to the slot in MainWindow


        apiKeyConfigWindow->show();
    }

    ApiCaller *caller = new ApiCaller(this, apiKey);

    apiCaller = caller;
    connect(apiKeyConfigWindow, &ApiKeyConfigWindow::apiKeySet, apiCaller, &ApiCaller::onApiKeyChanged);
    connect(apiCaller, &ApiCaller::responseReceived, this, &MainWindow::onApiResponseReceived);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//comment for testing
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

//save function
void MainWindow::on_saveButton_clicked()
{
    QString saveStream = ui->responseBox->toPlainText();
    //QString filepath = "newStory.txt";
    QFile file("newStory.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << saveStream;
        file.close();
    } else
    {
        // Handling an error
        qDebug() << "Failed to open file for writing:" << file.errorString();
    }
}

void MainWindow::onApiResponseReceived(QString response)
{ //append response to dialog box
    ui->responseBox->append(response);
    qDebug() << "-------------------------response printed----------------------------";
}



void MainWindow::on_actionFile_triggered()
{

}

