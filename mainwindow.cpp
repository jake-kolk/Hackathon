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
        "QTextBrowser::selection { background-color: darkgray; color: black; }"
        );

    //set tab container color
    ui->tabContainer->setStyleSheet(
        "QTabBar::tab { "
        "   height: 10px; "
        "   padding: 8px; "
        "   background: #1E2E2E; "
        "   color: white; "
        "   border-top-left-radius: 10px; "
       // "   border-bottom-right-radius: 10px; "
        "   border-top-right-radius: 10px; "
       // "   border: 2px solid #3B4B4B; "
        "} "
        "QTabBar::tab:selected { background: #3B4B4B; } "
        "QTabBar::tab:hover { background: #465656; } "
        );
    ui->tabContainer->setTabText(0, "\"ChatGPT\"");  // Changes the first tab's title
    ui->tabContainer->setTabText(1, "\"DeepSeek\"");
    //set prompt text box style
    ui->promptTextBox->setStyleSheet(
        "QTextEdit { "
        "   background-color: #B0B0B0; "
        "   color: black; "
        "   border-radius: 10px; "
        "   padding: 8px; "
        "   border: 2px solid #707070; " // Darker border
        "   selection-background-color: #909090; " // Highlight color for selected text
        "} "
        );
    //set style sheet for send button

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
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_sendButton_clicked() {
    QString prompt = ui->promptTextBox->toPlainText();
    ApiCaller *caller = new ApiCaller(this);
    QString userDialog = "You: ";
    userDialog.append(prompt);
    userDialog.append("\n");
    //Put entered text into the chat window
    ui->responseBox->append(userDialog);
    //connect APICaller::ResponseReceved to MainWindow::onApiResponseREceved
    connect(caller, &ApiCaller::responseReceived, this, &MainWindow::onApiResponseReceived);
    // Call OpenRouter API
    caller->makeRequest(prompt);

}

void MainWindow::onApiResponseReceived(QString response) {//append response to dialog box
    QString responseDialog = "AI: ";
    responseDialog.append(response);
    responseDialog.append("\n");
    ui->responseBox->append(responseDialog);
}

void MainWindow::on_actionFile_triggered()
{

}

