#ifndef SIGNUP_H
#define SIGNUP_H
#include "QSqlTableModel"
#include <QWidget>
namespace Ui {
class SignUP;
}

class SignUP : public QWidget
{
    Q_OBJECT

public:
    explicit SignUP(QWidget *parent = nullptr);
    ~SignUP();

private slots:
    void on_pushButton_return_clicked();

    void on_pushButton_register_clicked();

    void on_lineEdit_email_textChanged(const QString &arg1);

    void on_lineEdit_phone_textChanged(const QString &arg1);

    void on_lineEdit_repassword_textChanged(const QString &arg1);

    void on_lineEdit_password_textChanged(const QString &arg1);

    void on_lineEdit_username_textChanged(const QString &arg1);

private:
    Ui::SignUP *ui;
    QSqlTableModel *model;//注册数据写入
    bool isEmailValid;
    bool isPhoneValid;
    bool isUsernameValid;
    bool isPasswordValid;
    bool isRePasswordValid;
};

#endif // SIGNUP_H
