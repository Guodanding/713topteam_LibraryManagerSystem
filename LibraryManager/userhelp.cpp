#include "userhelp.h"
#include "ui_userhelp.h"

UserHelp::UserHelp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserHelp)
{
    ui->setupUi(this);
}

UserHelp::~UserHelp()
{
    delete ui;
}
