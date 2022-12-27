#include "readermanager.h"
#include "ui_readermanager.h"
#include "readerinformationmanageradddatadialog.h"
#include "readerinformationmanagermodifydialog.h"
#include <QStyle>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QString>
#include <QSqlRecord>

readerManager::readerManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::readerManager)
{
    ui->setupUi(this);
    setWindowTitle("读者信息管理模块");
    setWinStyle();
    databaseOperate();
}

readerManager::~readerManager()
{
    delete ui;
}

void readerManager::setWinStyle()
{
    ui->readerInformationtableView->setAlternatingRowColors(true); // 表格数据行隔行变色
    ui->readerInformationtableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单个数据格
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
    ui->AllpushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#87CEFA;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#1E90FF;"
                "color:white;"
                "}");
    ui->searchpushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#FFD700;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#DAA520;"
                "color:white;"
                "}");
    ui->Title->setStyleSheet(
                "QLabel{"
                "background-color:#DDDDDD;"
                "}");
    ui->readerSearchLineEdit->setPlaceholderText("搜索用户名");
    ui->phoneSearchLineEdit->setPlaceholderText("搜索手机号");
    ui->emailSearchLineEdit->setPlaceholderText("搜索电子邮箱");
}

void readerManager::databaseOperate()
{

    model = new QSqlTableModel();
    model->setTable("user");//选择表
    model->select();//展示所有

    ui->readerInformationtableView->setModel(model);//连接数据库
    ui->readerInformationtableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //只读
    int ColumnWidth[] = {50, 100, 100, 150, 160, 170, 70, 70, 70};//设置列宽
    for(int i = 0; i < model->columnCount(); i++)
        ui->readerInformationtableView->setColumnWidth(i, ColumnWidth[i]);
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *modifypushButton = new QPushButton("修改🔧");
        QPushButton *deletepushButton = new QPushButton("删除❌");
        modifypushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#FFA500;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#FF8C00;"
                    "color:white;"
                    "}");
        deletepushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#8470FF;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#6A5ACD;"
                    "color:white;"
                    "}");
        ui->readerInformationtableView->setIndexWidget(model->index(i, 7), modifypushButton);
        ui->readerInformationtableView->setIndexWidget(model->index(i, 8), deletepushButton);

        // 添加槽
        connect(modifypushButton, SIGNAL(clicked()), this, SLOT(on_modifypushButton_clicked()));
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }

}

void readerManager::on_AddpushButton_clicked()
{
    readerInformationManagerAdddatadialog readerinformationManagerAdddatadialog(this,this->model);
    readerinformationManagerAdddatadialog.exec();

    model->setFilter("");
    model->select();//展示所有
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *modifypushButton = new QPushButton("修改🔧");
        QPushButton *deletepushButton = new QPushButton("删除❌");
        modifypushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#FFA500;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#7B68EE;"
                    "color:white;"
                    "}");
        deletepushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#8470FF;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#6A5ACD;"
                    "color:white;"
                    "}");
        ui->readerInformationtableView->setIndexWidget(model->index(i, 7), modifypushButton);
        ui->readerInformationtableView->setIndexWidget(model->index(i, 8), deletepushButton);

        // 添加槽
        connect(modifypushButton, SIGNAL(clicked()), this, SLOT(on_modifypushButton_clicked()));
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }
}

void readerManager::on_deletepushButton_clicked()
{

    QMessageBox::StandardButton result = QMessageBox::question(this, "删除", "是否删除？");
    if(result == QMessageBox::Yes)
    {
        int row = ui->readerInformationtableView->currentIndex().row();
        model->removeRow(row);

        if(model->submitAll())
            QMessageBox::about(this, "删除", "删除成功！");
        else
            QMessageBox::critical(this, "删除", "删除失败！请重试。");
    }
    else
        return;

    model->select();//展示所有
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *modifypushButton = new QPushButton("修改🔧");
        QPushButton *deletepushButton = new QPushButton("删除❌");
        modifypushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#FFA500;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#7B68EE;"
                    "color:white;"
                    "}");
        deletepushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#8470FF;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#FF3030;"
                    "color:white;"
                    "}");
        ui->readerInformationtableView->setIndexWidget(model->index(i, 7), modifypushButton);
        ui->readerInformationtableView->setIndexWidget(model->index(i, 8), deletepushButton);

        // 添加槽
        connect(modifypushButton, SIGNAL(clicked()), this, SLOT(on_modifypushButton_clicked()));
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }

}

