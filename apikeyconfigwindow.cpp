#include "apikeyconfigwindow.h"
#include "ui_apikeyconfigwindow.h"

ApiKeyConfigWindow::ApiKeyConfigWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ApiKeyConfigWindow)
{
    ui->setupUi(this);
}

ApiKeyConfigWindow::~ApiKeyConfigWindow()
{
    delete ui;
}
void ApiKeyConfigWindow::on_buttonBox_clicked(QAbstractButton* n){

}
void ApiKeyConfigWindow::on_OkButton_accepted()
{
    QString newKey = ui->ApiKeyTextEdit->toPlainText();
    if(newKey == "")
    {
        qDebug() << "Empty API key laoded;(";
        return;
    }
    else{
        qDebug() << "apiKeySet emitted";
        emit apiKeySet(newKey);
    }
}

