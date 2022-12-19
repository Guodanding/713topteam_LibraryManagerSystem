/********************************************************************************
** Form generated from reading UI file 'readerinformationmanageradddatadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READERINFORMATIONMANAGERADDDATADIALOG_H
#define UI_READERINFORMATIONMANAGERADDDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_readerInformationManagerAdddatadialog
{
public:
    QLineEdit *usernameLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *phoneLineEdit;
    QLabel *username;
    QLabel *password;
    QLabel *phone;
    QLabel *readername;
    QLabel *email;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_9;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *readerInformationManagerAdddatadialog)
    {
        if (readerInformationManagerAdddatadialog->objectName().isEmpty())
            readerInformationManagerAdddatadialog->setObjectName("readerInformationManagerAdddatadialog");
        readerInformationManagerAdddatadialog->resize(646, 403);
        usernameLineEdit = new QLineEdit(readerInformationManagerAdddatadialog);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(120, 80, 113, 25));
        nameLineEdit = new QLineEdit(readerInformationManagerAdddatadialog);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(420, 80, 113, 25));
        passwordLineEdit = new QLineEdit(readerInformationManagerAdddatadialog);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(120, 160, 113, 25));
        emailLineEdit = new QLineEdit(readerInformationManagerAdddatadialog);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(420, 160, 113, 25));
        phoneLineEdit = new QLineEdit(readerInformationManagerAdddatadialog);
        phoneLineEdit->setObjectName("phoneLineEdit");
        phoneLineEdit->setGeometry(QRect(120, 240, 113, 25));
        username = new QLabel(readerInformationManagerAdddatadialog);
        username->setObjectName("username");
        username->setGeometry(QRect(20, 80, 69, 20));
        password = new QLabel(readerInformationManagerAdddatadialog);
        password->setObjectName("password");
        password->setGeometry(QRect(20, 160, 69, 20));
        phone = new QLabel(readerInformationManagerAdddatadialog);
        phone->setObjectName("phone");
        phone->setGeometry(QRect(20, 240, 69, 20));
        readername = new QLabel(readerInformationManagerAdddatadialog);
        readername->setObjectName("readername");
        readername->setGeometry(QRect(310, 80, 69, 20));
        email = new QLabel(readerInformationManagerAdddatadialog);
        email->setObjectName("email");
        email->setGeometry(QRect(310, 160, 69, 20));
        line = new QFrame(readerInformationManagerAdddatadialog);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 50, 571, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(readerInformationManagerAdddatadialog);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(0, 290, 591, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_9 = new QLabel(readerInformationManagerAdddatadialog);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 20, 69, 20));
        buttonBox = new QDialogButtonBox(readerInformationManagerAdddatadialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(390, 340, 193, 29));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(readerInformationManagerAdddatadialog);

        QMetaObject::connectSlotsByName(readerInformationManagerAdddatadialog);
    } // setupUi

    void retranslateUi(QWidget *readerInformationManagerAdddatadialog)
    {
        readerInformationManagerAdddatadialog->setWindowTitle(QCoreApplication::translate("readerInformationManagerAdddatadialog", "Form", nullptr));
        username->setText(QCoreApplication::translate("readerInformationManagerAdddatadialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        password->setText(QCoreApplication::translate("readerInformationManagerAdddatadialog", "\345\257\206\347\240\201", nullptr));
        phone->setText(QCoreApplication::translate("readerInformationManagerAdddatadialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        readername->setText(QCoreApplication::translate("readerInformationManagerAdddatadialog", "\350\257\273\350\200\205\345\220\215\345\255\227", nullptr));
        email->setText(QCoreApplication::translate("readerInformationManagerAdddatadialog", "\347\224\265\345\255\220\351\202\256\347\256\261", nullptr));
        label_9->setText(QCoreApplication::translate("readerInformationManagerAdddatadialog", "\346\267\273\345\212\240\350\257\273\350\200\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class readerInformationManagerAdddatadialog: public Ui_readerInformationManagerAdddatadialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READERINFORMATIONMANAGERADDDATADIALOG_H
