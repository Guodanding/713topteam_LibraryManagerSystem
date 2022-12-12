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
    //初始化sqlmodeltable
    model = new QSqlTableModel();
    model->setTable("user");//选择表admin
    model->select();//展示所有
    //获取用户输入数据
    QString username = ui->lineEdit_username->text();
    QString name = ui->lineEdit_name->text();
    QString password = ui->lineEdit_password->text();
    QString repassword = ui->lineEdit_repassword->text();
    QString phone = ui->lineEdit_phone->text();
    QString email = ui->lineEdit_email->text();
    //检查环节
    if(password == repassword)//两次密码一致
    {
        //检查是否已经存在用户名
        model->setFilter(QObject::tr("username = '%1'").arg(username)); //根据姓名进行筛选
        model->select();//选中
        if (model->rowCount()!=0) {
            QMessageBox::information(this,"注册认证","用户名已存在，请重新输入");
        }else {
            model->setFilter("");
            model->select();//选中
            int rowCount = model->rowCount();
            model->insertRow(rowCount);
            int curRow = rowCount;
            model->setData(model->index(curRow,0),curRow);
            model->setData(model->index(curRow,1),username);
            model->setData(model->index(curRow,2),name);
            model->setData(model->index(curRow,3),password);
            model->setData(model->index(curRow,4),phone);
            model->setData(model->index(curRow,5),email);
            //判断语句结果是否成功
            if(model->submitAll())
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
    }
    else//两次密码不一致
    {
        QMessageBox::information(this,"注册认证","两次密码输入不一致！");
    }
}


