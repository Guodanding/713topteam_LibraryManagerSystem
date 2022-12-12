#include "userprofilemanager.h"
#include "ui_userprofilemanager.h"
#include "QMovie"
UserProfileManager::UserProfileManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserProfileManager)
{
    ui->setupUi(this);
    // 显示gif图片
    ui->label_gif->setWindowFlag(Qt::FramelessWindowHint);// 设置无边框
    ui->label_gif->setWindowOpacity(0.9);// 设置透明度
    static QMovie movie(":/images/8.gif");
    ui->label_gif->setMovie(&movie);
    ui->label_gif->setScaledContents(true);
    movie.start();
}

UserProfileManager::~UserProfileManager()
{
    delete ui;
}
