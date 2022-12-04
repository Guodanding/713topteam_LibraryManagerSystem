/********************************************************************************
** Form generated from reading UI file 'bookmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKMANAGER_H
#define UI_BOOKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookManager
{
public:
    QLabel *Manager;
    QFrame *line1;
    QWidget *DataWidget;
    QLabel *BookInformationManagerTitle;
    QPushButton *AddpushButton;
    QFrame *line;
    QPushButton *SearchpushButton;
    QTableView *tableView;
    QPushButton *SurepushButton;
    QPushButton *CanclepushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *BookIDlineEdit;
    QLabel *label_2;
    QLineEdit *BookNamelineEdit;
    QLabel *label_3;
    QLineEdit *BookWriterlineEdit;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *Title;
    QPushButton *ReturnpushButton;

    void setupUi(QWidget *BookManager)
    {
        if (BookManager->objectName().isEmpty())
            BookManager->setObjectName("BookManager");
        BookManager->resize(1200, 800);
        QFont font;
        font.setPointSize(10);
        BookManager->setFont(font);
        Manager = new QLabel(BookManager);
        Manager->setObjectName("Manager");
        Manager->setGeometry(QRect(210, 0, 991, 31));
        Manager->setFont(font);
        line1 = new QFrame(BookManager);
        line1->setObjectName("line1");
        line1->setGeometry(QRect(210, 20, 989, 16));
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Sunken);
        DataWidget = new QWidget(BookManager);
        DataWidget->setObjectName("DataWidget");
        DataWidget->setGeometry(QRect(250, 50, 911, 711));
        BookInformationManagerTitle = new QLabel(DataWidget);
        BookInformationManagerTitle->setObjectName("BookInformationManagerTitle");
        BookInformationManagerTitle->setGeometry(QRect(0, 0, 911, 31));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        BookInformationManagerTitle->setFont(font1);
        AddpushButton = new QPushButton(DataWidget);
        AddpushButton->setObjectName("AddpushButton");
        AddpushButton->setGeometry(QRect(20, 100, 71, 31));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        AddpushButton->setFont(font2);
        line = new QFrame(DataWidget);
        line->setObjectName("line");
        line->setGeometry(QRect(20, 80, 871, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        SearchpushButton = new QPushButton(DataWidget);
        SearchpushButton->setObjectName("SearchpushButton");
        SearchpushButton->setGeometry(QRect(590, 40, 71, 31));
        SearchpushButton->setFont(font2);
        tableView = new QTableView(DataWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 140, 871, 521));
        SurepushButton = new QPushButton(DataWidget);
        SurepushButton->setObjectName("SurepushButton");
        SurepushButton->setGeometry(QRect(820, 670, 71, 31));
        SurepushButton->setFont(font2);
        CanclepushButton = new QPushButton(DataWidget);
        CanclepushButton->setObjectName("CanclepushButton");
        CanclepushButton->setGeometry(QRect(730, 670, 71, 31));
        CanclepushButton->setFont(font2);
        widget = new QWidget(DataWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 40, 551, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font3;
        font3.setPointSize(12);
        label->setFont(font3);

        horizontalLayout->addWidget(label);

        BookIDlineEdit = new QLineEdit(widget);
        BookIDlineEdit->setObjectName("BookIDlineEdit");
        QFont font4;
        font4.setPointSize(10);
        font4.setItalic(false);
        BookIDlineEdit->setFont(font4);

        horizontalLayout->addWidget(BookIDlineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font3);

        horizontalLayout->addWidget(label_2);

        BookNamelineEdit = new QLineEdit(widget);
        BookNamelineEdit->setObjectName("BookNamelineEdit");
        BookNamelineEdit->setFont(font4);

        horizontalLayout->addWidget(BookNamelineEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font3);

        horizontalLayout->addWidget(label_3);

        BookWriterlineEdit = new QLineEdit(widget);
        BookWriterlineEdit->setObjectName("BookWriterlineEdit");
        BookWriterlineEdit->setFont(font4);

        horizontalLayout->addWidget(BookWriterlineEdit);

        widget1 = new QWidget(BookManager);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(0, 2, 211, 801));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 10);
        Title = new QLabel(widget1);
        Title->setObjectName("Title");
        QFont font5;
        font5.setPointSize(22);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setUnderline(false);
        font5.setStrikeOut(false);
        font5.setKerning(true);
        Title->setFont(font5);
        Title->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(Title);

        ReturnpushButton = new QPushButton(widget1);
        ReturnpushButton->setObjectName("ReturnpushButton");
        QFont font6;
        font6.setPointSize(20);
        ReturnpushButton->setFont(font6);

        verticalLayout->addWidget(ReturnpushButton);


        retranslateUi(BookManager);

        QMetaObject::connectSlotsByName(BookManager);
    } // setupUi

    void retranslateUi(QWidget *BookManager)
    {
        BookManager->setWindowTitle(QCoreApplication::translate("BookManager", "Form", nullptr));
        Manager->setText(QCoreApplication::translate("BookManager", "                                                                                                                                                                                                                                        \347\256\241\347\220\206\345\221\230\357\274\232gkb", nullptr));
        BookInformationManagerTitle->setText(QCoreApplication::translate("BookManager", "  \345\233\276\344\271\246\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        AddpushButton->setText(QCoreApplication::translate("BookManager", "\346\267\273\345\212\240\342\236\225", nullptr));
        SearchpushButton->setText(QCoreApplication::translate("BookManager", "\346\237\245\350\257\242\360\237\224\215", nullptr));
        SurepushButton->setText(QCoreApplication::translate("BookManager", "\347\241\256\350\256\244\342\234\224", nullptr));
        CanclepushButton->setText(QCoreApplication::translate("BookManager", "\345\210\240\351\231\244\342\235\214", nullptr));
        label->setText(QCoreApplication::translate("BookManager", "\345\233\276\344\271\246ID", nullptr));
        BookIDlineEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("BookManager", "\345\233\276\344\271\246\345\220\215", nullptr));
        BookNamelineEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("BookManager", "\345\233\276\344\271\246\344\275\234\350\200\205", nullptr));
        BookWriterlineEdit->setText(QString());
        Title->setText(QCoreApplication::translate("BookManager", "  \345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        ReturnpushButton->setText(QCoreApplication::translate("BookManager", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookManager: public Ui_BookManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKMANAGER_H
