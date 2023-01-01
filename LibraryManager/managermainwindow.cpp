#include "managermainwindow.h"
#include "ui_managermainwindow.h"
#include "bookinformationmanager.h"//引入图书信息管理子窗口
#include "bookclassifymanager.h"//引入图书分类管理子窗口
#include "userprofilemanager.h"//引入用户主页
#include "readermanager.h"//引入用户管理子窗口
#include "returnbook.h"//引入图书归还信息子窗口
#include "borrowbookinformation.h"//引入借阅图书信息子窗口
#include "login.h"//引入登录窗口
#include "booksearch.h"//引入图书搜索
#include "borrow_history.h"//引入用户模块借阅历史查询
#include "borrow_info.h"//引入用户模块图书借阅信息
#include "returnbook.h"//引入管理员图书归还历史
#include "userhelp.h"//使用手册
#include "QMovie"
#include "QLabel"
#include "QMessageBox"
ManagerMainWindow::ManagerMainWindow(bool isUserOrAdmin,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerMainWindow)
{
    ui->setupUi(this);
    //fix window size
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(),this->height());
    isAdmin=isUserOrAdmin;
    isUser=!isUserOrAdmin;
    qDebug()<<"isUserOrAdmin "<<isUserOrAdmin;
    buttonStyle_unchecked="QPushButton{"
                        "border:none;"
                        "color:#999999;"
                        "font:15pt '黑体';"
                        "background-color: rgb(19, 30, 38);"
                        "}"
                        "QPushButton::pressed{"
                        "padding-top:2px;"
                        "padding-left:2px;"
                        "}"
                        "QPushButton::hover{"
                        "border:none;"
                        "font:15pt '黑体';"
                        "color:#FFFFFF;"
                        "}";
    buttonStyle_checked="QPushButton{"
                        "border:none;"
                        "color:#FFFFFF;"
                        "font:15pt '黑体';"
                        "background-color: rgb(19, 30, 38);"
                        "}";
    if (isUser) {
        //（读者）图书查询模块
        //（读者）图书借阅信息模块
        //（读者）借阅历史查询模块
        //topItem
        QTreeWidgetItem *topItem_user_1=new QTreeWidgetItem();
        topItem_user_1->setText(0,"查询&借阅");
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
        button_user_book_1=new QPushButton("图书查询");
        button_user_book_2=new QPushButton("图书借阅信息");
        button_user_book_3=new QPushButton("借阅历史查询");
        button_user_set_1=new QPushButton("个人主页");
        button_user_set_2=new QPushButton("使用帮助");
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
        //打开图书查询
        on_button_user_book_1_clicked();
        //style
        initUserStyle();
        topItem_user_1->setIcon(0,QIcon(":/images/search.png"));
        topItem_user_2->setIcon(0,QIcon(":/images/profile.png"));
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
        QTreeWidgetItem *subItem_admin_sys_1=new QTreeWidgetItem(topItem_admin_3);
        QTreeWidgetItem *subItem_admin_sys_2=new QTreeWidgetItem(topItem_admin_3);
        //subfuntion
        button_admin_book_1=new QPushButton("图书信息管理");
        button_admin_book_2=new QPushButton("图书分类管理");
        button_admin_user_1=new QPushButton("用户管理");
        button_admin_sys_1=new QPushButton("图书借阅信息");
        button_admin_sys_2=new QPushButton("图书归还信息");
        //connect btn and subitem
        ui->treeWidget->setItemWidget(subItem_admin_book_1,0,button_admin_book_1);
        ui->treeWidget->setItemWidget(subItem_admin_book_2,0,button_admin_book_2);
        ui->treeWidget->setItemWidget(subItem_admin_user_1,0,button_admin_user_1);
        ui->treeWidget->setItemWidget(subItem_admin_sys_1,0,button_admin_sys_1);
        ui->treeWidget->setItemWidget(subItem_admin_sys_2,0,button_admin_sys_2);
        //connect signal
        connect(button_admin_book_1,SIGNAL(clicked()),this,SLOT(on_button_admin_book_1_clicked()));
        connect(button_admin_book_2,SIGNAL(clicked()),this,SLOT(on_button_admin_book_2_clicked()));
        connect(button_admin_user_1,SIGNAL(clicked()),this,SLOT(on_button_admin_user_1_clicked()));
        connect(button_admin_sys_1,SIGNAL(clicked()),this,SLOT(on_button_admin_sys_1_clicked()));
        connect(button_admin_sys_2,SIGNAL(clicked()),this,SLOT(on_button_admin_sys_2_clicked()));
        //展开子树
        topItem_admin_1->setExpanded(true);
        topItem_admin_2->setExpanded(true);
        topItem_admin_3->setExpanded(true);
        //style
        initAdminStyle();
        topItem_admin_1->setIcon(0,QIcon(":/images/bookmana.png"));
        topItem_admin_2->setIcon(0,QIcon(":/images/usermana.png"));
        topItem_admin_3->setIcon(0,QIcon(":/images/log.png"));
        //打开管理员
        on_button_admin_book_1_clicked();
    }
    //logout button style
    ui->button_logout->setIconSize(QSize(48,48));
    ui->button_logout->setIcon(QIcon(":/images/logout.png"));
    QString treeStyle;
    treeStyle="QTreeView{"
            "border-radius: 20px;"
            "font: 18pt '黑体';"
              "color: white;"
            "outline:none;"
            "background-color: rgb(19, 30, 38);"
              "}"
              "QTreeWidget::item:selected{"
              "outline:none;"
              "}"
              "QTreeView::item {"
            "background-color: rgb(19, 30, 38);"
            "margin:10px;"
              "}";
    ui->treeWidget->setStyleSheet(treeStyle);
    //不显示左边三角形
    ui->treeWidget->setRootIsDecorated(false);
}

