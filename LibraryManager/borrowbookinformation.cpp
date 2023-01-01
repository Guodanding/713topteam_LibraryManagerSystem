#include "borrowbookinformation.h"
#include "ui_borrowbookinformation.h"
#include <QStyle>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QString>
#include <QSqlRecord>
#include <QDate>

borrowBookInformation::borrowBookInformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borrowBookInformation)
{
    ui->setupUi(this);
    setWindowTitle("借阅图书管理模块");
    setWinStyle();
    databaseOperate();
}

void borrowBookInformation::setWinStyle()
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
    ui->ReturnBtn->setStyleSheet(
                "QPushButton{"
                "background-color:#FF0000;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#8B4513;"
                "color:white;"
                "}");
    ui->Title->setStyleSheet(
                "QLabel{"
                "background-color:#DDDDDD;"
                "}");
    ui->bookNameSearchLineEdit->setPlaceholderText("搜索书名");
    ui->readerSearchLineEdit->setPlaceholderText("搜索借阅者");
}

void borrowBookInformation::databaseOperate()
{
    model = new QSqlTableModel();
    model->setTable("BorrowHistory");//选择表
    model->select();//展示所有

    ui->returnedBookInformationtableView->setModel(model);//连接数据库
    ui->returnedBookInformationtableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //只读
    int ColumnWidth[] = {155, 155, 155, 155, 155, 165};//设置列宽
    for(int i = 0; i < model->columnCount(); i++)
        ui->returnedBookInformationtableView->setColumnWidth(i, ColumnWidth[i]);
    /*for(int i = 0; i < model->rowCount(); i++)//设置按钮
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
    }*/

}

void borrowBookInformation::on_searchpushButton_clicked()
{
   QString BookName = ui->bookNameSearchLineEdit->text();
   QString Reader   = ui->readerSearchLineEdit->text();

   if(BookName.isEmpty() && Reader.isEmpty())
   {
       QMessageBox::StandardButton result = QMessageBox::warning(this, "错误", "请输入查询信息！");
       if(result == QMessageBox::Ok)
           return;
   }
   else
   {
       if(!BookName.isEmpty())
            model->setFilter(QObject::tr("Title = '%1'").arg(BookName)); //根据ID进行筛选
       if(!Reader.isEmpty())
            model->setFilter(QObject::tr("Username = '%1'").arg(Reader)); //根据姓名进行筛选

       model->select();//展示所有
   }
}

void borrowBookInformation::on_AllpushButton_clicked()
{
    model->setFilter("");
    model->select();//展示所有
}

/*
void borrowBookInformation::on_deletepushButton_clicked()
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
*/
borrowBookInformation::~borrowBookInformation()
{
    delete ui;
}
/*****************这里不会**********************/
void borrowBookInformation::on_ReturnBtn_clicked()
{
    int row = ui->returnedBookInformationtableView->currentIndex().row();
    //qDebug() << row;
    QSqlRecord record = model->record(row);
    QString Booknumber = record.value("Number").toString();
    QString Username = record.value("Username").toString();
    QString Title = record.value("Title").toString();
    QString Author = record.value("Author").toString();
    QString IsReturn = record.value("Returndate").toString();
    if(IsReturn != "未还书")
    {
        QMessageBox::warning(this,"提示","该书籍已归还！");
    }
    else
    {
        QMessageBox::StandardButton answer = QMessageBox::question(this,"还书确认","你确定要帮助读者进行还书吗？");
        if(answer == QMessageBox::Yes)
        {
            //BorrowHistory
            QDate date = QDate::currentDate();
            QString Returndate = date.toString("yyyy-MM-dd");
            model->setTable("BorrowHistory");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->setFilter(QObject::tr("(Number like '%1') and (Returndate like '%2')").arg(Booknumber).arg("未还书"));
            model->select();
            record = model->record(0);
            record.setValue("Returndate",Returndate);
            model->setRecord(0,record);
            model->submitAll();

            //BorrowInfo
            model->setTable("BorrowInfo");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->setFilter(QObject::tr("Number = '%1'").arg(Booknumber));
            model->setFilter(QObject::tr("Username = '%1'").arg(Username));
            model->setFilter(QObject::tr("BookTitle = '%1'").arg(Title));
            model->removeRow(0);
            model->submitAll();

            //bookInformation
            model->setTable("bookinformation");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->setFilter(QObject::tr("图书名 = '%1'").arg(Title));
            model->select();
            record = model->record(0);
            QString Booknum = record.value("数量").toString();
            int booknum = Booknum.toInt();
            booknum++;
            Booknum = QString::number(booknum,10);
            record.setValue("数量",Booknum);
            model->setRecord(0,record);
            model->submitAll();

            //Log
            model->setTable("Log");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            int Rowcount = model->rowCount();
            model->insertRow(Rowcount);
            QString log = "用户"+Username+"在"+Returndate+"归还"+Booknumber+Title;
            model->setData(model->index(row,1),log);
            model->submitAll();

            //BookSearch
            model->setTable("booksearch");
            model->setEditStrategy(QSqlTableModel::OnManualSubmit);
            model->setFilter(QObject::tr("索书号 like '%%1%'").arg(Booknumber));
            model->select();
            model->setData(model->index(0,8),"在库");
            model->submitAll();
        }
    }
    model->setTable("BorrowHistory");
    model->select();//展示所有
    int ColumnWidth[] = {155, 155, 155, 155, 155, 165};//设置列宽
    for(int i = 0; i < model->columnCount(); i++)
        ui->returnedBookInformationtableView->setColumnWidth(i, ColumnWidth[i]);
}

