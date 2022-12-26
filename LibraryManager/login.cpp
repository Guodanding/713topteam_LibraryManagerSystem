#include "login.h"
#include"signup.h"
#include "ui_login.h"
#include"QGraphicsDropShadowEffect"//图片阴影
#include "QMessageBox"//消息盒子
#include "managermainwindow.h"//主窗口
#include "QMovie"
#include"QTime"
#include <windows.h>
Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //设置图片背景
    QPixmap *pix =new QPixmap(":/images/loginBackground.jpg");
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
    static QMovie movie(":/images/login.gif");
    ui->label_gif->setMovie(&movie);
    ui->label_gif->setScaledContents(true);
    movie.start();
    //style
    ui->radioButton_user->setStyleSheet(
                "QRadioButton{"
                    "font: 10pt 'Microsoft YaHei UI';"
                    "spacing: 2px;"
                    "color: black;"
                "}"
                "QRadioButton::indicator {"
                    "width: 45px;"
                    "height: 30px;"
                "}"
                "QRadioButton::indicator:unchecked {"
                    "image: url(:/images/radio_button_left.png);"
                "}"
                "QRadioButton::indicator:unchecked:pressed {"
                    "image: url(:/images/radio_button_right.png);"
                "}"
                "QRadioButton::indicator:checked {"
                     "image: url(:/images/radio_button_right.png);"
                "}"
                "QRadioButton::indicator:checked:pressed {"
                     "image: url(:/images/radio_button_left.png);"
                "}");
    ui->radioButton_admin->setStyleSheet(
                "QRadioButton{"
                    "font: 10pt 'Microsoft YaHei UI';"
                    "spacing: 2px;"
                    "color: black;"
                "}"
                "QRadioButton::indicator {"
                    "width: 45px;"
                    "height: 30px;"
                "}"
                "QRadioButton::indicator:unchecked {"
                    "image: url(:/images/radio_button_left.png);"
                "}"
                "QRadioButton::indicator:unchecked:pressed {"
                    "image: url(:/images/radio_button_right.png);"
                "}"
                "QRadioButton::indicator:checked {"
                     "image: url(:/images/radio_button_right.png);"
                "}"
                "QRadioButton::indicator:checked:pressed {"
                     "image: url(:/images/radio_button_left.png);"
                "}");
}

Login::~Login()
{
    delete ui;
    //关闭数据库
    database.DBClose();
}

void Login::on_Button_login_clicked()//登录操作判断
{
    if (isUserSelected) {//用户登录
        QString username = ui->lineEdit_username->text();
        QString password = ui->lineEdit_password->text();
        QString sqlstr=QString("SELECT username,password FROM user WHERE username='%1' AND password='%2';")
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
            ManagerMainWindow *Managermainwindow=new ManagerMainWindow(0,this);
            Managermainwindow->setUsername(username);
            Managermainwindow->show();
            this->close();
        }
    }
    else if (isAdminSelected) {//管理员登录
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
            ManagerMainWindow *Managermainwindow=new ManagerMainWindow(1,this);
            Managermainwindow->setAdminname(username);
            Managermainwindow->show();
            this->close();
        }
    }
    else{
        QMessageBox::information(this,"登录认证","请选择您是管理员或用户");
    }
}

void Login::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_CapsLock) {
        if(LOBYTE(GetKeyState(VK_CAPITAL))) {
            ui->label_tip->setText("大写锁定已打开");
        }
        else {
            ui->label_tip->setText("大写锁定未打开");
        }
    }
    QWidget::keyPressEvent(event);
}

void Login::keyReleaseEvent( QKeyEvent * event)
{
    if(event->key() == Qt::Key_CapsLock) {
        if(LOBYTE(GetKeyState(VK_CAPITAL))) {
            ui->label_tip->setText("大写锁定已打开");
        }
        else {
            ui->label_tip->setText("大写锁定未打开");
        }
    }
    QWidget::keyReleaseEvent(event);
}

void Login::on_Button_signup_clicked()//进入注册界面
{
    this->close();
    SignUP *signup=new SignUP();
    signup->show();
}

void Login::on_radioButton_user_clicked()
{
    isUserSelected=true;
    isAdminSelected=false;
}

void Login::on_radioButton_admin_clicked()
{
    isAdminSelected=true;
    isUserSelected=false;
}

void Login::on_lineEdit_username_returnPressed()
{
    ui->lineEdit_username->grabKeyboard();
}


void Login::on_lineEdit_password_returnPressed()
{
    ui->lineEdit_password->grabKeyboard();
}



