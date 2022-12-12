#ifndef MANAGERMAINWINDOW_H
#define MANAGERMAINWINDOW_H

#include <QMainWindow>

struct admin
{
    QString username;
    QString password;

};
struct user
{
    int ID;
    QString username;
    QString password;
    QString name;
    QString phone;
    QString email;
};
namespace Ui {
class ManagerMainWindow;
}

class ManagerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManagerMainWindow(bool userOrAdmin,QWidget *parent = nullptr);
    ~ManagerMainWindow();
    void setUsername(QString username);
    void setAdminname(QString adminname);
private slots:
    void on_button_book_1_clicked();
    void on_button_book_2_clicked();
    void on_button_sys_1_clicked();
    void on_button_sys_2_clicked();
    void on_button_sys_3_clicked();
    void on_button_sys_4_clicked();
    void on_button_user_1_clicked();
    void on_button_user_2_clicked();
private:
    Ui::ManagerMainWindow *ui;
    int page_BookInfoMana;
    int page_BookClassMana;
    int page_UserProfileMana;
    struct admin adminInfo;
    struct user userInfo;
    bool isUser;
    bool isAdmin;
};

#endif // MANAGERMAINWINDOW_H