/*void borrow_info::on_ReturnBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if(tm->rowCount() == 0)
    {
        QMessageBox::warning(this,"提示","当前无可归还书籍！");
    }
    else
    {

    QMessageBox::StandardButton answer = QMessageBox::question(this,"还书确认","你确定要还书吗？");
    if(answer == QMessageBox::Yes)
    {
        QSqlRecord record = tm->record(row);
        QString Booknumber = record.value("Booknum").toString();
        QString BookTitle = record.value("BookTitle").toString();
        tm->removeRow(row);
        tm->submitAll();

        tm->setTable("bookinformation");
        tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
        tm->setFilter(QObject::tr("图书名 = '%1'").arg(BookTitle));
        tm->select();
        record = tm->record(0);
        QString Booknum = record.value("数量").toString();
        int booknum = Booknum.toInt();
        booknum++;
        Booknum = QString::number(booknum,10);
        record.setValue("数量",Booknum);
        tm->setRecord(0,record);
        tm->submitAll();

        QDate date = QDate::currentDate();
        QString Returndate = date.toString("yyyy-MM-dd");
        tm->setTable("BorrowHistory");
        tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
        tm->setFilter(QObject::tr("(Number like '%1') and (Returndate like '%2')").arg(Booknumber).arg("未还书"));
        tm->select();
        record = tm->record(0);
        record.setValue("Returndate",Returndate);
        tm->setRecord(0,record);
        tm->submitAll();

        tm->setTable("Log");
        tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
        int Rowcount = tm->rowCount();
        tm->insertRow(Rowcount);
        QString log = "用户"+Username+"在"+Returndate+"归还"+Booknumber+BookTitle;
        tm->setData(tm->index(row,1),log);
        tm->submitAll();

        tm->setTable("booksearch");
        tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
        tm->setFilter(QObject::tr("索书号 like '%%1%'").arg(Booknumber));
        tm->select();
        tm->setData(tm->index(0,8),"在库");
        tm->submitAll();


        tm->setTable("BorrowInfo");
        tm->setFilter(QObject::tr("Username = '%1'").arg(Username));
        tm->select();
        tm->setHeaderData(0, Qt::Horizontal, "用户名");
        tm->setHeaderData(1, Qt::Horizontal, "书本编号");
        tm->setHeaderData(2, Qt::Horizontal, "书名");
        tm->setHeaderData(3, Qt::Horizontal, "借书时间");
        tm->setHeaderData(4, Qt::Horizontal, "到期时间");
        tm->setHeaderData(5, Qt::Horizontal, "是否续借");
        ui->tableView->setModel(tm);
        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->setAlternatingRowColors(true); // 表格数据行隔行变色
        ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单个数据格
        int ColumnWidth[] = { 160, 160, 165, 160, 160,150 };//设置列宽
        for(int i = 0; i < tm->columnCount(); i++)
            ui->tableView->setColumnWidth(i, ColumnWidth[i]);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        if(tm->rowCount() == 0)
        {
            tm->clear();
        }
    }
    }

}*/
