/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QWidget *centralwidget;
    QTextBrowser *promptTextBox;
    QPushButton *sendButton;
    QTextBrowser *responseBox;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1318, 660);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName("actionFile");
        actionFile->setMenuRole(QAction::MenuRole::ApplicationSpecificRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        promptTextBox = new QTextBrowser(centralwidget);
        promptTextBox->setObjectName("promptTextBox");
        promptTextBox->setGeometry(QRect(20, 540, 901, 71));
        promptTextBox->setReadOnly(false);
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(1160, 540, 131, 71));
        responseBox = new QTextBrowser(centralwidget);
        responseBox->setObjectName("responseBox");
        responseBox->setGeometry(QRect(15, 11, 1281, 511));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-8, -1, 1331, 661));
        label->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/new/images/books.jpg);"));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        promptTextBox->raise();
        sendButton->raise();
        responseBox->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionFile->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
#if QT_CONFIG(shortcut)
        actionFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        sendButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
