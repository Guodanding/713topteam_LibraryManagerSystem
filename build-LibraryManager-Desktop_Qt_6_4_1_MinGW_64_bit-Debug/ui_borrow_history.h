/********************************************************************************
** Form generated from reading UI file 'borrow_history.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROW_HISTORY_H
#define UI_BORROW_HISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_borrow_history
{
public:
    QLabel *label;
    QTableView *tableView;
    QPushButton *ExitBtn;

    void setupUi(QWidget *borrow_history)
    {
        if (borrow_history->objectName().isEmpty())
            borrow_history->setObjectName("borrow_history");
        borrow_history->resize(740, 458);
        label = new QLabel(borrow_history);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 40, 81, 20));
        tableView = new QTableView(borrow_history);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(80, 110, 551, 281));
        ExitBtn = new QPushButton(borrow_history);
        ExitBtn->setObjectName("ExitBtn");
        ExitBtn->setGeometry(QRect(590, 30, 91, 29));

        retranslateUi(borrow_history);

        QMetaObject::connectSlotsByName(borrow_history);
    } // setupUi

    void retranslateUi(QWidget *borrow_history)
    {
        borrow_history->setWindowTitle(QCoreApplication::translate("borrow_history", "Form", nullptr));
        label->setText(QCoreApplication::translate("borrow_history", "\345\200\237\351\230\205\345\216\206\345\217\262\357\274\232", nullptr));
        ExitBtn->setText(QCoreApplication::translate("borrow_history", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class borrow_history: public Ui_borrow_history {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROW_HISTORY_H
