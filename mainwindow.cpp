#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , apiCaller(new ApiCaller(this)) // Persistent instance
{
    ui->setupUi(this);
    QMenu *fileMenu = ui->menuBar->addMenu("File");
   // QMenu *fileMenu = menuBar->addMenu("File");
    // Create actionSave
    QAction *actionSave = new QAction("Save", this);
    fileMenu->addAction(actionSave);
    // Connect actionSave to slot
    connect(actionSave, &QAction::triggered, this, &MainWindow::on_saveButton_clicked);

    // Create clear api key
    QAction *actionClearApiKey = new QAction("Clear API Key", this);
    fileMenu->addAction(actionClearApiKey);
    //connect action save is done lower so its linked to Apicaller (named caller) object

    //let the main window know when apicaller gets response
    connect(apiCaller, &ApiCaller::responseReceived, this, &MainWindow::onApiResponseReceived);

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
      //  "   border-radius: 35px; "  // Half of the width/height
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
    //connect clear api bey button to function:
    connect(actionClearApiKey, &QAction::triggered, caller, &ApiCaller::onClearApiKeyButtonCLicked);
    //This loads the Api key and send it to caller
    QString apiKey = caller->loadApiKey();
    if(apiKey == "")//if no key is loaded, open key config window
    {
        qDebug() << "No API key loaded....";
        //init ApiKeyConfigWindow
        apiKeyConfigWindow = new ApiKeyConfigWindow(this);
        //connect ApiKeyConfig key changes signal to ApiCaller so it can update json and update ApiCaller attribute
        connect(apiKeyConfigWindow, &ApiKeyConfigWindow::apiKeySet, apiCaller, &ApiCaller::onApiKeyChanged);
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

    if(this->apiCaller->isApiKeyEmpty() == true){
        qDebug() << "No API key loaded....";
        //init ApiKeyConfigWindow
        apiKeyConfigWindow = new ApiKeyConfigWindow(this);
        //connect ApiKeyConfig key changes signal to ApiCaller so it can update json and update ApiCaller attribute
        connect(apiKeyConfigWindow, &ApiKeyConfigWindow::apiKeySet, apiCaller, &ApiCaller::onApiKeyChanged);
        apiKeyConfigWindow->show();
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
        qDebug() << "Successfully wrote to file(Origin: MainWindow::on_saveButtonClicked()";
    }
    else
    {
        // Handling an error
        qDebug() << "Failed to open file for writing:" << file.errorString();
    }
}


void MainWindow::onApiResponseReceived(QString response)
{   //append response to dialog box
   // ui->responseBox->append(response);
    qDebug() << "-------------------------response printed----------------------------scanning images";
    //QStringList pageText = response.split('*');
    QStringList pageText = response.split('*');
    QString command;
    int pageCount = pageText.count();

    ui->responseBox->setText(pageText[0]);

    QProcess *process = new QProcess(this);
    StoryMediaContainer* container = new StoryMediaContainer;
    QImage* image;
    QString fileloc = "";
    QString* newString;
    for(int i = 0;  i < pageCount; i++)
    {

        command = QString("://../../../../../image_gen.exe %1.jpg \"").arg(i);
        command.append(pageText[i]);
        command.append("\"");
        process->start(command);
        if (!process->waitForFinished()) {
            qDebug() << "Error: Process failed to finish. (Origin MainWindow::onApiResonseReceved)";
        } else {
            int exitCode = process->exitCode();
            if (exitCode == 0) {
                qDebug() << "Process executed successfully!(Origin MainWindow::onApiResonseReceved)";
            } else {
                qDebug() << "(Origin MainWindow::onApiResonseReceved) Process exited with code:" << exitCode;
            }
        }
        fileloc = QString("%1.jpg").arg(i);
        image = container->scanImage(fileloc);
        if(image->isNull())
        {
            qDebug() << "Error: (Origin MainWindow::onApiResonseReceved, if(image->isNull == true))";
        }
        container->addMedia(*image);
        container->addQString(pageText[i]);
       QPixmap pixmap = QPixmap::fromImage(*image);
        // Create a QGraphicsScene to hold the item
        QGraphicsScene *scene = new QGraphicsScene();

        // Create a QGraphicsPixmapItem with the QPixmap
        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);

        // Add the item to the scene
        scene->addItem(item);

        // Optionally, adjust the view to fit the item
        container->pixmaps.push_back(scene);
        newString = new QString(pageText[i]);
        container->pageTexts.push_back(newString);
        if(i == 0){
            ui->graphicsView->setScene(container->pixmaps[0]);
            ui->graphicsView->fitInView(item, Qt::KeepAspectRatio);
        }
        this->vectorLen++;
    }
    ui->graphicsView->setScene(container->pixmaps[0]);
    this->mediaContainer = *container;
  //  ui->graphicsView->show();
}



void MainWindow::on_actionFile_triggered()
{
    qDebug() << "File button pressed";
}

void MainWindow::clearResponseWindow(){
    ui->responseBox->clear();
}

void MainWindow::updateImage()
{
    scene->clear(); // Clear previous image

    // Ensure the index is valid before accessing images
    QImage image = mediaContainer.getImage(currentIndex);
    if (image.isNull() == false)
    {
        QPixmap pixmap = QPixmap::fromImage(image);
        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
        scene->addItem(item); // Add image to the scene
    }

    ui->graphicsView->setScene(scene);
    ui->graphicsView->fitInView(scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}

// Load images from StoryMediaContainer
void MainWindow::imageHandler(StoryMediaContainer &container)
{
    mediaContainer = container; // Store the media container
    currentIndex = 0;           // Start from the first image

    scene = new QGraphicsScene(this); // Create scene
    updateImage(); // Display the first image
}

void MainWindow::nextImage()
{

}

void MainWindow::prevImage()
{

}

void MainWindow::nextText()
{


}

void MainWindow::prevText()
{

}

void MainWindow::on_pushButton_clicked()
{
    //int vectorSize = this->mediaContainer.pageText.size();
    int vectorSize = (int)this->mediaContainer.pageText.size();
    if( this->vectorPos < vectorSize - 1)
    {
        int newIndex = this->vectorPos + 1;
        QString newString = this->mediaContainer.pageText[vectorPos + 1];
        ui->responseBox->setText(newString);

        ui->graphicsView->setScene(this->mediaContainer.pixmaps[this->vectorPos + 1]);
        this->vectorPos++;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    //int vectorSize = this->mediaContainer.pageText.size();
    int vectorSize = (int)this->mediaContainer.pageText.size();
    if( this->vectorPos > 0)
    {
        int newIndex = this->vectorPos - 1;
        QString newString = this->mediaContainer.pageText[vectorPos - 1];
        ui->responseBox->setText(newString);

        ui->graphicsView->setScene(this->mediaContainer.pixmaps[this->vectorPos - 1]);
        this->vectorPos--;
    }
}

