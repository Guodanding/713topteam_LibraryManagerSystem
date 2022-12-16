#ifndef READERMANAGER_H
#define READERMANAGER_H

#include <QWidget>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui
{ class readerManager; }
QT_END_NAMESPACE

class readerManager : public QWidget
{
    Q_OBJECT

public:
    readerManager(QWidget *parent = nullptr);
    ~readerManager();
    void setWinStyle();
    void databaseOperate();

private:
    Ui::readerManager *ui;
    QSqlTableModel *model;

private slots:
    void on_addpushButton_clicked();

    void on_deletepushButton_clicked();

    void on_modifypushButton_clicked();

    void on_SurepushButton_clicked();

    void on_searchpushButton_clicked();

};
#endif // READERMANAGER_H
