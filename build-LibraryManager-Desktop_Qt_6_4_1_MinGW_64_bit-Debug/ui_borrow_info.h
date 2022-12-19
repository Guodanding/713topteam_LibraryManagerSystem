/********************************************************************************
** Form generated from reading UI file 'borrow_info.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROW_INFO_H
#define UI_BORROW_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_borrow_info
{
public:
    QLabel *label;
    QTableView *tableView;
    QPushButton *ReturnBtn;
    QPushButton *ExitBtn;

    void setupUi(QWidget *borrow_info)
    {
        if (borrow_info->objectName().isEmpty())
            borrow_info->setObjectName("borrow_info");
        borrow_info->resize(777, 452);
        label = new QLabel(borrow_info);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 40, 111, 20));
        tableView = new QTableView(borrow_info);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(80, 90, 541, 241));
        ReturnBtn = new QPushButton(borrow_info);
        ReturnBtn->setObjectName("ReturnBtn");
        ReturnBtn->setGeometry(QRect(300, 380, 93, 29));
        ExitBtn = new QPushButton(borrow_info);
        ExitBtn->setObjectName("ExitBtn");
        ExitBtn->setGeometry(QRect(650, 20, 91, 29));

        retranslateUi(borrow_info);

        QMetaObject::connectSlotsByName(borrow_info);
    } // setupUi

    void retranslateUi(QWidget *borrow_info)
    {
        borrow_info->setWindowTitle(QCoreApplication::translate("borrow_info", "Form", nullptr));
        label->setText(QCoreApplication::translate("borrow_info", "\345\200\237\351\230\205\344\277\241\346\201\257\345\246\202\344\270\213\357\274\232", nullptr));
        ReturnBtn->setText(QCoreApplication::translate("borrow_info", "\350\277\230\344\271\246", nullptr));
        ExitBtn->setText(QCoreApplication::translate("borrow_info", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class borrow_info: public Ui_borrow_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROW_INFO_H
