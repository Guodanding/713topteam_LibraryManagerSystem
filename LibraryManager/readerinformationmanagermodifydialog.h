#ifndef READERINFORMATIONMANAGERMODIFYDIALOG_H
#define READERINFORMATIONMANAGERMODIFYDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QAbstractButton>
#include <QPushButton>


namespace Ui {
class readerInformationManagerModifydialog;
}

class readerInformationManagerModifydialog : public QDialog
{
    Q_OBJECT

public:
    explicit readerInformationManagerModifydialog(QWidget *parent = nullptr, QSqlTableModel *_model = nullptr, QSqlRecord *_record = nullptr, int *_row = nullptr);
    ~readerInformationManagerModifydialog();

private slots:
    //void on_buttonBox_accepted();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::readerInformationManagerModifydialog *ui;
    QSqlTableModel* model;
    QSqlRecord *record;
    int *row;
};

#endif // READERINFORMATIONMANAGERMODIFYDIALOG_H
