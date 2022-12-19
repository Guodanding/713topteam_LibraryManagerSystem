/********************************************************************************
** Form generated from reading UI file 'readerinformationmanagermodifydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READERINFORMATIONMANAGERMODIFYDIALOG_H
#define UI_READERINFORMATIONMANAGERMODIFYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_readerInformationManagerModifydialog
{
public:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *phoneLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *emailLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_9;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *readerInformationManagerModifydialog)
    {
        if (readerInformationManagerModifydialog->objectName().isEmpty())
            readerInformationManagerModifydialog->setObjectName("readerInformationManagerModifydialog");
        readerInformationManagerModifydialog->resize(676, 377);
        usernameLineEdit = new QLineEdit(readerInformationManagerModifydialog);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(140, 100, 113, 25));
        passwordLineEdit = new QLineEdit(readerInformationManagerModifydialog);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(140, 180, 113, 25));
        phoneLineEdit = new QLineEdit(readerInformationManagerModifydialog);
        phoneLineEdit->setObjectName("phoneLineEdit");
        phoneLineEdit->setGeometry(QRect(140, 260, 113, 25));
        nameLineEdit = new QLineEdit(readerInformationManagerModifydialog);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(440, 100, 113, 25));
        emailLineEdit = new QLineEdit(readerInformationManagerModifydialog);
        emailLineEdit->setObjectName("emailLineEdit");
        emailLineEdit->setGeometry(QRect(440, 180, 113, 25));
        label = new QLabel(readerInformationManagerModifydialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 100, 69, 20));
        label_2 = new QLabel(readerInformationManagerModifydialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 180, 69, 20));
        label_3 = new QLabel(readerInformationManagerModifydialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 260, 69, 20));
        label_5 = new QLabel(readerInformationManagerModifydialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(330, 100, 69, 20));
        label_6 = new QLabel(readerInformationManagerModifydialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(330, 180, 69, 20));
        line = new QFrame(readerInformationManagerModifydialog);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 300, 641, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(readerInformationManagerModifydialog);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(10, 60, 631, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_9 = new QLabel(readerInformationManagerModifydialog);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 20, 91, 31));
        buttonBox = new QDialogButtonBox(readerInformationManagerModifydialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(450, 330, 193, 29));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(readerInformationManagerModifydialog);

        QMetaObject::connectSlotsByName(readerInformationManagerModifydialog);
    } // setupUi

    void retranslateUi(QWidget *readerInformationManagerModifydialog)
    {
        readerInformationManagerModifydialog->setWindowTitle(QCoreApplication::translate("readerInformationManagerModifydialog", "Form", nullptr));
        label->setText(QCoreApplication::translate("readerInformationManagerModifydialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("readerInformationManagerModifydialog", "\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("readerInformationManagerModifydialog", "\346\211\213\346\234\272\345\217\267", nullptr));
        label_5->setText(QCoreApplication::translate("readerInformationManagerModifydialog", "\350\257\273\350\200\205\345\220\215\345\255\227", nullptr));
        label_6->setText(QCoreApplication::translate("readerInformationManagerModifydialog", "\347\224\265\345\255\220\351\202\256\347\256\261", nullptr));
        label_9->setText(QCoreApplication::translate("readerInformationManagerModifydialog", "\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class readerInformationManagerModifydialog: public Ui_readerInformationManagerModifydialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READERINFORMATIONMANAGERMODIFYDIALOG_H
