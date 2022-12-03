#ifndef DBOPERATOR_H
#define DBOPERATOR_H
#include <QSqlDatabase> //数据驱动
#include <QSqlQuery> //数据库执行语句
class DBOperator
{
private:
    QSqlDatabase dbcon;//connection to database
    bool openFlag;
public:
    DBOperator();
    void DBOpen();//打开数据库
    void DBClose();//关闭数据库
    QSqlQuery DBGetData(QString sqlstr);
};

#endif // DBOPERATOR_H
