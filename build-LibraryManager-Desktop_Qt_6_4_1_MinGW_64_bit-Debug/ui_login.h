/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label_image;
    QLabel *label_tip;
    QLabel *label_welcome;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Button_login;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_signup;
    QLabel *label_gif;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_user;
    QRadioButton *radioButton_admin;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(800, 600);
        Login->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_image = new QLabel(Login);
        label_image->setObjectName("label_image");
        label_image->setGeometry(QRect(10, 10, 361, 571));
        label_tip = new QLabel(Login);
        label_tip->setObjectName("label_tip");
        label_tip->setGeometry(QRect(710, 250, 181, 41));
        label_tip->setStyleSheet(QString::fromUtf8("font: 7pt \"Arial\";"));
        label_welcome = new QLabel(Login);
        label_welcome->setObjectName("label_welcome");
        label_welcome->setGeometry(QRect(420, 100, 211, 41));
        label_welcome->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(170, 255, 255);"));
        verticalLayoutWidget = new QWidget(Login);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(420, 180, 281, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_username = new QLineEdit(verticalLayoutWidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setEnabled(true);
        lineEdit_username->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(lineEdit_username);

        lineEdit_password = new QLineEdit(verticalLayoutWidget);
        lineEdit_password->setObjectName("lineEdit_password");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_password->sizePolicy().hasHeightForWidth());
        lineEdit_password->setSizePolicy(sizePolicy);
        lineEdit_password->setTabletTracking(true);
        lineEdit_password->setAcceptDrops(false);
        lineEdit_password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_password);

        horizontalLayoutWidget = new QWidget(Login);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(420, 390, 281, 111));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Button_login = new QPushButton(horizontalLayoutWidget);
        Button_login->setObjectName("Button_login");
        Button_login->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 123, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 9pt \"Bahnschrift Light\";"));

        horizontalLayout->addWidget(Button_login);

        horizontalSpacer = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Button_signup = new QPushButton(horizontalLayoutWidget);
        Button_signup->setObjectName("Button_signup");
        Button_signup->setStyleSheet(QString::fromUtf8("background-color: rgb(29, 123, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 25 9pt \"Bahnschrift Light\";"));

        horizontalLayout->addWidget(Button_signup);

        label_gif = new QLabel(Login);
        label_gif->setObjectName("label_gif");
        label_gif->setGeometry(QRect(620, 10, 151, 141));
        label_gif->setStyleSheet(QString::fromUtf8(""));
        horizontalLayoutWidget_2 = new QWidget(Login);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(420, 310, 281, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_user = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_user->setObjectName("radioButton_user");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(radioButton_user->sizePolicy().hasHeightForWidth());
        radioButton_user->setSizePolicy(sizePolicy1);
        radioButton_user->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"    spacing: 2px;\n"
"    color: black;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 45px;\n"
"    height: 30px;\n"
"}\n"
"QRadioButton::indicator:unchecked {\n"
"    image: url(:/images/radio_button_left.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    image: url(:/images/radio_button_right.png);\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"     image: url(:/images/radio_button_right.png);\n"
"}\n"
"QRadioButton::indicator:checked:pressed {\n"
"     image: url(:/images/radio_button_left.png);\n"
"}"));

        horizontalLayout_2->addWidget(radioButton_user);

        radioButton_admin = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_admin->setObjectName("radioButton_admin");
        sizePolicy1.setHeightForWidth(radioButton_admin->sizePolicy().hasHeightForWidth());
        radioButton_admin->setSizePolicy(sizePolicy1);
        radioButton_admin->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	font: 10pt \"Microsoft YaHei UI\";\n"
"    spacing: 2px;\n"
"    color: black;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 45px;\n"
"    height: 30px;\n"
"}\n"
"QRadioButton::indicator:unchecked {\n"
"    image: url(:/images/radio_button_left.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:pressed {\n"
"    image: url(:/images/radio_button_right.png);\n"
"}\n"
"QRadioButton::indicator:checked {\n"
"     image: url(:/images/radio_button_right.png);\n"
"}\n"
"QRadioButton::indicator:checked:pressed {\n"
"     image: url(:/images/radio_button_left.png);\n"
"}"));

        horizontalLayout_2->addWidget(radioButton_admin);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        label_image->setText(QString());
        label_tip->setText(QString());
        label_welcome->setText(QCoreApplication::translate("Login", "WELCOME", nullptr));
        lineEdit_username->setPlaceholderText(QCoreApplication::translate("Login", "please input your ID", nullptr));
        lineEdit_password->setText(QString());
        lineEdit_password->setPlaceholderText(QCoreApplication::translate("Login", "please input your password", nullptr));
        Button_login->setText(QCoreApplication::translate("Login", "sign in", nullptr));
        Button_signup->setText(QCoreApplication::translate("Login", "sign up", nullptr));
        label_gif->setText(QCoreApplication::translate("Login", "TextLabel", nullptr));
        radioButton_user->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        radioButton_admin->setText(QCoreApplication::translate("Login", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
