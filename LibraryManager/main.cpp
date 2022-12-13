#include "mainwindow.h"
#include "splashscreen.h"//启动动画
#include "bookinformationmanager.h"
#include "bookclassifymanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    //启动动画
    QPixmap pixmap(":/images/loginBackground.png");
    SplashScreen splash(pixmap);
    splash.setRange(0,10);//设置进度条内容长度
    splash.show();
    int i=0;
    while(i<=10){
        splash.updateNum(i);
        i++;
    }
    //splash.processEvents();
    MainWindow w;
    w.show();
    splash.finish(&splash);
    //BookManager bookmanager;
    //bookmanager.show();
    //BookClassifyManager bookclassify;
    //bookclassify.show();
    return a.exec();
}
