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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookManager
{
public:
    QLabel *Manager;
    QFrame *line;
    QWidget *DataWidget;
    QLabel *BookInformationManagerTitle;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *Title;
    QPushButton *BookInformationpushButton;
    QPushButton *BookClassifypushButton;

    void setupUi(QWidget *BookManager)
    {
        if (BookManager->objectName().isEmpty())
            BookManager->setObjectName("BookManager");
        BookManager->resize(1000, 600);
        QFont font;
        font.setPointSize(25);
        BookManager->setFont(font);
        Manager = new QLabel(BookManager);
        Manager->setObjectName("Manager");
        Manager->setGeometry(QRect(210, -1, 791, 31));
        QFont font1;
        font1.setPointSize(10);
        Manager->setFont(font1);
        line = new QFrame(BookManager);
        line->setObjectName("line");
        line->setGeometry(QRect(210, 20, 811, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        DataWidget = new QWidget(BookManager);
        DataWidget->setObjectName("DataWidget");
        DataWidget->setGeometry(QRect(220, 40, 771, 541));
        BookInformationManagerTitle = new QLabel(DataWidget);
        BookInformationManagerTitle->setObjectName("BookInformationManagerTitle");
        BookInformationManagerTitle->setGeometry(QRect(0, 0, 771, 31));
        QFont font2;
        font2.setPointSize(13);
        BookInformationManagerTitle->setFont(font2);
        widget = new QWidget(BookManager);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 211, 601));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 10);
        Title = new QLabel(widget);
        Title->setObjectName("Title");
        QFont font3;
        font3.setPointSize(22);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        font3.setKerning(true);
        Title->setFont(font3);
        Title->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(Title);

        BookInformationpushButton = new QPushButton(widget);
        BookInformationpushButton->setObjectName("BookInformationpushButton");
        QFont font4;
        font4.setPointSize(20);
        BookInformationpushButton->setFont(font4);

        verticalLayout->addWidget(BookInformationpushButton);

        BookClassifypushButton = new QPushButton(widget);
        BookClassifypushButton->setObjectName("BookClassifypushButton");
        BookClassifypushButton->setFont(font4);

        verticalLayout->addWidget(BookClassifypushButton);


        retranslateUi(BookManager);

        QMetaObject::connectSlotsByName(BookManager);
    } // setupUi

    void retranslateUi(QWidget *BookManager)
    {
        BookManager->setWindowTitle(QCoreApplication::translate("BookManager", "Form", nullptr));
        Manager->setText(QCoreApplication::translate("BookManager", "                                                                                                                                                                                       \347\256\241\347\220\206\345\221\230\357\274\232gkb", nullptr));
        BookInformationManagerTitle->setText(QCoreApplication::translate("BookManager", "  \345\233\276\344\271\246\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        Title->setText(QCoreApplication::translate("BookManager", "  \345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        BookInformationpushButton->setText(QCoreApplication::translate("BookManager", "\345\233\276\344\271\246\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        BookClassifypushButton->setText(QCoreApplication::translate("BookManager", "\345\233\276\344\271\246\345\210\206\347\261\273\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookManager: public Ui_BookManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKMANAGER_H
