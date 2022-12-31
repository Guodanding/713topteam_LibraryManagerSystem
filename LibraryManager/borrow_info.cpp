#include "borrow_info.h"
#include "ui_borrow_info.h"
#include <QMessageBox>
#include <qsqlrecord.h>
#include <QDate>

borrow_info::borrow_info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borrow_info)
{
    ui->setupUi(this);
    DBO.DBOpen();
    ui->Title->setStyleSheet(
                "QLabel{"
                "background-color:#DDDDDD;"
                "}");
    ui->ExitBtn->setStyleSheet(
                "QPushButton{"
                "background-color:#FF0000;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#8B4513;"
                "color:white;"
                "}");
    ui->ReturnBtn->setStyleSheet(
                "QPushButton{"
                "background-color:#8470FF;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "border-width:71;"//按钮大小设置
                "}"
                "QPushButton:hover{"
                "background-color:#6A5ACD;"
                "color:white;"
                "}");
    ui->RenewBtn->setStyleSheet(
                "QPushButton{"
                "background-color:#FFA500;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FF8C00;"
                "color:white;"
                "}");
}

borrow_info::~borrow_info()
{
    delete ui;
}

void borrow_info::on_ReturnBtn_clicked()
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

}


void borrow_info::on_ExitBtn_clicked()
{
    borrow_info::close();
}

void borrow_info::setusername(QString username)
{
    Username = username;
    tm = new QSqlTableModel(this);
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
    int ColumnWidth[] = { 160, 160, 165, 160, 160,150 };//设置列宽
    for(int i = 0; i < tm->columnCount(); i++)
        ui->tableView->setColumnWidth(i, ColumnWidth[i]);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(tm->rowCount() == 0)
    {
        tm->clear();
    }
}



void borrow_info::on_RenewBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();
    if(tm->rowCount() == 0)
    {
        QMessageBox::warning(this,"提示","当前无可续借书籍！");
    }
    else
    {
        QSqlRecord record = tm->record(row);
        QString RenewFlag = record.value("RenewFlag").toString();

        if(RenewFlag == "否")
       {
        QMessageBox::information(this,"续借确认","续借成功！");

        QString Booknumber = record.value("Booknum").toString();
        QString BookTitle = record.value("BookTitle").toString();
        QString Exturndate = record.value("Expiredate").toString();
        QDate date = QDate::fromString(Exturndate,"yyyy-MM-dd");
        date = date.addMonths(1);
        qDebug()<<date;
        Exturndate = date.toString("yyyy-MM-dd");
        qDebug()<<Exturndate;
        record.setValue("Expiredate",Exturndate);
        record.setValue("RenewFlag","是");
        tm->setRecord(row,record);
        tm->submitAll();


        tm->setTable("Log");
        tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
        int Rowcount = tm->rowCount();
        tm->insertRow(Rowcount);
        date = QDate::currentDate();
        QString Nowdate = date.toString();
        QString log = "用户"+Username+"在"+Nowdate+"续借"+Booknumber+BookTitle;
        tm->setData(tm->index(row,1),log);
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
        int ColumnWidth[] = { 160, 160, 165, 160, 160,150 };//设置列宽
        for(int i = 0; i < tm->columnCount(); i++)
            ui->tableView->setColumnWidth(i, ColumnWidth[i]);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        if(tm->rowCount() == 0)
        {
            tm->clear();
        }

       }

       if(RenewFlag == "是")
       {
           QMessageBox::warning(this,"提示","每本书籍只能续借一次！");
       }
    }

}

