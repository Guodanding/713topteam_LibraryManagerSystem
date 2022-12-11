#include "login.h"
#include"signup.h"
#include "ui_login.h"
#include"QGraphicsDropShadowEffect"//图片阴影
#include "QMessageBox"//消息盒子
#include "managermainwindow.h"//主窗口
#include "QMovie"
#include"QTime"
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //设置图片背景
    QPixmap *pix =new QPixmap(":/images/loginBackground.png");
    QSize size=ui->label_image->size();
    ui->label_image->setPixmap(pix->scaled(size));
    //设置图片阴影效果
    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect(this);
    shadow->setOffset(6, 0);
    shadow->setColor(QColor("#CCCCCC"));
    shadow->setBlurRadius(60);
    ui->label_image->setGraphicsEffect(shadow);
    //连接数据库
    database.DBOpen();
    // 显示gif图片
    ui->label_gif->setWindowFlag(Qt::FramelessWindowHint);// 设置无边框
    ui->label_gif->setWindowOpacity(0.9);// 设置透明度
    static QMovie movie(":/images/2.gif");
    ui->label_gif->setMovie(&movie);
    ui->label_gif->setScaledContents(true);
    movie.start();
    // 设置延迟时间
    //QTime time = QTime::currentTime().addMSecs(2000);
    //while (QTime::currentTime()<time) {
    //    QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    //
    // 停止
    //movie.stop();


}

Login::~Login()
{
    delete ui;
    //关闭数据库
    database.DBClose();
}

void Login::on_Button_login_clicked()//登录操作判断
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString sqlstr=QString("SELECT username,password FROM admin WHERE username='%1' AND password='%2';")
                .arg(username).arg(password);
    QSqlQuery query_if_login(sqlstr);
    //判断执行结果
    if(!query_if_login.next())
    {
        qDebug()<<"Login error";
        QMessageBox::information(this,"登录认证","登录失败,账户或者密码错误");
    }
    else
    {
        qDebug()<<"Login success";
        QMessageBox::information(this,"登录认证","登录成功");
        //登录成功后跳转到主窗口
        ManagerMainWindow *Managermainwindow=new ManagerMainWindow();
        Managermainwindow->show();
        this->close();
    }
}


void Login::on_Button_signup_clicked()//进入注册界面
{
    this->close();
    SignUP *signup=new SignUP();
    signup->show();
}

