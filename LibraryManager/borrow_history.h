#ifndef BORROW_HISTORY_H
#define BORROW_HISTORY_H

#include <QWidget>
#include "dboperator.h"
#include <qsqltablemodel.h>

namespace Ui {
class borrow_history;
}

class borrow_history : public QWidget
{
    Q_OBJECT

public:
    explicit borrow_history(QWidget *parent = nullptr);
    ~borrow_history();
    void setusername(QString username);


private:
    Ui::borrow_history *ui;
    DBOperator DBO;
    QSqlTableModel *tm;
    QString Username ;
};

#endif // BORROW_HISTORY_H
