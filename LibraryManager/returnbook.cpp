#include "returnbook.h"
#include "ui_returnbook.h"
#include <QStyle>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QString>
#include <QSqlRecord>

returnBook::returnBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::returnBook)
{
    ui->setupUi(this);
    setWindowTitle("归还图书管理模块");
    setWinStyle();
    databaseOperate();
}

void returnBook::setWinStyle()
{
    ui->returnedBookInformationtableView->setAlternatingRowColors(true); // 表格数据行隔行变色
    ui->returnedBookInformationtableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单个数据格
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
    ui->bookNameSearchLineEdit->setPlaceholderText("搜索书名");
    ui->pressSearchLineEdit->setPlaceholderText("搜索出版社");
    ui->writerSearchLineEdit->setPlaceholderText("搜索作者");
}

void returnBook::databaseOperate()
{
    model = new QSqlTableModel();
    model->setTable("returnedBookInformation");//选择表
    model->select();//展示所有

    ui->returnedBookInformationtableView->setModel(model);//连接数据库
    ui->returnedBookInformationtableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //只读
    int ColumnWidth[] = {50, 100, 120, 100, 150, 50, 200, 50};//设置列宽
    for(int i = 0; i < model->columnCount(); i++)
        ui->returnedBookInformationtableView->setColumnWidth(i, ColumnWidth[i]);
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *deletepushButton = new QPushButton("删除❌");
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
        ui->returnedBookInformationtableView->setIndexWidget(model->index(i, 7), deletepushButton);

        // 添加槽
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }

}

void returnBook::on_searchpushButton_clicked()
{
   QString BookName = ui->bookNameSearchLineEdit->text();
   QString press    = ui->pressSearchLineEdit->text();
   QString Writer   = ui->writerSearchLineEdit->text();

   if(press.isEmpty() && BookName.isEmpty() && Writer.isEmpty())
   {
       QMessageBox::StandardButton result = QMessageBox::warning(this, "错误", "请输入查询信息！");
       if(result == QMessageBox::Ok)
           return;
   }
   else
   {
       if(!BookName.isEmpty())
            model->setFilter(QObject::tr("图书名 = '%1'").arg(BookName)); //根据ID进行筛选
       if(!press.isEmpty())
            model->setFilter(QObject::tr("出版社 = '%1'").arg(press)); //根据图书名进行筛选
       if(!Writer.isEmpty())
            model->setFilter(QObject::tr("作者 = '%1'").arg(Writer)); //根据姓名进行筛选

       model->select();//展示所有
       for(int i = 0; i < model->rowCount(); i++)//设置按钮
       {

           QPushButton *deletepushButton = new QPushButton("删除❌");
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
           ui->returnedBookInformationtableView->setIndexWidget(model->index(i, 9), deletepushButton);

           // 添加槽
           connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
       }
   }
}

void returnBook::on_AllpushButton_clicked()
{
    model->setFilter("");
    model->select();//展示所有
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *deletepushButton = new QPushButton("删除❌");
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

        ui->returnedBookInformationtableView->setIndexWidget(model->index(i, 7), deletepushButton);

        // 添加槽
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }
}

void returnBook::on_deletepushButton_clicked()
{

    QMessageBox::StandardButton result = QMessageBox::question(this, "删除", "是否删除？");
    if(result == QMessageBox::Yes)
    {
        int row = ui->returnedBookInformationtableView->currentIndex().row();
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
        QPushButton *deletepushButton = new QPushButton("删除❌");
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
        ui->returnedBookInformationtableView->setIndexWidget(model->index(i, 7), deletepushButton);

        // 添加槽
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }

}
returnBook::~returnBook()
{
    delete ui;
}
