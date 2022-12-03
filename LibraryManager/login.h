#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include"dboperator.h"//引入数据库
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_Button_login_clicked();

    void on_Button_signup_clicked();

private:
    Ui::Login *ui;
    DBOperator database;//数据库引入
};

#endif // LOGIN_H
