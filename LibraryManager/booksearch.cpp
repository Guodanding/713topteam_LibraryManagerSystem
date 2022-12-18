#include "booksearch.h"
#include "ui_booksearch.h"
#include <qsqlrecord.h>
#include <qmessagebox.h>
#include <QDate>

BookSearch::BookSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookSearch)
{
    ui->setupUi(this);
    setWindowTitle("图书查询");
    DBO.DBOpen();
    tm = new QSqlTableModel(this);
    tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->ExitBtn->setStyleSheet( "QPushButton{"
                                "background-color:#8470FF;"
                                "border-radius:3px;"//设置圆角半径
                                "color:white;"
                                "}"
                                "QPushButton:hover{"
                                "background-color:#FF8C00;"
                                "color:white;"
                                "}");

}

BookSearch::~BookSearch()
{
    delete ui;
}

void BookSearch::on_SearchBtn_clicked()
{
    bookName = ui->lineEdit_bookname->text().trimmed();
    QString author = ui->lineEdit_author->text().trimmed();
    tm->setTable("booksearch");
    //tm->setFilter(QObject::tr("图书名 like '%%1%'").arg(bookName));
    if(bookName == "")
    {
        tm->setFilter(QObject::tr("作者 like '%%1%'").arg(author));
    }
    else if(author == "")
    {
        tm->setFilter(QObject::tr("图书名 like '%%1%'").arg(bookName));
    }
    else
    {
        tm->setFilter(QObject::tr("(图书名 like '%1%') OR (作者 like '%2%')").arg(bookName).arg(author));
    }
    tm->select();
    int row = tm->rowCount();
    if(row > 0)
    {
    ui->tableView->setModel(tm);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    searchflag = true;
    }
    else
    {
        QMessageBox::warning(this,"查询失败","未找到该图书！");
        searchflag = false;
    }
}


void BookSearch::on_BorrowBtn_clicked()
{
    if(searchflag)
   {
   int row = ui->tableView->currentIndex().row();
   QSqlRecord record = tm->record(row);
   QString state = record.value("状态").toString();
   if(state == "在库")
   {
    record.setValue("状态","借出");
    tm->setRecord(row,record);
    QMessageBox::about(this,"提醒","借阅成功！");
    tm->submitAll();

   QDate date = QDate::currentDate();
   QDate date2 = date.addMonths(1);
   QString Borrowtime = date.toString("yyyy-MM-dd");
   QString Expiretime = date2.toString("yyyy-MM-dd");
   QString Bookname = record.value("图书名").toString();
   QString Booknumber = record.value("索书号").toString();
   QString Author = record.value("作者").toString();

   tm->setTable("BorrowInfo");
   tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
   int Rowcount = tm->rowCount();
   tm->insertRow(Rowcount);
   tm->setData(tm->index(row,0),Username);
   tm->setData(tm->index(row,1),Booknumber);
   tm->setData(tm->index(row,2),Bookname);
   tm->setData(tm->index(row,3),Borrowtime);
   tm->setData(tm->index(row,4),Expiretime);
   tm->submitAll();

   tm->setTable("BorrowHistory");
   tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
   Rowcount = tm->rowCount();
   tm->insertRow(Rowcount);
   tm->setData(tm->index(row,0),Username);
   tm->setData(tm->index(row,1),Booknumber);
   tm->setData(tm->index(row,2),Bookname);
   tm->setData(tm->index(row,3),Author);
   tm->setData(tm->index(row,4),Borrowtime);
   tm->setData(tm->index(row,5),"未还书");
   tm->submitAll();

   tm->setTable("Log");
   tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
   Rowcount = tm->rowCount();
   tm->insertRow(Rowcount);
   QString log = "用户"+Username+"在"+Borrowtime+"借出"+Booknumber+Bookname;
   tm->setData(tm->index(row,1),log);
   tm->submitAll();

   tm->setTable("bookinformation");
   tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
   tm->setFilter(QObject::tr("图书名 like '%%1%'").arg(Bookname));
   tm->select();
   QString Booknum = tm->index(0,7).data().toString();
   qDebug()<<Booknum;
   int booknum = Booknum.toInt();
   booknum--;
   Booknum = QString::number(booknum,10);
   tm->setData(tm->index(0,7),Booknum);
   tm->submitAll();

   tm->clear();
   }
   else
   {
       QMessageBox::warning(this,"警告","该书已被借阅！");
   }
    }
}


void BookSearch::on_ExitBtn_clicked()
{
    BookSearch::close();
}

void BookSearch::setusername(QString username)
{
    Username = username;
}


