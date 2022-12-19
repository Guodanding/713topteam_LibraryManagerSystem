#include "readerinformationmanagermodifydialog.h"
#include "ui_readerinformationmanagermodifydialog.h"
#include <QString>
#include <QVariant>
#include <QSqlRecord>
#include "QMessageBox"

readerInformationManagerModifydialog::readerInformationManagerModifydialog(QWidget *parent, QSqlTableModel *_model, QSqlRecord *_record, int *_row) :
    QDialog(parent),
    model(_model),
    record(_record),
    row(_row),
    ui(new Ui::readerInformationManagerModifydialog)
{
    ui->setupUi(this);
    setWindowTitle("读者信息修改");

    ui->usernameLineEdit->setText(record->value("用户名").toString());
    ui->nameLineEdit->setText(record->value("读者名字").toString());
    ui->passwordLineEdit->setText(record->value("密码").toString());
    ui->emailLineEdit->setText(record->value("电子邮箱").toString());
    ui->phoneLineEdit->setText(record->value("手机号码").toString());
}

readerInformationManagerModifydialog::~readerInformationManagerModifydialog()
{
    delete ui;
}

void readerInformationManagerModifydialog::on_buttonBox_accepted()
{
    if(ui->usernameLineEdit->text().isEmpty() || ui->nameLineEdit->text().isEmpty() ||
       ui->passwordLineEdit->text().isEmpty() || ui->emailLineEdit->text().isEmpty() ||
       ui->phoneLineEdit->text().isEmpty())
    {
        QMessageBox::StandardButton result = QMessageBox::warning(this, "错误", "请输入完整信息！");
        if(result == QMessageBox::Ok)
            return;
    }

    QString username = ui->usernameLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString phone=ui->phoneLineEdit->text();

    model->setData(model->index(*row, 1), QVariant(username));
    model->setData(model->index(*row, 2), QVariant(name));
    model->setData(model->index(*row, 3), QVariant(password));
    model->setData(model->index(*row, 4), QVariant(phone));
    model->setData(model->index(*row, 5), QVariant(email));
    model->setData(model->index(*row, 6), QVariant(""));
    model->setData(model->index(*row, 7),QVariant(""));

    if (model->submitAll())
    {   QMessageBox::about(this, "修改", "修改成功！");
        this->close();
    }
    model->setFilter("");
    model->select();//展示所有
}