void ManagerMainWindow::setUsername(QString username)//用户标志
{
    this->username=username;
    qDebug()<<"username"<<this->username;
}
void ManagerMainWindow::setAdminname(QString adminname)//管理员标志
{
    this->adminname=adminname;
    qDebug()<<"adminname"<<this->adminname;
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
    booksearch->setusername(username);
    index=ui->stackedWidget->addWidget(booksearch);
    ui->stackedWidget->setCurrentIndex(index);
    initUserStyle();
    button_user_book_1->setStyleSheet(buttonStyle_checked);
}
void ManagerMainWindow::on_button_user_book_2_clicked()
{
    removeWidget(index);
    borrow_info *borrowinfo = new borrow_info();
    borrowinfo->setusername(username);
    index=ui->stackedWidget->addWidget(borrowinfo);
    ui->stackedWidget->setCurrentIndex(index);
    initUserStyle();
    button_user_book_2->setStyleSheet(buttonStyle_checked);
}
void ManagerMainWindow::on_button_user_book_3_clicked()
{
    removeWidget(index);
    borrow_history *borrowhistory = new borrow_history();
    borrowhistory->setusername(username);
    index=ui->stackedWidget->addWidget(borrowhistory);
    ui->stackedWidget->setCurrentIndex(index);
    initUserStyle();
    button_user_book_3->setStyleSheet(buttonStyle_checked);
}
void ManagerMainWindow::on_button_user_set_1_clicked()
{
    removeWidget(index);
    UserProfileManager *UserProfileMana = new UserProfileManager();
    index=ui->stackedWidget->addWidget(UserProfileMana);
    ui->stackedWidget->setCurrentIndex(index);
    initUserStyle();
    button_user_set_1->setStyleSheet(buttonStyle_checked);
}
void ManagerMainWindow::on_button_user_set_2_clicked()
{
    removeWidget(index);
    UserHelp *userhelp = new UserHelp();
    index=ui->stackedWidget->addWidget(userhelp);
    ui->stackedWidget->setCurrentIndex(index);
    initUserStyle();
    button_user_set_2->setStyleSheet(buttonStyle_checked);
}
void ManagerMainWindow::on_button_logout_clicked()
{
    QMessageBox::StandardButton answer = QMessageBox::question(this,"登出","你确定要退出登录吗？");
    if(answer == QMessageBox::Yes)
    {
        //打开登录窗口
        removeWidget(index);
        Login *login=new Login(this);
        login->setWindowFlag(Qt::Window);
        login->show();
        this->close();
    }
}
void ManagerMainWindow::initUserStyle()
{
    button_user_book_1->setStyleSheet(buttonStyle_unchecked);
    button_user_book_2->setStyleSheet(buttonStyle_unchecked);
    button_user_book_3->setStyleSheet(buttonStyle_unchecked);
    button_user_set_1->setStyleSheet(buttonStyle_unchecked);
    button_user_set_2->setStyleSheet(buttonStyle_unchecked);
}
//管理员模块
void ManagerMainWindow::on_button_admin_book_1_clicked()
{
    removeWidget(index);
    BookManager *BookInfoMana = new BookManager();
    index=ui->stackedWidget->addWidget(BookInfoMana);
    ui->stackedWidget->setCurrentIndex(index);
    initAdminStyle();
    button_admin_book_1->setStyleSheet(buttonStyle_checked);
}
void ManagerMainWindow::on_button_admin_book_2_clicked()
{
    removeWidget(index);
    BookClassifyManager *BookClassMana = new BookClassifyManager();
    index=ui->stackedWidget->addWidget(BookClassMana);
    ui->stackedWidget->setCurrentIndex(index);
    initAdminStyle();
    button_admin_book_2->setStyleSheet(buttonStyle_checked);
}
void ManagerMainWindow::on_button_admin_user_1_clicked()
{
    removeWidget(index);
    readerManager *readermanager=new readerManager();
    index=ui->stackedWidget->addWidget(readermanager);
    ui->stackedWidget->setCurrentIndex(index);
    initAdminStyle();
    button_admin_user_1->setStyleSheet(buttonStyle_checked);
}
void ManagerMainWindow::on_button_admin_sys_1_clicked()
{
    removeWidget(index);
    borrowBookInformation *borrowbookinformation = new borrowBookInformation();
    index=ui->stackedWidget->addWidget(borrowbookinformation);
    ui->stackedWidget->setCurrentIndex(index);
    initAdminStyle();
    button_admin_sys_1->setStyleSheet(buttonStyle_checked);
}
void ManagerMainWindow::on_button_admin_sys_2_clicked()
{
    removeWidget(index);
    returnBook *returnbook = new returnBook();
    index=ui->stackedWidget->addWidget(returnbook);
    ui->stackedWidget->setCurrentIndex(index);
    initAdminStyle();
    button_admin_sys_2->setStyleSheet(buttonStyle_checked);
}
void ManagerMainWindow::initAdminStyle()
{
    button_admin_book_1->setStyleSheet(buttonStyle_unchecked);
    button_admin_book_2->setStyleSheet(buttonStyle_unchecked);
    button_admin_user_1->setStyleSheet(buttonStyle_unchecked);
    button_admin_sys_1->setStyleSheet(buttonStyle_unchecked);
    button_admin_sys_2->setStyleSheet(buttonStyle_unchecked);
}
