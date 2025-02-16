#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMenu>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , apiCaller(new ApiCaller(this)) // Persistent instance
{
    ui->setupUi(this);

    // Create Menu
    QMenu *fileMenu = menuBar()->addMenu("File");

    // Create actionSave
    QAction *actionSave = new QAction("Save", this);
    fileMenu->addAction(actionSave);
    // Connect actionSave to slot
    connect(actionSave, &QAction::triggered, this, &MainWindow::on_saveButton_clicked);

    // Create actionSave
    QAction *actionClearApiKey = new QAction("Clear API Key", this);
    fileMenu->addAction(actionClearApiKey);
    //connect action save is done lower so its linked to Apicaller (named caller) object


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
    //init ApiCaller
    ApiCaller *caller = new ApiCaller(this, "");
    this->apiCaller = caller;
    //Connect ApiCaller response receved signal to MainWindow so MainWindow can display results
    connect(apiCaller, &ApiCaller::responseReceived, this, &MainWindow::onApiResponseReceived);
    //This loads the Api key and send it to caller
    QString apiKey = caller->loadApiKey();

    //connect action clearApiKey to slot
    connect(actionClearApiKey, &QAction::triggered, caller, &ApiCaller::onClearApiKeyButtonCLicked);

    if(apiKey == "")//if no key is loaded, open key config window
    {
        qDebug() << "No API key loaded....";
        //init ApiKeyConfigWindow
        apiKeyConfigWindow = new ApiKeyConfigWindow(this);
        //connect ApiKeyConfig key changes signal to ApiCaller so it can update json and update ApiCaller attribute
        connect(apiKeyConfigWindow, &ApiKeyConfigWindow::apiKeySet, apiCaller, &ApiCaller::onApiKeyChanged);
        apiKeyConfigWindow->setWindowTitle(QString("API key configuration"));
        apiKeyConfigWindow->show();

    }else{
        qDebug() << "Key loaded: " << apiKey;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
//comment for testing
void MainWindow::on_sendButton_clicked()
{
    if(apiCaller->isApiKeyEmpty())//if no key is loaded, open key config window
    {
        qDebug() << "No API key loaded....";
        //init ApiKeyConfigWindow
        apiKeyConfigWindow = new ApiKeyConfigWindow(this);
        //connect ApiKeyConfig key changes signal to ApiCaller so it can update json and update ApiCaller attribute
        connect(apiKeyConfigWindow, &ApiKeyConfigWindow::apiKeySet, apiCaller, &ApiCaller::onApiKeyChanged);
        apiKeyConfigWindow->setWindowTitle(QString("API key configuration"));
        apiKeyConfigWindow->show();
        return;

    }else{
        qDebug() << "on_sendButton_clicked(): WE HAVE API KEY ";
    }
    QString prompt = ui->promptTextBox->toPlainText();
    //clear prompt box after pressing enter
    ui->promptTextBox->clear();
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
    qDebug() << "FILE HIT";
}

void MainWindow::clearResponseWindow(){
    ui->responseBox->clear();
}

void MainWindow::imageHandler()
{
    //wont be file, will be feed of images generated
    QString filename = "xxxxx";
    QLabel* lbl = new QLabel(this);
    //for showing in center
    lbl->setAlignment(Qt::AlignCenter);
    QPixmap pix;

    //if loaded okay
    if(pix.load(filename))
    {
        //scaling
        pix = pix.scaled(lbl->size(),Qt::KeepAspectRatio);
        lbl->setPixmap(pix);
    }
}
