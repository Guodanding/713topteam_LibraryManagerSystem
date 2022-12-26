#include "signup.h"
#include"login.h"
#include "ui_signup.h"
#include"QGraphicsDropShadowEffect"//图片阴影
#include "QMessageBox"//消息盒子
#include "QRegularExpression"//正则表达式
SignUP::SignUP(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUP)
{
    ui->setupUi(this);
    //设置图片背景
    QPixmap *pix =new QPixmap(":/images/registerBackground.jpg");
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
    QString username = ui->lineEdit_username->text().trimmed();
    QString name = ui->lineEdit_name->text();
    QString password = ui->lineEdit_password->text().trimmed();
    QString repassword = ui->lineEdit_repassword->text().trimmed();
    QString phone = ui->lineEdit_phone->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();
    //检查环节
    bool flagComplete=username.isEmpty()||name.isEmpty()||password.isEmpty()||phone.isEmpty()||email.isEmpty();
    if (flagComplete) {//输入数据不全
        QMessageBox::information(this,"注册认证","请完整填写信息，谢谢！");
    }
    else {
        if(isRePasswordValid)//两次密码一致
        {
            if (isPasswordValid&&isEmailValid&&isPhoneValid&&isUsernameValid){
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
            }else {
                QMessageBox::information(this,"注册认证","您输入的数据不符合规范");
            }

        }
        else//两次密码不一致
        {
            QMessageBox::information(this,"注册认证","两次密码输入不一致！");
        }
    }
}

void SignUP::on_lineEdit_email_textChanged(const QString &arg1)
{
    QRegularExpression regExp("^[A-Za-z0-9]+([_\\.][A-Za-z0-9]+)*@([A-Za-z0-9\\-]+\\.)+[A-Za-z]{2,6}$");//正则表达式
    QRegularExpressionMatch dateMatch;
    dateMatch= regExp.match(ui->lineEdit_email->text());
    isEmailValid=dateMatch.hasMatch();
    if (isEmailValid) {
        QPixmap pixmap(":/images/right.ico");
        QPixmap pixmap1;
        pixmap1 = pixmap.scaled(25, 25);
        ui->label_sign_email->setPixmap(pixmap1);
    }
    else{
        QPixmap pixmap(":/images/wrong.ico");
        QPixmap pixmap1;
        pixmap1 = pixmap.scaled(25, 25);
        ui->label_sign_email->setPixmap(pixmap1);
    }
}


void SignUP::on_lineEdit_phone_textChanged(const QString &arg1)
{
    QRegularExpression regExp("^1\\d{10}$");//正则表达式
    QRegularExpressionMatch dateMatch;
    dateMatch= regExp.match(ui->lineEdit_phone->text());
    isPhoneValid=dateMatch.hasMatch();
    if (isPhoneValid) {
        QPixmap pixmap(":/images/right.ico");
        QPixmap pixmap1;
        pixmap1 = pixmap.scaled(25, 25);
        ui->label_sign_phone->setPixmap(pixmap1);
    }
    else{
        QPixmap pixmap(":/images/wrong.ico");
        QPixmap pixmap1;
        pixmap1 = pixmap.scaled(25, 25);
        ui->label_sign_phone->setPixmap(pixmap1);
    }
}


void SignUP::on_lineEdit_repassword_textChanged(const QString &arg1)
{
    QString password = ui->lineEdit_password->text().trimmed();
    QString repassword = ui->lineEdit_repassword->text().trimmed();
    if (password==repassword) {
        isRePasswordValid=true;
    }else{
        isRePasswordValid=false;
    }
    if (isRePasswordValid) {
        QPixmap pixmap(":/images/right.ico");
        QPixmap pixmap1;
        pixmap1 = pixmap.scaled(25, 25);
        ui->label_sign_repassword->setPixmap(pixmap1);
    }
    else{
        QPixmap pixmap(":/images/wrong.ico");
        QPixmap pixmap1;
        pixmap1 = pixmap.scaled(25, 25);
        ui->label_sign_repassword->setPixmap(pixmap1);
    }
}

void SignUP::on_lineEdit_password_textChanged(const QString &arg1)
{
    QString password = ui->lineEdit_password->text().trimmed();
    QRegularExpression regExp("^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{8,16}$");//正则表达式
    QRegularExpressionMatch dateMatch;
    dateMatch= regExp.match(password);
    isPasswordValid=dateMatch.hasMatch();
    if (isPasswordValid) {
        QPixmap pixmap(":/images/right.ico");
        QPixmap pixmap1;
        pixmap1 = pixmap.scaled(25, 25);
        ui->label_sign_password->setPixmap(pixmap1);
    }
    else{
        QPixmap pixmap(":/images/wrong.ico");
        QPixmap pixmap1;
        pixmap1 = pixmap.scaled(25, 25);
        ui->label_sign_password->setPixmap(pixmap1);
    }
}


void SignUP::on_lineEdit_username_textChanged(const QString &arg1)
{
    QRegularExpression regExp("^[0-9a-zA-Z_]{4,16}$");//正则表达式
    QRegularExpressionMatch dateMatch;
    dateMatch= regExp.match(ui->lineEdit_username->text());
    isUsernameValid=dateMatch.hasMatch();
    if (isUsernameValid) {
        QPixmap pixmap(":/images/right.ico");
        QPixmap pixmap1;
        pixmap1 = pixmap.scaled(25, 25);
        ui->label_sign_username->setPixmap(pixmap1);
    }
    else{
        QPixmap pixmap(":/images/wrong.ico");
        QPixmap pixmap1;
        pixmap1 = pixmap.scaled(25, 25);
        ui->label_sign_username->setPixmap(pixmap1);
    }
}

