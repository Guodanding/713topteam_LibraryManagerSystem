#include "bookinformationmanager.h"
#include "managermainwindow.h"
#include "ui_managermainwindow.h"

ManagerMainWindow::ManagerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerMainWindow)
{
    ui->setupUi(this);
}

ManagerMainWindow::~ManagerMainWindow()
{
    delete ui;
}

void ManagerMainWindow::on_pushButton_clicked()
{
    BookManager *BookInformation = new BookManager();
    ui->horizontalLayout->addWidget(BookInformation);
}

