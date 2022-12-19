#ifndef BORROWBOOKINFORMATION_H
#define BORROWBOOKINFORMATION_H

#include <QWidget>
#include "dboperator.h"
#include <QSqlTableModel>

namespace Ui {
class borrowBookInformation;
}

class borrowBookInformation : public QWidget
{
    Q_OBJECT

public:
    explicit borrowBookInformation(QWidget *parent = nullptr);
    ~borrowBookInformation();
    void databaseOperate();
    void setWinStyle();

private:
    Ui::borrowBookInformation *ui;
    QSqlTableModel *model;
    DBOperator database; //数据库引入

private slots:
    void on_searchpushButton_clicked();

    void on_AllpushButton_clicked();

    void on_deletepushButton_clicked();
};

#endif // BORROWBOOKINFORMATION_H
