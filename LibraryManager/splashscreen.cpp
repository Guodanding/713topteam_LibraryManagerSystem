#include <QPixmap>
#include "splashscreen.h"
#include "QLabel"
SplashScreen::SplashScreen(QPixmap pixmap,QWidget *parent):QSplashScreen(pixmap)
{
    //installEventFilter(this);
    progressBar = new QProgressBar(this);
    progressBar->setAlignment(Qt::AlignCenter);
    // 设置进度条的位置
    progressBar->setGeometry(0,pixmap.height()*0.9,pixmap.width(),30);
    //text
    QLabel *label=new QLabel(this);
    label->setAlignment(Qt::AlignCenter);
    label->setText("欢迎使用713图书管理系统");
    label->setStyleSheet("font: 20pt 'Microsoft YaHei UI';");
    label->setGeometry(100,20,400,50);
}

void SplashScreen::setRange(int min,int max)
{
    progressBar->setRange(min,max);
}

void SplashScreen::updateNum(int n)
{
    qDebug()<<n;
    sleep(20);// 延迟时间
    progressBar->setValue(n);
}

void SplashScreen::sleep(int ms)
{
    QTime time = QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime()<time) {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

bool SplashScreen::eventFilter(QObject *watched, QEvent *event)
{
    //防止进度条被隐藏
    if(event->type()==QEvent::Type::MouseButtonPress || event->type()==QEvent::Type::MouseButtonDblClick)
    {
        return true;
    }
    return false;
}
