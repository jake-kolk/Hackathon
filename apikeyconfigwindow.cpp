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

void ApiKeyConfigWindow::on_buttonBox_clicked(QAbstractButton *button)//shits not working idk why program uses one below
{
    QString newKey = ui->ApiKeyTextEdit->toPlainText();
    if(newKey == "")
    {
        return;
    }
    else{
        emit apiKeySet(newKey);
    }
}


void ApiKeyConfigWindow::on_OkButton_accepted()
{
    QString newKey = ui->ApiKeyTextEdit->toPlainText();
    if(newKey == "")
    {
        return;
    }
    else{
        emit apiKeySet(newKey);
    }
}

