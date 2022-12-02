#ifndef BOOKINFORMATIONMANAGERDIALOG_H
#define BOOKINFORMATIONMANAGERDIALOG_H

#include <QMainWindow>

namespace Ui {
class BookInformationManagerDialog;
}

class BookInformationManagerDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookInformationManagerDialog(QWidget *parent = nullptr);
    ~BookInformationManagerDialog();

private:
    Ui::BookInformationManagerDialog *ui;
};

#endif // BOOKINFORMATIONMANAGERDIALOG_H
