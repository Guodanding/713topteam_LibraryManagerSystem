#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"login.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //打开登录窗口
    Login *login=new Login(this);
    login->setWindowFlag(Qt::Window);
    login->show();
    //

}

MainWindow::~MainWindow()
{
    delete ui;
}

