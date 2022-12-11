#ifndef BOOKINFORMATIONMANAGER_H
#define BOOKINFORMATIONMANAGER_H

#include <QWidget>
#include <QSqlTableModel>
#include "dboperator.h"

namespace Ui {
class BookManager;
}

class BookManager : public QWidget
{
    Q_OBJECT

public:
    explicit BookManager(QWidget *parent = nullptr);
    ~BookManager();
    void setWinStyle();
    void databaseOperate();

private slots:
    void on_AddpushButton_clicked();

    void on_DeletepushButton_clicked();

    void on_ModifypushButton_clicked();

    void on_CanclepushButton_clicked();

    void on_SurepushButton_clicked();

    void on_SearchpushButton_clicked();

    void on_AllpushButton_clicked();

private:
    Ui::BookManager *ui;
    DBOperator database; //数据库引入
    QSqlTableModel *model;
};

#endif // BOOKINFORMATIONMANAGER_H
