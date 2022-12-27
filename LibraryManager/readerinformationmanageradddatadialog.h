#ifndef READERINFORMATIONMANAGERADDDATADIALOG_H
#define READERINFORMATIONMANAGERADDDATADIALOG_H

#include <QSqlTableModel>
#include <QDialog>
#include <QAbstractButton>
#include <QPushButton>



namespace Ui {
class readerInformationManagerAdddatadialog;
}

class readerInformationManagerAdddatadialog : public QDialog
{
    Q_OBJECT

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

public:
    explicit readerInformationManagerAdddatadialog(QWidget *parent = nullptr, QSqlTableModel *_model = nullptr);
    ~readerInformationManagerAdddatadialog();

private:
    Ui::readerInformationManagerAdddatadialog *ui;
    QSqlTableModel* model;

};

#endif // READERINFORMATIONMANAGERADDDATADIALOG_H
