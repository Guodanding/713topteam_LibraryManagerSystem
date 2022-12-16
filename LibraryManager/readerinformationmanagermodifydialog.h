#ifndef READERINFORMATIONMANAGERMODIFYDIALOG_H
#define READERINFORMATIONMANAGERMODIFYDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

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
    void on_buttonBox_accepted();

private:
    Ui::readerInformationManagerModifydialog *ui;
    QSqlTableModel* model;
    QSqlRecord *record;
    int *row;
};

#endif // READERINFORMATIONMANAGERMODIFYDIALOG_H
