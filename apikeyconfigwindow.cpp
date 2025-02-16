#include "apikeyconfigwindow.h"
#include "ui_apikeyconfigwindow.h"

ApiKeyConfigWindow::ApiKeyConfigWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ApiKeyConfigWindow)
{
    ui->setupUi(this);

    ui->ApiKeyTextEdit->setStyleSheet(
        "QLineEdit { border: 1px solid gray; outline: none; border-radius: 12px; padding: 5px; } "
        "QLineEdit:focus { border: 1px solid gray; outline: none; border-radius: 20px; }");
}

ApiKeyConfigWindow::~ApiKeyConfigWindow()
{
    delete ui;
}
void ApiKeyConfigWindow::on_buttonBox_clicked(QAbstractButton *n) {}
void ApiKeyConfigWindow::on_OkButton_accepted()
{
    QString newKey = ui->ApiKeyTextEdit->toPlainText();
    if (newKey == "") {
        qDebug() << "Empty API key laoded;(";
        return;
    } else {
        qDebug() << "apiKeySet emitted";
        emit apiKeySet(newKey);
    }
}
