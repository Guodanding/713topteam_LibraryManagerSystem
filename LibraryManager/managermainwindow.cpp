#include "bookclassifymanager.h"
#include "ui_bookclassifymanager.h"
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
    BookClassifyManager *BookClassify = new BookClassifyManager();
    ui->horizontalLayout->addWidget(BookClassify);
}

