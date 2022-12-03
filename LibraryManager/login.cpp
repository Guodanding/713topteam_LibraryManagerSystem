#include "login.h"
#include "ui_login.h"
#include"QGraphicsDropShadowEffect"//图片阴影
#include"dboperator.h"//引入数据库
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
    //用户名密码登录
    DBOperator database;
    database.DBOpen();

}

Login::~Login()
{
    delete ui;
}
