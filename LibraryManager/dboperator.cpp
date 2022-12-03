#include "dboperator.h"
#include <QMessageBox>//消息盒子
#include <QDebug>//debug

DBOperator::DBOperator()
{
    openFlag = false;
}

void DBOperator::DBOpen()
{
    QString dsn;
    if(!openFlag)//如果未打开
    {
        dbcon = QSqlDatabase::addDatabase("QODBC");
        dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access};DBQ=:/database/LibraryData.accdb");
        dbcon.setDatabaseName(dsn);
        bool ok = dbcon.open();//activate the physical connection to the database.
        if(!ok)
            qDebug() << "错误, LibraryData 数据库文件打开失败！";
        else
            qDebug() << "打开数据库成功";
        openFlag = true;
    }
}

void DBOperator::DBClose()
{
    dbcon.close();//Closes the database connection
}

QSqlQuery DBOperator::DBGetData(QString sqlstr)
{
    QSqlQuery query = QSqlQuery(dbcon);//Constructs a QSqlQuery object using the database db.
    query.exec(sqlstr);//Executes a previously prepared SQL query. Returns true if the query executed successfully
    return query;//Successfully executed SQL statements set the query's state to active so that isActive() returns true.
}
