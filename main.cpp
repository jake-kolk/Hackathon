#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString("PictoTales"));
    w.setWindowIcon(QIcon(":/pictoTalesIcon.png"));
    w.show();
    return a.exec();
}
