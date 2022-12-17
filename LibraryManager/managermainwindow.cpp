#include "managermainwindow.h"
#include "ui_managermainwindow.h"
#include "bookinformationmanager.h"//引入图书信息管理子窗口
#include "bookclassifymanager.h"//引入图书分类管理子窗口
#include "userprofilemanager.h"//引入用户主页
#include "readermanager.h"//引入用户管理子窗口
#include "login.h"//引入登录窗口
#include "booksearch.h"//引入图书搜索
#include "borrow_history.h"//引入用户模块借阅历史查询
#include "borrow_info.h"//引入用户模块图书借阅信息
#include "QMovie"
#include "QLabel"
#include "QPushButton"
ManagerMainWindow::ManagerMainWindow(bool isUserOrAdmin,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerMainWindow)
{
    ui->setupUi(this);
    isAdmin=isUserOrAdmin;
    isUser=!isUserOrAdmin;
    qDebug()<<"isUserOrAdmin "<<isUserOrAdmin;
    if (isUser) {
        //（读者）图书查询模块
        //（读者）图书借阅信息模块
        //（读者）借阅历史查询模块
        //topItem
        QTreeWidgetItem *topItem_user_1=new QTreeWidgetItem();
        topItem_user_1->setText(0,"功能");
        QTreeWidgetItem *topItem_user_2=new QTreeWidgetItem();
        topItem_user_2->setText(0,"个人设置");
        ui->treeWidget->addTopLevelItem(topItem_user_1);
        ui->treeWidget->addTopLevelItem(topItem_user_2);
        //subitem
        QTreeWidgetItem *subItem_user_book_1=new QTreeWidgetItem(topItem_user_1);
        QTreeWidgetItem *subItem_user_book_2=new QTreeWidgetItem(topItem_user_1);
        QTreeWidgetItem *subItem_user_book_3=new QTreeWidgetItem(topItem_user_1);
        QTreeWidgetItem *subItem_user_set_1=new QTreeWidgetItem(topItem_user_2);
        QTreeWidgetItem *subItem_user_set_2=new QTreeWidgetItem(topItem_user_2);
        //subfuntion;
        QPushButton *button_user_book_1=new QPushButton("图书查询");
        QPushButton *button_user_book_2=new QPushButton("图书借阅信息");
        QPushButton *button_user_book_3=new QPushButton("借阅历史查询");
        QPushButton *button_user_set_1=new QPushButton("个人主页");
        QPushButton *button_user_set_2=new QPushButton("退出登录");
        //connect btn and subitem
        ui->treeWidget->setItemWidget(subItem_user_book_1,0,button_user_book_1);
        ui->treeWidget->setItemWidget(subItem_user_book_2,0,button_user_book_2);
        ui->treeWidget->setItemWidget(subItem_user_book_3,0,button_user_book_3);
        ui->treeWidget->setItemWidget(subItem_user_set_1,0,button_user_set_1);
        ui->treeWidget->setItemWidget(subItem_user_set_2,0,button_user_set_2);
        //connect signal
        connect(button_user_book_1,SIGNAL(clicked()),this,SLOT(on_button_user_book_1_clicked()));
        connect(button_user_book_2,SIGNAL(clicked()),this,SLOT(on_button_user_book_2_clicked()));
        connect(button_user_book_3,SIGNAL(clicked()),this,SLOT(on_button_user_book_3_clicked()));
        connect(button_user_set_1,SIGNAL(clicked()),this,SLOT(on_button_user_set_1_clicked()));
        connect(button_user_set_2,SIGNAL(clicked()),this,SLOT(on_button_user_set_2_clicked()));
        //展开子树
        topItem_user_1->setExpanded(true);
        topItem_user_2->setExpanded(true);
        //style
    }
    else if (isAdmin) {
        //（管理员）图书信息管理模块实现（郭铠槟）
        //（管理员）图书分类管理模块实现（郭铠槟）
        //（管理员）读者管理模块实现
        //（管理员）图书借阅信息模块实现
        //（管理员）图书归还信息管理模块实现
        //topItem
        QTreeWidgetItem *topItem_admin_1=new QTreeWidgetItem();
        topItem_admin_1->setText(0,"图书管理");
        QTreeWidgetItem *topItem_admin_2=new QTreeWidgetItem();
        topItem_admin_2->setText(0,"读者管理");
        QTreeWidgetItem *topItem_admin_3=new QTreeWidgetItem();
        topItem_admin_3->setText(0,"系统管理");
        ui->treeWidget->addTopLevelItem(topItem_admin_1);
        ui->treeWidget->addTopLevelItem(topItem_admin_2);
        ui->treeWidget->addTopLevelItem(topItem_admin_3);
        //subitem
        QTreeWidgetItem *subItem_admin_book_1=new QTreeWidgetItem(topItem_admin_1);
        QTreeWidgetItem *subItem_admin_book_2=new QTreeWidgetItem(topItem_admin_1);
        QTreeWidgetItem *subItem_admin_user_1=new QTreeWidgetItem(topItem_admin_2);
        QTreeWidgetItem *subItem_admin_user_2=new QTreeWidgetItem(topItem_admin_2);
        QTreeWidgetItem *subItem_admin_sys_1=new QTreeWidgetItem(topItem_admin_3);
        QTreeWidgetItem *subItem_admin_sys_2=new QTreeWidgetItem(topItem_admin_3);
        //subfuntion
        QPushButton *button_admin_book_1=new QPushButton("图书信息管理");
        QPushButton *button_admin_book_2=new QPushButton("图书分类管理");
        QPushButton *button_admin_user_1=new QPushButton("用户管理");
        QPushButton *button_admin_user_2=new QPushButton("角色管理");
        QPushButton *button_admin_sys_1=new QPushButton("图书借阅信息");
        QPushButton *button_admin_sys_2=new QPushButton("图书归还信息");
        //connect btn and subitem
        ui->treeWidget->setItemWidget(subItem_admin_book_1,0,button_admin_book_1);
        ui->treeWidget->setItemWidget(subItem_admin_book_2,0,button_admin_book_2);
        ui->treeWidget->setItemWidget(subItem_admin_user_1,0,button_admin_user_1);
        ui->treeWidget->setItemWidget(subItem_admin_user_2,0,button_admin_user_2);
        ui->treeWidget->setItemWidget(subItem_admin_sys_1,0,button_admin_sys_1);
        ui->treeWidget->setItemWidget(subItem_admin_sys_2,0,button_admin_sys_2);
        //connect signal
        connect(button_admin_book_1,SIGNAL(clicked()),this,SLOT(on_button_admin_book_1_clicked()));
        connect(button_admin_book_2,SIGNAL(clicked()),this,SLOT(on_button_admin_book_2_clicked()));
        connect(button_admin_user_1,SIGNAL(clicked()),this,SLOT(on_button_admin_user_1_clicked()));
        connect(button_admin_user_2,SIGNAL(clicked()),this,SLOT(on_button_admin_user_2_clicked()));
        connect(button_admin_sys_1,SIGNAL(clicked()),this,SLOT(on_button_admin_sys_1_clicked()));
        connect(button_admin_sys_2,SIGNAL(clicked()),this,SLOT(on_button_admin_sys_2_clicked()));
        //展开子树
        topItem_admin_1->setExpanded(true);
        topItem_admin_2->setExpanded(true);
        topItem_admin_3->setExpanded(true);
        //style
        button_admin_book_1->setStyleSheet("background-color: rgb(29, 123, 255);"
                                "color: rgb(255, 255, 255);");
    }
    //不显示左边三角形
    ui->treeWidget->setRootIsDecorated(false);
    //树最顶部名称
    QStringList top;
    top << "功能选择";
    ui->treeWidget->setHeaderLabels(top);
    // 显示gif图片
    ui->label_bacgroud->setWindowFlag(Qt::FramelessWindowHint);// 设置无边框
    static QMovie movie(":/images/3.gif");
    ui->label_bacgroud->setMovie(&movie);
    ui->label_bacgroud->setScaledContents(true);
    movie.start();
}

