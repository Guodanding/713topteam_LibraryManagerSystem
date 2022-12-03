#include "signup.h"
#include"login.h"
#include "ui_signup.h"
#include"QGraphicsDropShadowEffect"//图片阴影
#include "QMessageBox"//消息盒子
SignUP::SignUP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUP)
{
    ui->setupUi(this);
    //设置图片背景
    QPixmap *pix =new QPixmap(":/images/registerBackground.png");
    QSize size=ui->label_image->size();
    ui->label_image->setPixmap(pix->scaled(size));
}

SignUP::~SignUP()
{
    delete ui;
}

void SignUP::on_pushButton_return_clicked()//回到登录界面
{
    this->close();
    Login *login=new Login();
    login->show();
}


void SignUP::on_pushButton_register_clicked()//确认注册
{
    //获取用户输入数据
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString repassword = ui->lineEdit_repassword->text();
    //判断两次密码是否一致
    if(password == repassword)//两次密码一致
    {
        QString sql_signup=QString("INSERT INTO admin(username,password) VALUES('%1','%2');")
                .arg(username).arg(password);
        QSqlQuery query;
        //判断语句结果是否成功
        if(query.exec(sql_signup))
        {
            qDebug()<<"insert into success";
            QMessageBox::information(this,"注册认证","插入成功！");
            on_pushButton_return_clicked();//回到登录界面
        }
        else
        {
            qDebug()<<"insert into error";
        }
    }
    else//两次密码不一致
    {
        QMessageBox::information(this,"注册认证","两次密码输入不一致！");
    }
}


