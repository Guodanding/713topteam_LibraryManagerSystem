#ifndef USERPROFILEMANAGER_H
#define USERPROFILEMANAGER_H

#include <QWidget>
#include <QSqlTableModel>
#include <QString>

namespace Ui {
class UserProfileManager;
}

class UserProfileManager : public QWidget
{
    Q_OBJECT

public:
    explicit UserProfileManager(QWidget *parent = nullptr);
    ~UserProfileManager();
    void setusername(QString username);

private slots:
    void on_AddpushButton_clicked();

private:
    Ui::UserProfileManager *ui;
    QSqlTableModel *model;
    QString Username ;
};

#endif // USERPROFILEMANAGER_H