void ManagerMainWindow::setUsername(QString username)//用户标志
{
    this->username=username;
}
void ManagerMainWindow::setAdminname(QString adminname)//管理员标志
{
    this->adminname=adminname;
}
void ManagerMainWindow::removeWidget(int index)
{
    ui->stackedWidget->widgetRemoved(index);
}
ManagerMainWindow::~ManagerMainWindow()
{
    delete ui;
}

//读者模块
void ManagerMainWindow::on_button_user_book_1_clicked()
{
    removeWidget(index);
    BookSearch *booksearch = new BookSearch();
    index=ui->stackedWidget->addWidget(booksearch);
    ui->stackedWidget->setCurrentIndex(index);
}
void ManagerMainWindow::on_button_user_book_2_clicked()
{
    removeWidget(index);
    borrow_info *borrowinfo = new borrow_info();
    index=ui->stackedWidget->addWidget(borrowinfo);
    ui->stackedWidget->setCurrentIndex(index);
}
void ManagerMainWindow::on_button_user_book_3_clicked()
{
    removeWidget(index);
    borrow_history *borrowhistory = new borrow_history();
    index=ui->stackedWidget->addWidget(borrowhistory);
    ui->stackedWidget->setCurrentIndex(index);
}
void ManagerMainWindow::on_button_user_set_1_clicked()
{
    removeWidget(index);
    UserProfileManager *UserProfileMana = new UserProfileManager();
    index=ui->stackedWidget->addWidget(UserProfileMana);
    ui->stackedWidget->setCurrentIndex(index);
}
void ManagerMainWindow::on_button_user_set_2_clicked()
{
    this->close();
    //打开登录窗口
    Login *login=new Login(this);
    login->setWindowFlag(Qt::Window);
    login->show();
}
//管理员模块
void ManagerMainWindow::on_button_admin_book_1_clicked()
{
    removeWidget(index);
    BookManager *BookInfoMana = new BookManager();
    index=ui->stackedWidget->addWidget(BookInfoMana);
    ui->stackedWidget->setCurrentIndex(index);
}
void ManagerMainWindow::on_button_admin_book_2_clicked()
{
    removeWidget(index);
    BookClassifyManager *BookClassMana = new BookClassifyManager();
    index=ui->stackedWidget->addWidget(BookClassMana);
    ui->stackedWidget->setCurrentIndex(index);
}
void ManagerMainWindow::on_button_admin_user_1_clicked()
{
    removeWidget(index);
    readerManager *readermanager=new readerManager();
    index=ui->stackedWidget->addWidget(readermanager);
    ui->stackedWidget->setCurrentIndex(index);
}
void ManagerMainWindow::on_button_admin_user_2_clicked()
{
    removeWidget(index);
    BookClassifyManager *BookClassMana = new BookClassifyManager();
    index=ui->stackedWidget->addWidget(BookClassMana);
    ui->stackedWidget->setCurrentIndex(index);
}
void ManagerMainWindow::on_button_admin_sys_1_clicked()
{
    removeWidget(index);
    BookManager *BookInfoMana = new BookManager();
    index=ui->stackedWidget->addWidget(BookInfoMana);
    ui->stackedWidget->setCurrentIndex(index);
}
void ManagerMainWindow::on_button_admin_sys_2_clicked()
{
    removeWidget(index);
    BookClassifyManager *BookClassMana = new BookClassifyManager();
    index=ui->stackedWidget->addWidget(BookClassMana);
    ui->stackedWidget->setCurrentIndex(index);
}
