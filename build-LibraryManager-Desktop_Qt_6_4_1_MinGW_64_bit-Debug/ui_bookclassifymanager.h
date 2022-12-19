/********************************************************************************
** Form generated from reading UI file 'bookclassifymanager.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKCLASSIFYMANAGER_H
#define UI_BOOKCLASSIFYMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookClassifyManager
{
public:
    QPushButton *AddpushButton;
    QFrame *line;
    QPushButton *AllpushButton;
    QPushButton *DeletepushButton;
    QPushButton *SurepushButton;
    QTableView *BookInformationtableView;
    QLabel *Title;
    QPushButton *SearchpushButton;
    QLabel *label;
    QComboBox *BookTypedepcbBox;

    void setupUi(QWidget *BookClassifyManager)
    {
        if (BookClassifyManager->objectName().isEmpty())
            BookClassifyManager->setObjectName("BookClassifyManager");
        BookClassifyManager->resize(1000, 700);
        AddpushButton = new QPushButton(BookClassifyManager);
        AddpushButton->setObjectName("AddpushButton");
        AddpushButton->setGeometry(QRect(20, 90, 71, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setItalic(true);
        AddpushButton->setFont(font);
        line = new QFrame(BookClassifyManager);
        line->setObjectName("line");
        line->setGeometry(QRect(20, 70, 961, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        AllpushButton = new QPushButton(BookClassifyManager);
        AllpushButton->setObjectName("AllpushButton");
        AllpushButton->setGeometry(QRect(510, 40, 71, 31));
        AllpushButton->setFont(font);
        DeletepushButton = new QPushButton(BookClassifyManager);
        DeletepushButton->setObjectName("DeletepushButton");
        DeletepushButton->setGeometry(QRect(970, 9, 20, 16));
        SurepushButton = new QPushButton(BookClassifyManager);
        SurepushButton->setObjectName("SurepushButton");
        SurepushButton->setGeometry(QRect(910, 650, 71, 31));
        SurepushButton->setFont(font);
        BookInformationtableView = new QTableView(BookClassifyManager);
        BookInformationtableView->setObjectName("BookInformationtableView");
        BookInformationtableView->setGeometry(QRect(20, 130, 961, 511));
        Title = new QLabel(BookClassifyManager);
        Title->setObjectName("Title");
        Title->setGeometry(QRect(0, 0, 1001, 31));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        Title->setFont(font1);
        SearchpushButton = new QPushButton(BookClassifyManager);
        SearchpushButton->setObjectName("SearchpushButton");
        SearchpushButton->setGeometry(QRect(430, 40, 71, 31));
        SearchpushButton->setFont(font);
        label = new QLabel(BookClassifyManager);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 81, 22));
        QFont font2;
        font2.setPointSize(13);
        label->setFont(font2);
        BookTypedepcbBox = new QComboBox(BookClassifyManager);
        BookTypedepcbBox->setObjectName("BookTypedepcbBox");
        BookTypedepcbBox->setGeometry(QRect(100, 50, 291, 21));

        retranslateUi(BookClassifyManager);

        QMetaObject::connectSlotsByName(BookClassifyManager);
    } // setupUi

    void retranslateUi(QWidget *BookClassifyManager)
    {
        BookClassifyManager->setWindowTitle(QCoreApplication::translate("BookClassifyManager", "Form", nullptr));
        AddpushButton->setText(QCoreApplication::translate("BookClassifyManager", "\346\267\273\345\212\240\342\236\225", nullptr));
        AllpushButton->setText(QCoreApplication::translate("BookClassifyManager", "\345\205\250\351\203\250", nullptr));
        DeletepushButton->setText(QCoreApplication::translate("BookClassifyManager", "\303\227", nullptr));
        SurepushButton->setText(QCoreApplication::translate("BookClassifyManager", "\347\241\256\350\256\244\342\234\224", nullptr));
        Title->setText(QCoreApplication::translate("BookClassifyManager", "  \345\233\276\344\271\246\345\210\206\347\261\273\347\256\241\347\220\206", nullptr));
        SearchpushButton->setText(QCoreApplication::translate("BookClassifyManager", "\346\237\245\350\257\242\360\237\224\215", nullptr));
        label->setText(QCoreApplication::translate("BookClassifyManager", "\345\233\276\344\271\246\347\261\273\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookClassifyManager: public Ui_BookClassifyManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKCLASSIFYMANAGER_H
