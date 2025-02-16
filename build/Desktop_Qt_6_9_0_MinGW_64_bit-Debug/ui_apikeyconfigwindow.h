/********************************************************************************
** Form generated from reading UI file 'apikeyconfigwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APIKEYCONFIGWINDOW_H
#define UI_APIKEYCONFIGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ApiKeyConfigWindow
{
public:
    QDialogButtonBox *OkButton;
    QLabel *NoKeyLabel;
    QTextEdit *ApiKeyTextEdit;

    void setupUi(QDialog *ApiKeyConfigWindow)
    {
        if (ApiKeyConfigWindow->objectName().isEmpty())
            ApiKeyConfigWindow->setObjectName("ApiKeyConfigWindow");
        ApiKeyConfigWindow->resize(400, 300);
        OkButton = new QDialogButtonBox(ApiKeyConfigWindow);
        OkButton->setObjectName("OkButton");
        OkButton->setGeometry(QRect(30, 240, 341, 32));
        OkButton->setOrientation(Qt::Orientation::Horizontal);
        OkButton->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        NoKeyLabel = new QLabel(ApiKeyConfigWindow);
        NoKeyLabel->setObjectName("NoKeyLabel");
        NoKeyLabel->setGeometry(QRect(20, 40, 361, 20));
        ApiKeyTextEdit = new QTextEdit(ApiKeyConfigWindow);
        ApiKeyTextEdit->setObjectName("ApiKeyTextEdit");
        ApiKeyTextEdit->setGeometry(QRect(30, 80, 321, 151));

        retranslateUi(ApiKeyConfigWindow);
        QObject::connect(OkButton, &QDialogButtonBox::accepted, ApiKeyConfigWindow, qOverload<>(&QDialog::accept));
        QObject::connect(OkButton, &QDialogButtonBox::rejected, ApiKeyConfigWindow, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(ApiKeyConfigWindow);
    } // setupUi

    void retranslateUi(QDialog *ApiKeyConfigWindow)
    {
        ApiKeyConfigWindow->setWindowTitle(QCoreApplication::translate("ApiKeyConfigWindow", "Dialog", nullptr));
        NoKeyLabel->setText(QCoreApplication::translate("ApiKeyConfigWindow", "You have no API key saved on your machine. Enter one below:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApiKeyConfigWindow: public Ui_ApiKeyConfigWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APIKEYCONFIGWINDOW_H
