#ifndef BOOKINFORMATIONMANAGERADDDATADIALOG_H
#define BOOKINFORMATIONMANAGERADDDATADIALOG_H

#include <QDialog>

namespace Ui {
class BookInformationManagerAddDataDialog;
}

class BookInformationManagerAddDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BookInformationManagerAddDataDialog(QWidget *parent = nullptr);
    ~BookInformationManagerAddDataDialog();

private:
    Ui::BookInformationManagerAddDataDialog *ui;
};

#endif // BOOKINFORMATIONMANAGERADDDATADIALOG_H
