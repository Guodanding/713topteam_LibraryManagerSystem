#include "mainwindow.h"
#include "bookinformationmanagermainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //BookInformationManagerMainWindow BookInformationManager;
    //BookInformationManager.show();
    MainWindow w;
    w.show();
    return a.exec();
}
