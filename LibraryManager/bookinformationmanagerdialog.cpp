#include "bookinformationmanagerdialog.h"
#include "ui_bookinformationmanagerdialog.h"

BookInformationManagerDialog::BookInformationManagerDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookInformationManagerDialog)
{
    ui->setupUi(this);
}

BookInformationManagerDialog::~BookInformationManagerDialog()
{
    delete ui;
}
