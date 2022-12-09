#include "bookinformationmanager.h"
#include "ui_bookinformationmanager.h"
#include "bookinformationmanageradddatadialog.h"
#include <QStyle>

BookManager::BookManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookManager)
{
    ui->setupUi(this);
    setWindowTitle("图书信息管理模块");
    setWinStyle();
}

BookManager::~BookManager()
{
    delete ui;
}

void BookManager::setWinStyle()
{
    ui->AddpushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#FFA500;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FF8C00;"
                "color:white;"
                "}");
    ui->SearchpushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#FFD700;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FF8C00;"
                "color:white;"
                "}");
    ui->SurepushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#FF0000;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FF8C00;"
                "color:white;"
                "}");
    ui->CanclepushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#8470FF;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FF8C00;"
                "color:white;"
                "}");
    ui->DeletepushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#8470FF;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FF8C00;"
                "color:white;"
                "}");
    ui->BookInformationManagerTitle->setStyleSheet(
                "QLabel{"
                "background-color:#DDDDDD;"
                "}");
    ui->BookIDlineEdit->setPlaceholderText("请输入图书ID");
    ui->BookNamelineEdit->setPlaceholderText("请输入图书名");
    ui->WriterNamelineEdit->setPlaceholderText("请输入作者名");
}

void BookManager::on_AddpushButton_clicked()
{
    BookInformationManagerAddDataDialog BookInformationManagerAddDataDialog(this);
    BookInformationManagerAddDataDialog.exec();
}

//ui->BookIDlineEdit->setPlaceholderText("请输入图书ID");
//ui->BookNamelineEdit->setPlaceholderText("请输入图书名");
//ui->BookWriterlineEdit->setPlaceholderText("请输入作者名");
/*ui->Title->setStyleSheet(
            "QLabel{"
            "background-color:#333333;"
            "color:white;"
            "}");
ui->ReturnpushButton->setStyleSheet(   //正常状态样式
            "QPushButton{"
            "background-color:#222222;"
            "color:#DDDDDD;"
            "}"
            //鼠标悬停样式
            "QPushButton:hover{"
            "background-color:#444444;"
            "color:white;"
            "}");
ui->AddpushButton->setStyleSheet(
            "QPushButton{"
            "background-color:#FFA500;"
            "border-radius:3px;"//设置圆角半径
            "color:white;"
            "}"
            "QPushButton:hover{"
            "background-color:#FF8C00;"
            "color:white;"
            "}");
ui->SearchpushButton->setStyleSheet(
            "QPushButton{"
            "background-color:#FFD700;"
            "border-radius:3px;"//设置圆角半径
            "color:white;"
            "}"
            "QPushButton:hover{"
            "background-color:#FF8C00;"
            "color:white;"
            "}");
ui->SurepushButton->setStyleSheet(
            "QPushButton{"
            "background-color:#FF0000;"
            "border-radius:3px;"//设置圆角半径
            "color:white;"
            "}"
            "QPushButton:hover{"
            "background-color:#FF8C00;"
            "color:white;"
            "}");
ui->CanclepushButton->setStyleSheet(
            "QPushButton{"
            "background-color:#8470FF;"
            "border-radius:3px;"//设置圆角半径
            "color:white;"
            "}"
            "QPushButton:hover{"
            "background-color:#FF8C00;"
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
            "}");*/

void BookManager::on_DeletepushButton_clicked()
{
    this->~BookManager();
}

