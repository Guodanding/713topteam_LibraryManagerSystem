#include "userprofilemanager.h"
#include "ui_userprofilemanager.h"

UserProfileManager::UserProfileManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserProfileManager)
{
    ui->setupUi(this);
}

UserProfileManager::~UserProfileManager()
{
    delete ui;
}
