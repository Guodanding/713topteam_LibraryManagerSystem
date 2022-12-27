#ifndef USERHELP_H
#define USERHELP_H

#include <QWidget>

namespace Ui {
class UserHelp;
}

class UserHelp : public QWidget
{
    Q_OBJECT

public:
    explicit UserHelp(QWidget *parent = nullptr);
    ~UserHelp();

private:
    Ui::UserHelp *ui;
};

#endif // USERHELP_H
