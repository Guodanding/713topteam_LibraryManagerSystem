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
    explicit ManagerMainWindow(bool isUserOrAdmin,QWidget *parent = nullptr);
    ~ManagerMainWindow();
    void setUsername(QString username);
    void setAdminname(QString adminname);
    void removeWidget(int index);
private slots:
    //admin
    void on_button_admin_book_1_clicked();
    void on_button_admin_book_2_clicked();
    void on_button_admin_user_1_clicked();
    void on_button_admin_sys_1_clicked();
    void on_button_admin_sys_2_clicked();
    //user
    void on_button_user_book_1_clicked();
    void on_button_user_book_2_clicked();
    void on_button_user_book_3_clicked();
    void on_button_user_set_1_clicked();
    void on_button_user_set_2_clicked();
    void on_button_user_set_3_clicked();

private:
    Ui::ManagerMainWindow *ui;
    bool isUser;
    bool isAdmin;
    int index;
    QString username;
    QString adminname;
};

#endif // MANAGERMAINWINDOW_H
