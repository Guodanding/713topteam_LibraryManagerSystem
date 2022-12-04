#include "mainwindow.h"
#include "bookinformationmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //BookManager BookManager;
    //BookManager.show();
    return a.exec();
}