void readerManager::on_modifypushButton_clicked()
{
    QSqlRecord *record = new QSqlRecord(model->record(ui->readerInformationtableView->currentIndex().row()));
    int r = ui->readerInformationtableView->currentIndex().row();
    int *row = &r;
    readerInformationManagerModifydialog readerInformationManagerModifyDialog(this, model, record, row);
    readerInformationManagerModifyDialog.exec();

    model->select();

    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *modifypushButton = new QPushButton("修改🔧");
        QPushButton *deletepushButton = new QPushButton("删除❌");
        modifypushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#FFA500;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#FF8C00;"
                    "color:white;"
                    "}");
        deletepushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#8470FF;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#6A5ACD;"
                    "color:white;"
                    "}");
        ui->readerInformationtableView->setIndexWidget(model->index(i, 7), modifypushButton);
        ui->readerInformationtableView->setIndexWidget(model->index(i, 8), deletepushButton);

        // 添加槽
        connect(modifypushButton, SIGNAL(clicked()), this, SLOT(on_modifypushButton_clicked()));
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }
}

void readerManager::on_searchpushButton_clicked()
{
   QString username = ui->readerSearchLineEdit->text();
   QString phone    = ui->phoneSearchLineEdit->text();
   QString email    = ui->emailSearchLineEdit->text();
   if(username.isEmpty()&&phone.isEmpty()&&email.isEmpty())
   {
       QMessageBox::StandardButton result = QMessageBox::warning(this, "错误", "请输入查询信息！");
       if(result == QMessageBox::Ok)
           return;
   }
   else
   {
       if(!username.isEmpty())
            model->setFilter(QObject::tr("user = '%1'").arg(username)); //根据姓名进行筛选
       if(!phone.isEmpty())
            model->setFilter(QObject::tr("phone = '%1'").arg(phone)); //根据图书名进行筛选
       if(!email.isEmpty())
            model->setFilter(QObject::tr("email = '%1'").arg(email)); //根据姓名进行筛选
       model->select();//展示所有
       for(int i = 0; i < model->rowCount(); i++)//设置按钮
       {
           QPushButton *modifypushButton = new QPushButton("修改🔧");
           QPushButton *deletepushButton = new QPushButton("删除❌");
           modifypushButton->setStyleSheet(
                       "QPushButton{"
                       "font-style:italic;" //斜体
                       "font-weight: bold;" //粗体
                       "font-size: 13px;" //字体大小
                       "font-family: 'Microsoft YaHei UI';"//字体
                       "background-color:#FFA500;"
                       "border-radius:3px;"//设置圆角半径
                       "color:white;"
                       "border-width:71;"//按钮大小设置
                       "}"
                       "QPushButton:hover{"
                       "background-color:#7B68EE;"
                       "color:white;"
                       "}");
           deletepushButton->setStyleSheet(
                       "QPushButton{"
                       "font-style:italic;" //斜体
                       "font-weight: bold;" //粗体
                       "font-size: 13px;" //字体大小
                       "font-family: 'Microsoft YaHei UI';"//字体
                       "background-color:#8470FF;"
                       "border-radius:3px;"//设置圆角半径
                       "color:white;"
                       "border-width:71;"//按钮大小设置
                       "}"
                       "QPushButton:hover{"
                       "background-color:#FF3030;"
                       "color:white;"
                       "}");
           ui->readerInformationtableView->setIndexWidget(model->index(i, 7), modifypushButton);
           ui->readerInformationtableView->setIndexWidget(model->index(i, 8), deletepushButton);

           // 添加槽
           connect(modifypushButton, SIGNAL(clicked()), this, SLOT(on_modifypushButton_clicked()));
           connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
       }
   }
}

void readerManager::on_SurepushButton_clicked()
{
    QMessageBox::StandardButton result = QMessageBox::question(this, "确认", "是否确认？");
    if(result == QMessageBox::Yes)
    {
        if(model->submitAll())
            QMessageBox::about(this, "确认", "确认成功！");
        else
            QMessageBox::critical(this, "确认", "确认失败！请重试。");
    }
}

void readerManager::on_AllpushButton_clicked()
{
    model->setFilter("");
    model->select();//展示所有
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *modifypushButton = new QPushButton("修改🔧");
        QPushButton *deletepushButton = new QPushButton("删除❌");
        modifypushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#FFA500;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#FF8C00;"
                    "color:white;"
                    "}");
        deletepushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#8470FF;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#6A5ACD;"
                    "color:white;"
                    "}");
        ui->readerInformationtableView->setIndexWidget(model->index(i, 7), modifypushButton);
        ui->readerInformationtableView->setIndexWidget(model->index(i, 8), deletepushButton);

        // 添加槽
        connect(modifypushButton, SIGNAL(clicked()), this, SLOT(on_modifypushButton_clicked()));
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }
}



