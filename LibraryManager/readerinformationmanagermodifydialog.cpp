#include "readerinformationmanagermodifydialog.h"
#include "ui_readerinformationmanagermodifydialog.h"
#include <QString>
#include <QVariant>
#include <QSqlRecord>
#include <QAbstractButton>
#include "QMessageBox"

readerInformationManagerModifydialog::readerInformationManagerModifydialog(QWidget *parent, QSqlTableModel *_model, QSqlRecord *_record, int *_row) :
    QDialog(parent),
    ui(new Ui::readerInformationManagerModifydialog),
    model(_model),
    record(_record),
    row(_row)
{
    ui->setupUi(this);
    setWindowTitle("读者信息修改");

    ui->usernameLineEdit->setText(record->value("username").toString());
    ui->nameLineEdit->setText(record->value("name").toString());
    ui->passwordLineEdit->setText(record->value("password").toString());
    ui->emailLineEdit->setText(record->value("email").toString());
    ui->phoneLineEdit->setText(record->value("phone").toString());
    ui->scoreLineEdit->setText(record->value("score").toString());

}

readerInformationManagerModifydialog::~readerInformationManagerModifydialog()
{
    delete ui;
}

/*void readerInformationManagerModifydialog::on_buttonBox_accepted()
{

    if(ui->usernameLineEdit->text().isEmpty() || ui->nameLineEdit->text().isEmpty() ||
       ui->passwordLineEdit->text().isEmpty() || ui->emailLineEdit->text().isEmpty() ||
       ui->phoneLineEdit->text().isEmpty() || ui->scoreLineEdit->text().isEmpty())
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
    QString score = ui->scoreLineEdit->text();

    model->setData(model->index(*row, 1), QVariant(username));
    model->setData(model->index(*row, 2), QVariant(name));
    model->setData(model->index(*row, 3), QVariant(password));
    model->setData(model->index(*row, 4), QVariant(phone));
    model->setData(model->index(*row, 5), QVariant(email));
    model->setData(model->index(*row, 6), QVariant(score));
    model->setData(model->index(*row, 7), QVariant(""));
    model->setData(model->index(*row, 8),QVariant(""));

    model->submitAll();

    close();
}*/


void readerInformationManagerModifydialog::on_buttonBox_clicked(QAbstractButton *button)
{

    if(ui->buttonBox->button(QDialogButtonBox::Ok)  == button)
    {
        if(ui->usernameLineEdit->text().isEmpty() || ui->nameLineEdit->text().isEmpty() ||
                ui->passwordLineEdit->text().isEmpty() || ui->emailLineEdit->text().isEmpty() ||
                ui->phoneLineEdit->text().isEmpty() || ui->scoreLineEdit->text().isEmpty())
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
        QString score = ui->scoreLineEdit->text();

        model->setData(model->index(*row, 1), QVariant(username));
        model->setData(model->index(*row, 2), QVariant(name));
        model->setData(model->index(*row, 3), QVariant(password));
        model->setData(model->index(*row, 4), QVariant(phone));
        model->setData(model->index(*row, 5), QVariant(email));
        model->setData(model->index(*row, 6), QVariant(score));
        model->setData(model->index(*row, 7), QVariant(""));
        model->setData(model->index(*row, 8),QVariant(""));

        model->submitAll();
    }

    close();
}

