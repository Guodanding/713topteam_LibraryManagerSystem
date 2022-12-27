#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include"dboperator.h"//引入数据库
#include <QKeyEvent>//键盘事件
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    void keyPressEvent( QKeyEvent *k );
    void keyReleaseEvent( QKeyEvent *k );
private slots:
    void on_Button_login_clicked();
    void on_Button_signup_clicked();
    void on_radioButton_user_clicked();
    void on_radioButton_admin_clicked();
    void on_lineEdit_username_returnPressed();
    void on_lineEdit_password_returnPressed();


private:
    Ui::Login *ui;
    DBOperator database;//数据库引入
    bool isUserSelected;
    bool isAdminSelected;
};

#endif // LOGIN_H
