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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
    QWidget *gridWidget;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QTextBrowser *promptTextBox;
    QVBoxLayout *verticalLayout;
    QTextBrowser *responseBox;
    QPushButton *pushButton;
    QPushButton *sendButton;
    QGraphicsView *graphicsView;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuSave;
    QMenu *menuClear;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1178, 668);
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
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName("gridWidget");
        gridWidget->setMaximumSize(QSize(10000, 10000));
        gridLayout_2 = new QGridLayout(gridWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        textBrowser = new QTextBrowser(gridWidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMinimumSize(QSize(0, 192));
        textBrowser->setAutoFillBackground(false);

        gridLayout_2->addWidget(textBrowser, 1, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        promptTextBox = new QTextBrowser(gridWidget);
        promptTextBox->setObjectName("promptTextBox");
        promptTextBox->setReadOnly(false);

        gridLayout_2->addWidget(promptTextBox, 3, 0, 2, 1, Qt::AlignmentFlag::AlignHCenter);


        gridLayout->addWidget(gridWidget, 2, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);

        responseBox = new QTextBrowser(centralwidget);
        responseBox->setObjectName("responseBox");

        gridLayout->addWidget(responseBox, 2, 3, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 3, 4, 1, 1);

        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName("sendButton");

        gridLayout->addWidget(sendButton, 3, 2, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 2, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1178, 25));
        menuSave = new QMenu(menuBar);
        menuSave->setObjectName("menuSave");
        menuClear = new QMenu(menuBar);
        menuClear->setObjectName("menuClear");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuSave->menuAction());
        menuBar->addAction(menuClear->menuAction());

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
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:700; text-decoration: underline;\">User Manual:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt; font-weight:700; text-decoration: underline;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right"
                        ":0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">Enter a topic for your story in the textbox below.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">and click &quot;send&quot;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">If you would like to save the story generated as</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">a .txt file click the &quot;save&quot; button</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; mar"
                        "gin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">If you would like to clear the story hit &quot;Clear&quot;</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:11pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p></body></html>", nullptr));
        promptTextBox->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Next...", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "Make your story!", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menuClear->setTitle(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
