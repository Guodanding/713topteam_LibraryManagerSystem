#include "managermainwindow.h"
#include "ui_managermainwindow.h"
#include "bookinformationmanager.h"//引入图书信息管理子窗口
#include "bookclassifymanager.h"//引入
ManagerMainWindow::ManagerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerMainWindow)
{
    ui->setupUi(this);
    BookManager *BookInfoMana = new BookManager();
    BookClassifyManager *BookClassMana = new BookClassifyManager();
    page_BookInfoMana=ui->stackedWidget->addWidget(BookInfoMana);
    page_BookClassMana=ui->stackedWidget->addWidget(BookClassMana);
}

ManagerMainWindow::~ManagerMainWindow()
{
    delete ui;
}

void ManagerMainWindow::on_pushButton_1_clicked()
{

    ui->stackedWidget->setCurrentIndex(page_BookInfoMana);

};


void ManagerMainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(page_BookClassMana);

}

