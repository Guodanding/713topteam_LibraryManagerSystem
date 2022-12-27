#include "booksearch.h"
#include "ui_booksearch.h"
#include <qsqlrecord.h>
#include <qmessagebox.h>
#include <QDate>
#include <QSqlQuery>

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
    ui->SearchBtn->setStyleSheet(
                "QPushButton{"
                "background-color:#FFD700;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#DAA520;"
                "color:white;"
                "}");
    ui->BorrowBtn->setStyleSheet(
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
    ui->Title->setStyleSheet(
                "QLabel{"
                "background-color:#DDDDDD;"
                "}");

    ui->lineEdit_bookname->setPlaceholderText("请输入查找信息");

    QStringList cbList;
    cbList << "马克思主义、列宁主义、毛泽东思想、邓小平理论" << "哲学、宗教" << "社会科学总论" << "政治、法律" << "军事";
    cbList << "经济" << "文化、科学、教育、体育" << "语言、文字" << "文学" << "艺术";
    cbList << "历史、地理" << "自然科学总论" << "数理科学和化学" << "天文学、地球科学" << "生物科学";
    cbList << "医药、卫生" << "农业科学" << "工业技术" << "交通运输" << "航空、航天";
    cbList << "环境科学、劳动保护科学（安全科学）" << "综合性图书";
    ui->BookTypedepcbBox->addItems(cbList);
}

BookSearch::~BookSearch()
{
    delete ui;
}

void BookSearch::on_SearchBtn_clicked()
{
    bookName = ui->lineEdit_bookname->text().trimmed();
    QString search_info = ui->lineEdit_bookname->text().trimmed();
    tm->setTable("booksearch");

    if(authorSelected)
    {
        tm->setFilter(QObject::tr("作者 like '%%1%'").arg(search_info));
    }
    if(publisherSelected)
    {
        tm->setFilter(QObject::tr("出版社 like '%%1%'").arg(search_info));
    }
    if(titleSelected)
    {
        tm->setFilter(QObject::tr("图书名 like '%%1%'").arg(search_info));
    }
    if(typeSelected)
    {
        QString BookType = ui->BookTypedepcbBox->currentText();
        tm->setFilter(QObject::tr("图书类型 = '%1'").arg(BookType));
    }

    tm->select();
    int row = tm->rowCount();
    if(row > 0)
    {
    ui->tableView->setModel(tm);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    searchflag = true;
    ui->tableView->setAlternatingRowColors(true); // 表格数据行隔行变色
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单个数据格
    int ColumnWidth[] = { 70, 90, 70, 120, 120, 140, 160, 120, 65};//设置列宽
    for(int i = 0; i < tm->columnCount(); i++)
        ui->tableView->setColumnWidth(i, ColumnWidth[i]);
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


   bookName = ui->lineEdit_bookname->text().trimmed();
   QString search_info = ui->lineEdit_bookname->text().trimmed();
   tm->setTable("booksearch");

   if(authorSelected)
   {
       tm->setFilter(QObject::tr("作者 like '%%1%'").arg(search_info));
   }
   if(publisherSelected)
   {
       tm->setFilter(QObject::tr("出版社 like '%%1%'").arg(search_info));
   }
   if(titleSelected)
   {
       tm->setFilter(QObject::tr("图书名 like '%%1%'").arg(search_info));
   }
   if(typeSelected)
   {
       tm->setFilter(QObject::tr("图书类型 like '%%1%'").arg(search_info));
   }


   tm->select();
   int row = tm->rowCount();
   if(row > 0)
   {
   ui->tableView->setModel(tm);
   ui->tableView->verticalHeader()->setVisible(false);
   ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
   searchflag = true;
   ui->tableView->setAlternatingRowColors(true); // 表格数据行隔行变色
   ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单个数据格
   int ColumnWidth[] = { 70, 90, 70, 120, 120, 140, 160, 120, 65};//设置列宽
   for(int i = 0; i < tm->columnCount(); i++)
       ui->tableView->setColumnWidth(i, ColumnWidth[i]);
   }


   else
   {
       QMessageBox::warning(this,"警告","该书已被借阅！");
   }
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
    QString sqlstr = QString("SELECT score FROM user WHERE username = '%1';").arg(Username);
    QSqlQuery query(sqlstr);
    query.next();
    QString score = query.value(0).toString();
    qDebug()<<score;
    ui->label_score->setText(score);
}



void BookSearch::on_radioButton_publiser_clicked()
{
    publisherSelected = true;
    typeSelected = false;
    authorSelected = false;
    titleSelected = false;
}



void BookSearch::on_radioButton_booktype_clicked()
{
    publisherSelected = false;
    typeSelected = true;
    authorSelected = false;
    titleSelected = false;
}


void BookSearch::on_radioButton_author_clicked()
{
    publisherSelected = false;
    typeSelected = false;
    authorSelected = true;
    titleSelected = false;
}


void BookSearch::on_radioButton_booktitle_clicked()
{
    publisherSelected = false;
    typeSelected = false;
    authorSelected = false;
    titleSelected = true;
}

