#ifndef BOOKINFORMATIONMANAGERADDDATADIALOG_H
#define BOOKINFORMATIONMANAGERADDDATADIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class BookInformationManagerAddDataDialog;
}

class BookInformationManagerAddDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookInformationManagerAddDataDialog(QWidget *parent = nullptr, QSqlTableModel *_model = nullptr);
    ~BookInformationManagerAddDataDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::BookInformationManagerAddDataDialog *ui;
    QSqlTableModel* model;
};

#endif // BOOKINFORMATIONMANAGERADDDATADIALOG_H
