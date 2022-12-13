#include "managermainwindow.h"
#include "ui_managermainwindow.h"
#include "bookinformationmanager.h"//引入图书信息管理子窗口
#include "bookclassifymanager.h"//引入图书分类管理子窗口
#include "userprofilemanager.h"//引入用户主页
#include "QMovie"
#include "QLabel"
#include "QPushButton"
ManagerMainWindow::ManagerMainWindow(bool userOrAdmin,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerMainWindow)
{
    ui->setupUi(this);
    isAdmin=userOrAdmin;
    isUser=(!userOrAdmin);
    //创建子窗口
    BookManager *BookInfoMana = new BookManager();
    BookClassifyManager *BookClassMana = new BookClassifyManager();
    UserProfileManager *UserProfileMana = new UserProfileManager();
    page_BookInfoMana=ui->stackedWidget->addWidget(BookInfoMana);
    page_BookClassMana=ui->stackedWidget->addWidget(BookClassMana);
    page_UserProfileMana=ui->stackedWidget->addWidget(UserProfileMana);
    //topItem图书查询&借阅、系统管理
    QTreeWidgetItem *topItem1=new QTreeWidgetItem();
    topItem1->setText(0,"图书查询&借阅");
    QTreeWidgetItem *topItem2=new QTreeWidgetItem();
    topItem2->setText(0,"系统管理");
    QTreeWidgetItem *topItem3=new QTreeWidgetItem();
    topItem3->setText(0,"个人设置");
    ui->treeWidget->addTopLevelItem(topItem1);
    ui->treeWidget->addTopLevelItem(topItem2);
    ui->treeWidget->addTopLevelItem(topItem3);
    ui->treeWidget->setRootIsDecorated(false);//不显示三角形
    //subitem用户管理、角色管理、图书管理、资源管理
    QTreeWidgetItem *subItem_book_1=new QTreeWidgetItem(topItem1);
    QTreeWidgetItem *subItem_book_2=new QTreeWidgetItem(topItem1);
    QTreeWidgetItem *subItem_sys_1=new QTreeWidgetItem(topItem2);
    QTreeWidgetItem *subItem_sys_2=new QTreeWidgetItem(topItem2);
    QTreeWidgetItem *subItem_sys_3=new QTreeWidgetItem(topItem2);
    QTreeWidgetItem *subItem_sys_4=new QTreeWidgetItem(topItem2);
    QTreeWidgetItem *subItem_user_1=new QTreeWidgetItem(topItem3);
    QTreeWidgetItem *subItem_user_2=new QTreeWidgetItem(topItem3);
    //topItem->setIcon(0,QIcon("D:\\favicon.ico"));设置图标

    //add subfuntion
    QPushButton *button_book_1=new QPushButton("图书信息管理");
    QPushButton *button_book_2=new QPushButton("图书分类管理");
    QPushButton *button_sys_1=new QPushButton("用户管理");
    QPushButton *button_sys_2=new QPushButton("角色管理");
    QPushButton *button_sys_3=new QPushButton("图书管理");
    QPushButton *button_sys_4=new QPushButton("资源管理");
    QPushButton *button_user_1=new QPushButton("个人主页");
    QPushButton *button_user_2=new QPushButton("借阅情况");
    button_sys_1->setStyleSheet("background-color: rgb(29, 123, 255);"
                            "color: rgb(255, 255, 255);");
    ui->treeWidget->setItemWidget(subItem_book_1,0,button_book_1);
    ui->treeWidget->setItemWidget(subItem_book_2,0,button_book_2);
    ui->treeWidget->setItemWidget(subItem_sys_1,0,button_sys_1);
    ui->treeWidget->setItemWidget(subItem_sys_2,0,button_sys_2);
    ui->treeWidget->setItemWidget(subItem_sys_3,0,button_sys_3);
    ui->treeWidget->setItemWidget(subItem_sys_4,0,button_sys_4);
    ui->treeWidget->setItemWidget(subItem_user_1,0,button_user_1);
    ui->treeWidget->setItemWidget(subItem_user_2,0,button_user_2);
    //connect signal
    connect(button_book_1,SIGNAL(clicked()),this,SLOT(on_button_book_1_clicked()));
    connect(button_book_2,SIGNAL(clicked()),this,SLOT(on_button_book_2_clicked()));
    connect(button_user_1,SIGNAL(clicked()),this,SLOT(on_button_user_1_clicked()));
    connect(button_user_2,SIGNAL(clicked()),this,SLOT(on_button_user_2_clicked()));

    //树最顶部名称
    QStringList top;
    top << "功能选择";
    ui->treeWidget->setHeaderLabels(top);
    //展开子树
    topItem1->setExpanded(true);
    topItem2->setExpanded(true);
    topItem3->setExpanded(true);
    // 显示gif图片
    ui->label_bacgroud->setWindowFlag(Qt::FramelessWindowHint);// 设置无边框
    static QMovie movie(":/images/3.gif");
    ui->label_bacgroud->setMovie(&movie);
    ui->label_bacgroud->setScaledContents(true);
    movie.start();
}

void ManagerMainWindow::setUsername(QString username)
{
    userInfo.username=username;
}
void ManagerMainWindow::setAdminname(QString adminname)
{
    adminInfo.username=adminname;
}

ManagerMainWindow::~ManagerMainWindow()
{
    delete ui;
}
//图书管理
void ManagerMainWindow::on_button_book_1_clicked(){ ui->stackedWidget->setCurrentIndex(page_BookInfoMana);}
void ManagerMainWindow::on_button_book_2_clicked(){ui->stackedWidget->setCurrentIndex(page_BookClassMana);}
//系统管理
void ManagerMainWindow::on_button_sys_1_clicked(){ ui->stackedWidget->setCurrentIndex(page_BookInfoMana);}
void ManagerMainWindow::on_button_sys_2_clicked(){ui->stackedWidget->setCurrentIndex(page_BookClassMana);}
void ManagerMainWindow::on_button_sys_3_clicked(){ ui->stackedWidget->setCurrentIndex(page_BookInfoMana);}
void ManagerMainWindow::on_button_sys_4_clicked(){ui->stackedWidget->setCurrentIndex(page_BookClassMana);}
//用户个人设置
void ManagerMainWindow::on_button_user_1_clicked(){ ui->stackedWidget->setCurrentIndex(page_UserProfileMana);}
void ManagerMainWindow::on_button_user_2_clicked(){ ui->stackedWidget->setCurrentIndex(page_UserProfileMana);}
