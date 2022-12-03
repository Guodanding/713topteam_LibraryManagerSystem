#ifndef SIGNUP_H
#define SIGNUP_H

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

private:
    Ui::SignUP *ui;
};

#endif // SIGNUP_H
