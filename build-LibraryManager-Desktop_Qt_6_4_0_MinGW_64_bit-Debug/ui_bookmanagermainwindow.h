/********************************************************************************
** Form generated from reading UI file 'bookmanagermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKMANAGERMAINWINDOW_H
#define UI_BOOKMANAGERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookInformationManagerMainWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BookInformationManagerMainWindow)
    {
        if (BookInformationManagerMainWindow->objectName().isEmpty())
            BookInformationManagerMainWindow->setObjectName("BookInformationManagerMainWindow");
        BookInformationManagerMainWindow->resize(1000, 800);
        centralwidget = new QWidget(BookInformationManagerMainWindow);
        centralwidget->setObjectName("centralwidget");
        BookInformationManagerMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BookInformationManagerMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 17));
        BookInformationManagerMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(BookInformationManagerMainWindow);
        statusbar->setObjectName("statusbar");
        BookInformationManagerMainWindow->setStatusBar(statusbar);

        retranslateUi(BookInformationManagerMainWindow);

        QMetaObject::connectSlotsByName(BookInformationManagerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BookInformationManagerMainWindow)
    {
        BookInformationManagerMainWindow->setWindowTitle(QCoreApplication::translate("BookInformationManagerMainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookInformationManagerMainWindow: public Ui_BookInformationManagerMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKMANAGERMAINWINDOW_H