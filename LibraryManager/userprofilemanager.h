#ifndef USERPROFILEMANAGER_H
#define USERPROFILEMANAGER_H

#include <QWidget>

namespace Ui {
class UserProfileManager;
}

class UserProfileManager : public QWidget
{
    Q_OBJECT

public:
    explicit UserProfileManager(QWidget *parent = nullptr);
    ~UserProfileManager();

private:
    Ui::UserProfileManager *ui;
};

#endif // USERPROFILEMANAGER_H
