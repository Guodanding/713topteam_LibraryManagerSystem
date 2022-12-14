#include "borrow_history.h"
#include "ui_borrow_history.h"

borrow_history::borrow_history(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::borrow_history)
{
    ui->setupUi(this);
    setWindowTitle("图书借阅历史查询");
    DBO.DBOpen();
    ui->Title->setStyleSheet(
                "QLabel{"
                "background-color:#DDDDDD;"
                "}");
}

borrow_history::~borrow_history()
{
    delete ui;
}


void borrow_history::setusername(QString username)
{
    Username = username;
    tm = new QSqlTableModel(this);
    tm->setTable("BorrowHistory");
    tm->setFilter(QObject::tr("Username = '%1'").arg(Username));
    tm->select();
    tm->setHeaderData(0, Qt::Horizontal, "用户名");
    tm->setHeaderData(1, Qt::Horizontal, "书本编号");
    tm->setHeaderData(2, Qt::Horizontal, "书名");
    tm->setHeaderData(3, Qt::Horizontal, "作者");
    tm->setHeaderData(4, Qt::Horizontal, "借书时间");
    tm->setHeaderData(5, Qt::Horizontal, "还书时间");
    ui->tableView->setModel(tm);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setAlternatingRowColors(true); // 表格数据行隔行变色
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单个数据格
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    int ColumnWidth[] = {155, 155, 162, 155, 165, 165};//设置列宽
    for(int i = 0; i < tm->columnCount(); i++)
        ui->tableView->setColumnWidth(i, ColumnWidth[i]);
}

