/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUP
{
public:
    QLabel *label;
    QLabel *label_image;
    QLabel *label_5;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_username;
    QLabel *label_4;
    QLineEdit *lineEdit_password;
    QLabel *label_6;
    QLineEdit *lineEdit_repassword;
    QPushButton *pushButton_register;
    QPushButton *pushButton_return;

    void setupUi(QWidget *SignUP)
    {
        if (SignUP->objectName().isEmpty())
            SignUP->setObjectName("SignUP");
        SignUP->resize(800, 600);
        SignUP->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(SignUP);
        label->setObjectName("label");
        label->setGeometry(QRect(490, 20, 171, 81));
        label->setStyleSheet(QString::fromUtf8("font: 30pt \"Arial\";\n"
"color: rgb(0, 170, 255);"));
        label_image = new QLabel(SignUP);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(110, 90, 211, 311));
        label_5 = new QLabel(SignUP);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(440, 100, 301, 61));
        label_5->setStyleSheet(QString::fromUtf8("font: 15pt \"Arial\";\n"
"color: rgb(0, 170, 255);"));
        verticalLayoutWidget = new QWidget(SignUP);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(420, 190, 311, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_3);

        lineEdit_username = new QLineEdit(verticalLayoutWidget);
        lineEdit_username->setObjectName("lineEdit_username");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_username->sizePolicy().hasHeightForWidth());
        lineEdit_username->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(lineEdit_username);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_4);

        lineEdit_password = new QLineEdit(verticalLayoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_password->sizePolicy().hasHeightForWidth());
        lineEdit_password->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(lineEdit_password);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_6);

        lineEdit_repassword = new QLineEdit(verticalLayoutWidget);
        lineEdit_repassword->setObjectName("lineEdit_repassword");
        sizePolicy2.setHeightForWidth(lineEdit_repassword->sizePolicy().hasHeightForWidth());
        lineEdit_repassword->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(lineEdit_repassword);

        pushButton_register = new QPushButton(verticalLayoutWidget);
        pushButton_register->setObjectName("pushButton_register");
        pushButton_register->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_register->sizePolicy().hasHeightForWidth());
        pushButton_register->setSizePolicy(sizePolicy3);
        pushButton_register->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 123, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 9pt \"Bahnschrift Light\";"));

        verticalLayout->addWidget(pushButton_register);

        pushButton_return = new QPushButton(SignUP);
        pushButton_return->setObjectName("pushButton_return");
        pushButton_return->setGeometry(QRect(420, 500, 309, 29));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_return->sizePolicy().hasHeightForWidth());
        pushButton_return->setSizePolicy(sizePolicy4);
        pushButton_return->setStyleSheet(QString::fromUtf8("alternate-background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 255, 255);\n"
""));

        retranslateUi(SignUP);

        QMetaObject::connectSlotsByName(SignUP);
    } // setupUi

    void retranslateUi(QWidget *SignUP)
    {
        SignUP->setWindowTitle(QCoreApplication::translate("SignUP", "Form", nullptr));
        label->setText(QCoreApplication::translate("SignUP", "HELLO ", nullptr));
        label_image->setText(QCoreApplication::translate("SignUP", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("SignUP", "WELCOME TO JOIN US", nullptr));
        label_3->setText(QCoreApplication::translate("SignUP", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("SignUP", "\345\257\206\347\240\201\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("SignUP", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton_register->setText(QCoreApplication::translate("SignUP", "\346\263\250\345\206\214", nullptr));
        pushButton_return->setText(QCoreApplication::translate("SignUP", "\345\233\236\345\210\260\347\231\273\345\275\225\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUP: public Ui_SignUP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
