#include "bookmanager.h"
#include "ui_bookmanager.h"
#include <QStyle>

BookManager::BookManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookManager)
{
    ui->setupUi(this);
    setWindowTitle("图书管理模块");
    setWinStyle();
}

BookManager::~BookManager()
{
    delete ui;
}

void BookManager::setWinStyle()
{
    ui->Title->setStyleSheet(
                "QLabel{"
                "background-color:#222222;"
                "color:white;"
                "}");
    ui->BookInformationpushButton->setStyleSheet(   //正常状态样式
                "QPushButton{"
                "border-radius:5px;"//设置圆角半径
                "background-color:#222222;"
                "color:#DDDDDD;"
                "}"
                //鼠标悬停样式
                "QPushButton:hover{"
                "background-color:#444444;"
                "color:white;"
                "}");
    ui->BookClassifypushButton->setStyleSheet(   //正常状态样式
                "QPushButton{"
                "border-radius:5px;"//设置圆角半径
                "background-color:#222222;"
                "color:#DDDDDD;"
                "}"
                //鼠标悬停样式
                "QPushButton:hover{"
                "background-color:#444444;"
                "color:white;"
                "}");
    ui->Manager->setStyleSheet(
                "QLabel{"
                "background-color:white;"
                "}");
    ui->DataWidget->setStyleSheet(
                "QWidget{"
                "background-color:white;"
                "}");
    ui->BookInformationManagerTitle->setStyleSheet(
                "QLabel{"
                "background-color:#DDDDDD;"
                "}");

}
