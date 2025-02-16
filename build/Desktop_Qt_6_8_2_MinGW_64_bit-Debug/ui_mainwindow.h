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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTextBrowser *responseBox;
    QWidget *gridWidget;
    QGridLayout *gridLayout_2;
    QTextBrowser *promptTextBox;
    QPushButton *sendButton;
    QTextBrowser *textBrowser;
    QStatusBar *statusbar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1178, 605);
        MainWindow->setAutoFillBackground(false);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName("actionFile");
        actionFile->setMenuRole(QAction::MenuRole::ApplicationSpecificRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMaximumSize(QSize(16777215, 16777215));
        centralwidget->setStyleSheet(QString::fromUtf8("background-image: url(:/new/images/books.jpg);"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        responseBox = new QTextBrowser(centralwidget);
        responseBox->setObjectName("responseBox");

        gridLayout->addWidget(responseBox, 0, 3, 1, 1);

        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName("gridWidget");
        gridWidget->setMaximumSize(QSize(10000, 10000));
        gridLayout_2 = new QGridLayout(gridWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        promptTextBox = new QTextBrowser(gridWidget);
        promptTextBox->setObjectName("promptTextBox");
        promptTextBox->setReadOnly(false);

        gridLayout_2->addWidget(promptTextBox, 2, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignBottom);

        sendButton = new QPushButton(gridWidget);
        sendButton->setObjectName("sendButton");

        gridLayout_2->addWidget(sendButton, 4, 0, 1, 1);

        textBrowser = new QTextBrowser(gridWidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMinimumSize(QSize(0, 192));
        textBrowser->setAutoFillBackground(true);

        gridLayout_2->addWidget(textBrowser, 1, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);


        gridLayout->addWidget(gridWidget, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1178, 25));
        MainWindow->setMenuBar(menuBar);

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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
