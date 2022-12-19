#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QWidget>
#include "dboperator.h"
#include <QSqlTableModel>

namespace Ui {
class returnBook;
}

class returnBook : public QWidget
{
    Q_OBJECT

public:
    explicit returnBook(QWidget *parent = nullptr);
    ~returnBook();
    void databaseOperate();
    void setWinStyle();

private:
    Ui::returnBook *ui;
    QSqlTableModel *model;
    DBOperator database; //数据库引入

private slots:
    void on_searchpushButton_clicked();

    void on_AllpushButton_clicked();

    void on_deletepushButton_clicked();
};

#endif // RETURNBOOK_H
