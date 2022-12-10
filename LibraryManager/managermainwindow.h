#ifndef MANAGERMAINWINDOW_H
#define MANAGERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ManagerMainWindow;
}

class ManagerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerMainWindow(QWidget *parent = nullptr);
    ~ManagerMainWindow();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ManagerMainWindow *ui;
    int page_BookInfoMana;
    int page_BookClassMana;
};

#endif // MANAGERMAINWINDOW_H
