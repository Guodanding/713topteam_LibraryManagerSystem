#ifndef BOOKINFORMATIONMANAGERMODIFYDIALOG_H
#define BOOKINFORMATIONMANAGERMODIFYDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class BookInformationManagerModifyDialog;
}

class BookInformationManagerModifyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookInformationManagerModifyDialog(QWidget *parent = nullptr, QSqlTableModel *_model = nullptr, QSqlRecord *_record = nullptr, int *_row = nullptr);
    ~BookInformationManagerModifyDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::BookInformationManagerModifyDialog *ui;
    QSqlTableModel* model;
    QSqlRecord *record;
    int *row;
};

#endif // BOOKINFORMATIONMANAGERMODIFYDIALOG_H
