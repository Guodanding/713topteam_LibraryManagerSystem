/********************************************************************************
** Form generated from reading UI file 'bookinformationmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINFORMATIONMANAGER_H
#define UI_BOOKINFORMATIONMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookManager
{
public:
    QFrame *line;
    QLabel *BookInformationManagerTitle;
    QPushButton *SearchpushButton;
    QPushButton *SurepushButton;
    QPushButton *AddpushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *BookID;
    QLineEdit *BookIDlineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *BookName;
    QLineEdit *BookNamelineEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *WriterName;
    QLineEdit *WriterNamelineEdit;
    QPushButton *DeletepushButton;
    QTableView *BookInformationtableView;
    QPushButton *AllpushButton;

    void setupUi(QWidget *BookManager)
    {
        if (BookManager->objectName().isEmpty())
            BookManager->setObjectName("BookManager");
        BookManager->resize(1000, 700);
        QFont font;
        font.setPointSize(10);
        BookManager->setFont(font);
        line = new QFrame(BookManager);
        line->setObjectName("line");
        line->setGeometry(QRect(20, 70, 961, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        BookInformationManagerTitle = new QLabel(BookManager);
        BookInformationManagerTitle->setObjectName("BookInformationManagerTitle");
        BookInformationManagerTitle->setGeometry(QRect(0, 0, 1001, 31));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        BookInformationManagerTitle->setFont(font1);
        SearchpushButton = new QPushButton(BookManager);
        SearchpushButton->setObjectName("SearchpushButton");
        SearchpushButton->setGeometry(QRect(770, 40, 71, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        SearchpushButton->setFont(font2);
        SurepushButton = new QPushButton(BookManager);
        SurepushButton->setObjectName("SurepushButton");
        SurepushButton->setGeometry(QRect(910, 650, 71, 31));
        SurepushButton->setFont(font2);
        AddpushButton = new QPushButton(BookManager);
        AddpushButton->setObjectName("AddpushButton");
        AddpushButton->setGeometry(QRect(20, 90, 71, 31));
        AddpushButton->setFont(font2);
        layoutWidget = new QWidget(BookManager);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 50, 701, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        BookID = new QLabel(layoutWidget);
        BookID->setObjectName("BookID");
        QFont font3;
        font3.setPointSize(13);
        BookID->setFont(font3);

        horizontalLayout->addWidget(BookID);

        BookIDlineEdit = new QLineEdit(layoutWidget);
        BookIDlineEdit->setObjectName("BookIDlineEdit");

        horizontalLayout->addWidget(BookIDlineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BookName = new QLabel(layoutWidget);
        BookName->setObjectName("BookName");
        BookName->setFont(font3);

        horizontalLayout->addWidget(BookName);

        BookNamelineEdit = new QLineEdit(layoutWidget);
        BookNamelineEdit->setObjectName("BookNamelineEdit");

        horizontalLayout->addWidget(BookNamelineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        WriterName = new QLabel(layoutWidget);
        WriterName->setObjectName("WriterName");
        WriterName->setFont(font3);

        horizontalLayout->addWidget(WriterName);

        WriterNamelineEdit = new QLineEdit(layoutWidget);
        WriterNamelineEdit->setObjectName("WriterNamelineEdit");

        horizontalLayout->addWidget(WriterNamelineEdit);

        DeletepushButton = new QPushButton(BookManager);
        DeletepushButton->setObjectName("DeletepushButton");
        DeletepushButton->setGeometry(QRect(970, 9, 20, 16));
        BookInformationtableView = new QTableView(BookManager);
        BookInformationtableView->setObjectName("BookInformationtableView");
        BookInformationtableView->setGeometry(QRect(20, 130, 961, 511));
        AllpushButton = new QPushButton(BookManager);
        AllpushButton->setObjectName("AllpushButton");
        AllpushButton->setGeometry(QRect(850, 40, 71, 31));
        AllpushButton->setFont(font2);

        retranslateUi(BookManager);

        QMetaObject::connectSlotsByName(BookManager);
    } // setupUi

    void retranslateUi(QWidget *BookManager)
    {
        BookManager->setWindowTitle(QCoreApplication::translate("BookManager", "Form", nullptr));
        BookInformationManagerTitle->setText(QCoreApplication::translate("BookManager", "  \345\233\276\344\271\246\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        SearchpushButton->setText(QCoreApplication::translate("BookManager", "\346\237\245\350\257\242\360\237\224\215", nullptr));
        SurepushButton->setText(QCoreApplication::translate("BookManager", "\347\241\256\350\256\244\342\234\224", nullptr));
        AddpushButton->setText(QCoreApplication::translate("BookManager", "\346\267\273\345\212\240\342\236\225", nullptr));
        BookID->setText(QCoreApplication::translate("BookManager", "\345\233\276\344\271\246ID", nullptr));
        BookName->setText(QCoreApplication::translate("BookManager", "\345\233\276\344\271\246\345\220\215\345\255\227", nullptr));
        WriterName->setText(QCoreApplication::translate("BookManager", "\344\275\234\350\200\205\345\220\215\345\255\227", nullptr));
        DeletepushButton->setText(QCoreApplication::translate("BookManager", "\303\227", nullptr));
        AllpushButton->setText(QCoreApplication::translate("BookManager", "\345\205\250\351\203\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookManager: public Ui_BookManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINFORMATIONMANAGER_H
