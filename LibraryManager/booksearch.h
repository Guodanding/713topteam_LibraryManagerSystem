#ifndef BOOKSEARCH_H
#define BOOKSEARCH_H

#include <QWidget>
#include "dboperator.h"
#include <QSqlTableModel>

namespace Ui {
class BookSearch;
}

class BookSearch : public QWidget
{
    Q_OBJECT

public:
    explicit BookSearch(QWidget *parent = nullptr);
    ~BookSearch();
    void setusername(QString username);

private slots:
    void on_SearchBtn_clicked();

    void on_BorrowBtn_clicked();

    void on_ExitBtn_clicked();

private:
    Ui::BookSearch *ui;
    DBOperator DBO;
    QSqlTableModel *tm;
    QString Username ;
    bool searchflag;
    QString bookName;
};

#endif // BOOKSEARCH_H
