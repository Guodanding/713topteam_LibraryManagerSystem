/********************************************************************************
** Form generated from reading UI file 'managermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGERMAINWINDOW_H
#define UI_MANAGERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManagerMainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QTreeWidget *treeWidget;
    QLabel *label_bacgroud;

    void setupUi(QMainWindow *ManagerMainWindow)
    {
        if (ManagerMainWindow->objectName().isEmpty())
            ManagerMainWindow->setObjectName("ManagerMainWindow");
        ManagerMainWindow->resize(1200, 800);
        ManagerMainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(ManagerMainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(160, 30, 1000, 700));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(20, 80, 121, 391));
        treeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_bacgroud = new QLabel(centralwidget);
        label_bacgroud->setObjectName("label_bacgroud");
        label_bacgroud->setGeometry(QRect(0, 0, 1200, 800));
        label_bacgroud->setStyleSheet(QString::fromUtf8(""));
        ManagerMainWindow->setCentralWidget(centralwidget);
        label_bacgroud->raise();
        stackedWidget->raise();
        treeWidget->raise();

        retranslateUi(ManagerMainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ManagerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ManagerMainWindow)
    {
        ManagerMainWindow->setWindowTitle(QCoreApplication::translate("ManagerMainWindow", "MainWindow", nullptr));
        label_bacgroud->setText(QCoreApplication::translate("ManagerMainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManagerMainWindow: public Ui_ManagerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGERMAINWINDOW_H
