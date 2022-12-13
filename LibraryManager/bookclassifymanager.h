#ifndef BOOKCLASSIFYMANAGER_H
#define BOOKCLASSIFYMANAGER_H

#include <QWidget>
#include <QSqlTableModel>
#include "dboperator.h"


namespace Ui {
class BookClassifyManager;
}

class BookClassifyManager : public QWidget
{
    Q_OBJECT

public:
    explicit BookClassifyManager(QWidget *parent = nullptr);
    ~BookClassifyManager();
    void setWinStyle();
    void databaseOperate();

private slots:
    void on_AddpushButton_clicked();

    void on_SearchpushButton_clicked();

    void on_ModifypushButton_clicked();

    void on_CanclepushButton_clicked();

    void on_AllpushButton_clicked();

    void on_DeletepushButton_clicked();

    void on_SurepushButton_clicked();

private:
    Ui::BookClassifyManager *ui;
    DBOperator database; //数据库引入
    QSqlTableModel *model;
};

#endif // BOOKCLASSIFYMANAGER_H
