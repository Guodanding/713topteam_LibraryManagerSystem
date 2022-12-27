#include "mainwindow.h"
#include "splashscreen.h"//启动动画
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //启动动画
    QPixmap pixmap(":/images/start.png");
    QPixmap pixmap1;
    pixmap1 = pixmap.scaled(600, 350);
    SplashScreen splash(pixmap1);
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
    return a.exec();
}
