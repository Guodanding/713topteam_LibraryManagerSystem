#include "userprofilemanager.h"
#include "ui_userprofilemanager.h"
#include "QMovie"
#include <QSqlRecord>
#include "QMessageBox"
UserProfileManager::UserProfileManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserProfileManager)
{
    ui->setupUi(this);
    // 显示gif图片
    ui->label_gif->setWindowFlag(Qt::FramelessWindowHint);// 设置无边框
    ui->label_gif->setWindowOpacity(0.9);// 设置透明度
    static QMovie movie(":/images/rain.gif");
    ui->label_gif->setMovie(&movie);
    ui->label_gif->setScaledContents(true);
    movie.start();

    ui->SureButton->setStyleSheet(
                "QPushButton{"
                "background-color:#FF0000;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#8B4513;"
                "color:white;"
                "}");
}

UserProfileManager::~UserProfileManager()
{
    delete ui;
}

void UserProfileManager::setusername(QString _username)
{
    Username = _username;

    model = new QSqlTableModel();
    model->setTable("user");//选择表
    model->setFilter(QObject::tr("username = '%1'").arg(Username));
    model->select();

    QSqlRecord record = model->record(0);
    qDebug() << model->rowCount();
    QString username = record.value("username").toString();
    QString name = record.value("name").toString();
    QString password = record.value("password").toString();
    QString email = record.value("email").toString();
    QString phone = record.value("phone").toString();

    ui->usernamelineEdit->setText(username);
    ui->namelineEdit->setText(name);
    ui->passwordlineEdit->setText(password);
    ui->emaillineEdit->setText(email);
    ui->phonelineEdit->setText(phone);
}

void UserProfileManager::on_AddpushButton_clicked()
{
    if(ui->usernamelineEdit->text().isEmpty() || ui->emaillineEdit->text().isEmpty() ||
       ui->namelineEdit->text().isEmpty() || ui->passwordlineEdit->text().isEmpty() ||
       ui->phonelineEdit->text().isEmpty())
    {
        QMessageBox::StandardButton result = QMessageBox::warning(this, "错误", "请输入完整信息！");
        if(result == QMessageBox::Ok)
            return;
    }
    else
    {
        QMessageBox::StandardButton result = QMessageBox::question(this, "修改个人信息","是否确认修改");

        if(result == QMessageBox::Yes)
        {
            QString username = ui->usernamelineEdit->text();
            QString name = ui->namelineEdit->text();
            QString password = ui->passwordlineEdit->text();
            QString email = ui->emaillineEdit->text();
            QString phone =  ui->phonelineEdit->text();

            model->setData(model->index(0, 1), QVariant(username));
            model->setData(model->index(0, 2), QVariant(name));
            model->setData(model->index(0, 3), QVariant(password));
            model->setData(model->index(0, 4), QVariant(phone));
            model->setData(model->index(0, 5), QVariant(email));

            model->submitAll();
        }
        else;
    }
    model = new QSqlTableModel();
    model->setTable("user");//选择表
    model->setFilter(QObject::tr("username = '%1'").arg(Username));
    model->select();

    QSqlRecord record = model->record(0);
    qDebug() << model->rowCount();
    QString username = record.value("username").toString();
    QString name = record.value("name").toString();
    QString password = record.value("password").toString();
    QString email = record.value("email").toString();
    QString phone = record.value("phone").toString();

    ui->usernamelineEdit->setText(username);
    ui->namelineEdit->setText(name);
    ui->passwordlineEdit->setText(password);
    ui->emaillineEdit->setText(email);
    ui->phonelineEdit->setText(phone);
}

