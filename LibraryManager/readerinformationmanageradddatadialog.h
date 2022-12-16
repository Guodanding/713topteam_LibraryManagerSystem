#ifndef READERINFORMATIONMANAGERADDDATADIALOG_H
#define READERINFORMATIONMANAGERADDDATADIALOG_H

#include <QSqlTableModel>
#include <QDialog>



namespace Ui {
class readerInformationManagerAdddatadialog;
}

class readerInformationManagerAdddatadialog : public QDialog
{
    Q_OBJECT

private slots:
    void on_buttonBox_accepted();

public:
    explicit readerInformationManagerAdddatadialog(QWidget *parent = nullptr, QSqlTableModel *_model = nullptr);
    ~readerInformationManagerAdddatadialog();

private:
    Ui::readerInformationManagerAdddatadialog *ui;
    QSqlTableModel* model;
    QSqlRecord *record;
    int *row;
};

#endif // READERINFORMATIONMANAGERADDDATADIALOG_H
