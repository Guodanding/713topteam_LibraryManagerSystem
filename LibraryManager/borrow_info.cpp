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
    tm = new QSqlTableModel(this);
    tm->setTable("BorrowInfo");
    tm->setFilter(QObject::tr("Username = '%1'").arg(Username));
    tm->select();
    tm->setHeaderData(0, Qt::Horizontal, "用户名");
    tm->setHeaderData(1, Qt::Horizontal, "书本编号");
    tm->setHeaderData(2, Qt::Horizontal, "书名");
    tm->setHeaderData(3, Qt::Horizontal, "借书时间");
    tm->setHeaderData(4, Qt::Horizontal, "到期时间");
    ui->tableView->setModel(tm);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

borrow_info::~borrow_info()
{
    delete ui;
}

void borrow_info::on_ReturnBtn_clicked()
{
    int row = ui->tableView->currentIndex().row();

    QMessageBox::StandardButton answer = QMessageBox::question(this,"还书确认","你确定要还书吗？");
    if(answer == QMessageBox::Yes)
    {
        QSqlRecord record = tm->record(row);
        QString Booknumber = record.value("Booknumber").toString();
        QString BookTitle = record.value("BookTitle").toString();
        tm->removeRow(row);
        tm->submitAll();

        tm->setTable("BookInfo");
        tm->setEditStrategy(QSqlTableModel::OnManualSubmit);
        tm->setFilter(QObject::tr("Number = '%1'").arg(Booknumber));
        tm->select();
        record = tm->record(0);
        record.setValue("State","在库");
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

        tm->setTable("BorrowInfo");
        tm->setFilter(QObject::tr("Username = '%1'").arg(Username));
        tm->select();
        tm->setHeaderData(0, Qt::Horizontal, "用户名");
        tm->setHeaderData(1, Qt::Horizontal, "书本编号");
        tm->setHeaderData(2, Qt::Horizontal, "书名");
        tm->setHeaderData(3, Qt::Horizontal, "借书时间");
        tm->setHeaderData(4, Qt::Horizontal, "到期时间");
        ui->tableView->setModel(tm);
        ui->tableView->verticalHeader()->setVisible(false);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        if(tm->rowCount() == 0)
        {
            tm->clear();
        }
    }

}


void borrow_info::on_ExitBtn_clicked()
{
    borrow_info::close();
}

