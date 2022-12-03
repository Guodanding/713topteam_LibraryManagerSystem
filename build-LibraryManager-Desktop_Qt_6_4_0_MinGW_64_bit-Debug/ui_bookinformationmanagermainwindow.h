/********************************************************************************
** Form generated from reading UI file 'bookinformationmanagermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINFORMATIONMANAGERMAINWINDOW_H
#define UI_BOOKINFORMATIONMANAGERMAINWINDOW_H

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
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BookInformationManagerMainWindow)
    {
        if (BookInformationManagerMainWindow->objectName().isEmpty())
            BookInformationManagerMainWindow->setObjectName("BookInformationManagerMainWindow");
        BookInformationManagerMainWindow->resize(800, 600);
        menubar = new QMenuBar(BookInformationManagerMainWindow);
        menubar->setObjectName("menubar");
        BookInformationManagerMainWindow->setMenuBar(menubar);
        centralwidget = new QWidget(BookInformationManagerMainWindow);
        centralwidget->setObjectName("centralwidget");
        BookInformationManagerMainWindow->setCentralWidget(centralwidget);
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

#endif // UI_BOOKINFORMATIONMANAGERMAINWINDOW_H
