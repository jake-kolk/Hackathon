/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QWidget *centralwidget;
    QTabWidget *tabContainer;
    QWidget *tab;
    QTextBrowser *responseBox;
    QTextEdit *promptTextBox;
    QPushButton *sendButton;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(462, 401);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName("actionFile");
        actionFile->setMenuRole(QAction::MenuRole::ApplicationSpecificRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabContainer = new QTabWidget(centralwidget);
        tabContainer->setObjectName("tabContainer");
        tabContainer->setGeometry(QRect(6, 0, 451, 351));
        tab = new QWidget();
        tab->setObjectName("tab");
        responseBox = new QTextBrowser(tab);
        responseBox->setObjectName("responseBox");
        responseBox->setGeometry(QRect(10, 10, 421, 221));
        responseBox->setMouseTracking(true);
        responseBox->setFrameShadow(QFrame::Shadow::Raised);
        promptTextBox = new QTextEdit(tab);
        promptTextBox->setObjectName("promptTextBox");
        promptTextBox->setGeometry(QRect(10, 240, 351, 70));
        promptTextBox->setAutoFillBackground(false);
        promptTextBox->setFrameShape(QFrame::Shape::StyledPanel);
        sendButton = new QPushButton(tab);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(370, 240, 71, 71));
        tabContainer->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabContainer->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 462, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());

        retranslateUi(MainWindow);

        tabContainer->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionFile->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
#if QT_CONFIG(shortcut)
        actionFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        sendButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        tabContainer->setTabText(tabContainer->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        tabContainer->setTabText(tabContainer->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
