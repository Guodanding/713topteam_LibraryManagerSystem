#include "readerinformationmanageradddatadialog.h"
#include "ui_readerinformationmanageradddatadialog.h"
#include <QString>
#include <QVariant>
#include <QSqlRecord>
#include "QMessageBox"

readerInformationManagerAdddatadialog::readerInformationManagerAdddatadialog(QWidget *parent, QSqlTableModel *_model) :
    QDialog(parent),
    ui(new Ui::readerInformationManagerAdddatadialog),
    model(_model)
{
    ui->setupUi(this);
    setWindowTitle("添加读者信息");

    QStringList cbList;
    cbList <<"0"<<"1";
    ui->statuscomboBox->addItems(cbList);

    ui->statuscomboBox->setCurrentText(record->value("状态").toString());
    ui->usernameLineEdit->setText(record->value("用户名").toString());
    ui->nameLineEdit->setText(record->value("读者名字").toString());
    ui->passwordLineEdit->setText(record->value("密码").toString());
    ui->emailLineEdit->setText(record->value("电子邮箱").toString());
    ui->phoneLineEdit->setText(record->value("手机号码").toString());
    ui->lend_numLineEdit->setText(record->value("借阅数量").toString());
    ui->max_numLineEdit->setText(record->value("最大借阅数量").toString());
}

readerInformationManagerAdddatadialog::~readerInformationManagerAdddatadialog()
{
    delete ui;
}

void readerInformationManagerAdddatadialog::on_buttonBox_accepted()
{
    if(ui->usernameLineEdit->text().isEmpty() || ui->nameLineEdit->text().isEmpty() ||
       ui->passwordLineEdit->text().isEmpty() || ui->emailLineEdit->text().isEmpty() ||
       ui->statuscomboBox->currentText().isEmpty() || ui->lend_numLineEdit->text().isEmpty() ||
       ui->max_numLineEdit->text().isEmpty()||ui->phoneLineEdit->text().isEmpty())
    {
        QMessageBox::StandardButton result = QMessageBox::warning(this, "错误", "请输入完整信息！");
        if(result == QMessageBox::Ok)
            return;
    }

    QString username = ui->usernameLineEdit->text();
    QString name = ui->nameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString status = ui->statuscomboBox->currentText();
    QString lend_num = ui->lend_numLineEdit->text();
    QString max_num = ui->max_numLineEdit->text();
    QString phone=ui->phoneLineEdit->text();

    model->setFilter("");
    model->select();//展示所有

    model->insertRows(model->rowCount(), 1);
    model->setData(model->index(model->rowCount() - 1, 0), QVariant(model->rowCount()));
    model->setData(model->index(model->rowCount() - 1, 1), QVariant(username));
    model->setData(model->index(model->rowCount() - 1, 2), QVariant(name));
    model->setData(model->index(model->rowCount() - 1, 3), QVariant(password));
    model->setData(model->index(model->rowCount() - 1, 4), QVariant(email));
    model->setData(model->index(model->rowCount() - 1, 5), QVariant(phone));
    model->setData(model->index(model->rowCount() - 1, 6), QVariant(status));
    model->setData(model->index(model->rowCount() - 1, 7), QVariant(lend_num));
    model->setData(model->index(model->rowCount() - 1, 8), QVariant(max_num));
    model->setData(model->index(model->rowCount() - 1, 9), QVariant(""));
    model->setData(model->index(model->rowCount() - 1, 10), QVariant(""));

    model->submitAll();
    if (model->submitAll())
        QMessageBox::about(this, "添加", "添加成功！");
}