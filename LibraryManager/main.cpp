#include "mainwindow.h"
#include "splashscreen.h"//启动动画
#include <QApplication>
#include "booksearch.h"
#include "bookinformationmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //启动动画
    QPixmap pixmap(":/images/loginBackground.png");
    SplashScreen splash(pixmap);
    splash.setRange(0,100);//设置进度条内容长度
    splash.show();
    int i=0;
    while(i<=100){
        splash.updateNum(i);
        i++;
    }
    //splash.processEvents();
    MainWindow w;
    splash.finish(&splash);
    /*BookSearch booksearch;
    booksearch.show();
    BookClassifyManager bookclassify;
    bookclassify.show();
    BookManager bookmanager;
    bookmanager.show();*/
    return a.exec();
}
