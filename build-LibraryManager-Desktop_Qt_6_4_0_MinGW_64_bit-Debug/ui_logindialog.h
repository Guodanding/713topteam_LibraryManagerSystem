/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(944, 570);
        buttonBox = new QDialogButtonBox(LoginDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(490, 470, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(LoginDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 20, 551, 131));
        QFont font;
        font.setPointSize(19);
        label->setFont(font);
        lineEdit = new QLineEdit(LoginDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(320, 180, 113, 25));
        lineEdit_2 = new QLineEdit(LoginDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(320, 270, 113, 25));
        label_2 = new QLabel(LoginDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 180, 69, 20));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(240, 270, 69, 20));
        radioButton = new QRadioButton(LoginDialog);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(220, 380, 118, 24));
        radioButton_2 = new QRadioButton(LoginDialog);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(370, 380, 118, 24));
        dateTimeEdit = new QDateTimeEdit(LoginDialog);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(120, 490, 194, 25));

        retranslateUi(LoginDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, LoginDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, LoginDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237       \347\231\273\351\231\206\347\225\214\351\235\242", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("LoginDialog", "\345\257\206\347\240\201", nullptr));
        radioButton->setText(QCoreApplication::translate("LoginDialog", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
        radioButton_2->setText(QCoreApplication::translate("LoginDialog", "\350\257\273\350\200\205\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
