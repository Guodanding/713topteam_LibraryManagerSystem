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

}

BookSearch::~BookSearch()
{
    delete ui;
}

void BookSearch::on_SearchBtn_clicked()
{
    QString bookName;
    bookName = ui->lineEdit->text().trimmed();
    tm->setTable("BookInfo");
    tm->setFilter(QObject::tr("Title like '%%1%'").arg(bookName));
    tm->select();
    tm->setHeaderData(0, Qt::Horizontal, "编号");
    tm->setHeaderData(1, Qt::Horizontal, "书名");
    tm->setHeaderData(2, Qt::Horizontal, "状态");
    tm->setHeaderData(3, Qt::Horizontal, "作者");
    tm->setHeaderData(4, Qt::Horizontal, "出版时间");
    tm->setHeaderData(5, Qt::Horizontal, "出版社");
    ui->tableView->setModel(tm);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void BookSearch::on_BorrowBtn_clicked()
{
   int row = ui->tableView->currentIndex().row();
   QSqlRecord record = tm->record(row);
   QString state = record.value("State").toString();

   if(state == "在库")
   {
    record.setValue("State","借出");
    tm->setRecord(row,record);
    QMessageBox::about(this,"提醒","借阅成功！");
    tm->submitAll();

   QDate date = QDate::currentDate();
   QDate date2 = date.addMonths(1);
   QString Borrowtime = date.toString("yyyy-MM-dd");
   QString Expiretime = date2.toString("yyyy-MM-dd");
   QString Bookname = record.value("Title").toString();
   QString Booknumber = record.value("Number").toString();
   QString Author = record.value("Author").toString();

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

   tm->clear();
   }
   else
   {
       QMessageBox::warning(this,"警告","该书已被借阅！");
   }
}


void BookSearch::on_ExitBtn_clicked()
{
    BookSearch::close();
}


