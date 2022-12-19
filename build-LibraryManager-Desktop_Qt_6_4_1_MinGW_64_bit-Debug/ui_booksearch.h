/********************************************************************************
** Form generated from reading UI file 'booksearch.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKSEARCH_H
#define UI_BOOKSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookSearch
{
public:
    QTableView *tableView;
    QLabel *label;
    QLineEdit *lineEdit_bookname;
    QLabel *label_2;
    QPushButton *BorrowBtn;
    QPushButton *SearchBtn;
    QPushButton *ExitBtn;
    QLabel *label_3;
    QLineEdit *lineEdit_author;

    void setupUi(QWidget *BookSearch)
    {
        if (BookSearch->objectName().isEmpty())
            BookSearch->setObjectName("BookSearch");
        BookSearch->resize(864, 486);
        tableView = new QTableView(BookSearch);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(100, 170, 551, 221));
        label = new QLabel(BookSearch);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 20, 101, 20));
        lineEdit_bookname = new QLineEdit(BookSearch);
        lineEdit_bookname->setObjectName("lineEdit_bookname");
        lineEdit_bookname->setGeometry(QRect(160, 20, 241, 25));
        label_2 = new QLabel(BookSearch);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 130, 91, 20));
        BorrowBtn = new QPushButton(BookSearch);
        BorrowBtn->setObjectName("BorrowBtn");
        BorrowBtn->setGeometry(QRect(330, 420, 93, 29));
        SearchBtn = new QPushButton(BookSearch);
        SearchBtn->setObjectName("SearchBtn");
        SearchBtn->setGeometry(QRect(470, 60, 93, 29));
        ExitBtn = new QPushButton(BookSearch);
        ExitBtn->setObjectName("ExitBtn");
        ExitBtn->setGeometry(QRect(752, 30, 41, 21));
        label_3 = new QLabel(BookSearch);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 70, 121, 20));
        lineEdit_author = new QLineEdit(BookSearch);
        lineEdit_author->setObjectName("lineEdit_author");
        lineEdit_author->setGeometry(QRect(160, 70, 141, 25));

        retranslateUi(BookSearch);

        QMetaObject::connectSlotsByName(BookSearch);
    } // setupUi

    void retranslateUi(QWidget *BookSearch)
    {
        BookSearch->setWindowTitle(QCoreApplication::translate("BookSearch", "Form", nullptr));
        label->setText(QCoreApplication::translate("BookSearch", "\350\257\267\350\276\223\345\205\245\344\271\246\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("BookSearch", "\347\273\223\346\236\234\345\246\202\344\270\213\357\274\232", nullptr));
        BorrowBtn->setText(QCoreApplication::translate("BookSearch", "\345\200\237\344\271\246", nullptr));
        SearchBtn->setText(QCoreApplication::translate("BookSearch", "\346\237\245\350\257\242", nullptr));
        ExitBtn->setText(QCoreApplication::translate("BookSearch", "x", nullptr));
        label_3->setText(QCoreApplication::translate("BookSearch", "\350\257\267\350\276\223\345\205\245\344\275\234\350\200\205\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookSearch: public Ui_BookSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSEARCH_H
