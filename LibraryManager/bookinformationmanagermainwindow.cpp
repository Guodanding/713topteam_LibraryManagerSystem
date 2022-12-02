#include "bookinformationmanagermainwindow.h"
#include "ui_bookinformationmanagermainwindow.h"

BookInformationManagerMainWindow::BookInformationManagerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookInformationManagerMainWindow)
{
    ui->setupUi(this);
    setWindowTitle("图书信息管理模块");
}

BookInformationManagerMainWindow::~BookInformationManagerMainWindow()
{
    delete ui;
}
