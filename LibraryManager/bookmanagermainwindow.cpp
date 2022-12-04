#include "bookmanagermainwindow.h"
#include "ui_bookmanagermainwindow.h"

BookManagerMainWindow::BookManagerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookManagerMainWindow)
{
    ui->setupUi(this);
    setWindowTitle("图书信息管理模块");
}

BookManagerMainWindow::~BookManagerMainWindow()
{
    delete ui;
}
