#ifndef BORROW_INFO_H
#define BORROW_INFO_H

#include <QWidget>
#include <QSqlTableModel>
#include "dboperator.h"

namespace Ui {
class borrow_info;
}

class borrow_info : public QWidget
{
    Q_OBJECT

public:
    explicit borrow_info(QWidget *parent = nullptr);
    ~borrow_info();
    void setusername(QString username);

private slots:
    void on_ReturnBtn_clicked();

    void on_ExitBtn_clicked();

private:
    Ui::borrow_info *ui;
    DBOperator DBO;
    QSqlTableModel *tm;
    QString Username = "Lee";
};

#endif // BORROW_INFO_H
