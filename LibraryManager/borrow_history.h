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

private slots:
    void on_ExitBtn_clicked();

private:
    Ui::borrow_history *ui;
    DBOperator DBO;
    QSqlTableModel *tm;
    QString Username = "Lee";
};

#endif // BORROW_HISTORY_H
