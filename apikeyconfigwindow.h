#ifndef APIKEYCONFIGWINDOW_H
#define APIKEYCONFIGWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QTimer>
#include <cstdlib>
#include <QAbstractButton>


namespace Ui {
class ApiKeyConfigWindow;
}

class ApiKeyConfigWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ApiKeyConfigWindow(QWidget *parent = nullptr);
    ~ApiKeyConfigWindow();
signals:
    void apiKeySet(QString apiKey);
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_OkButton_accepted();

private:
    Ui::ApiKeyConfigWindow *ui;
};

#endif // APIKEYCONFIGWINDOW_H
