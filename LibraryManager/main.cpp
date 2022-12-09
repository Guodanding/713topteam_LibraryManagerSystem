#include "mainwindow.h"
#include "bookinformationmanager.h"
#include "bookclassifymanager.h"
#include "managermainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    BookManager BookManager;
    BookManager.show();
    //BookClassifyManager BookClassify;
    //BookClassify.show();
    //ManagerMainWindow Managermainwindow;
    //Managermainwindow.show();
    return a.exec();
}
