#include "managermainwindow.h"
#include "ui_managermainwindow.h"
#include "bookinformationmanager.h"//引入图书信息管理子窗口
#include "bookclassifymanager.h"//引入图书分类管理子窗口
#include "QPushButton"
#include "QMovie"
#include"QLabel"
ManagerMainWindow::ManagerMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManagerMainWindow)
{
    ui->setupUi(this);
    BookManager *BookInfoMana = new BookManager();
    BookClassifyManager *BookClassMana = new BookClassifyManager();
    page_BookInfoMana=ui->stackedWidget->addWidget(BookInfoMana);
    page_BookClassMana=ui->stackedWidget->addWidget(BookClassMana);
    //topItem add
    QTreeWidgetItem *topItem1=new QTreeWidgetItem();
    topItem1->setText(0,"图书查询&借阅");
    QTreeWidgetItem *topItem2=new QTreeWidgetItem();
    topItem2->setText(0,"系统管理");
    ui->treeWidget->setRootIsDecorated(false);//不显示三角形
    //subitem add
    QTreeWidgetItem *subItem_book_1=new QTreeWidgetItem(topItem1);
    QTreeWidgetItem *subItem_book_2=new QTreeWidgetItem(topItem1);

    QTreeWidgetItem *subItem_sys_1=new QTreeWidgetItem(topItem2);
    QTreeWidgetItem *subItem_sys_2=new QTreeWidgetItem(topItem2);
    QTreeWidgetItem *subItem_sys_3=new QTreeWidgetItem(topItem2);
    QTreeWidgetItem *subItem_sys_4=new QTreeWidgetItem(topItem2);

    //topItem->setIcon(0,QIcon("D:\\favicon.ico"));
    ui->treeWidget->addTopLevelItem(topItem1);
    ui->treeWidget->addTopLevelItem(topItem2);
    //add subfuntion
    QPushButton *button_book_1=new QPushButton("图书信息管理");
    QPushButton *button_book_2=new QPushButton("图书分类管理");

    QPushButton *button_sys_1=new QPushButton("用户管理");
    QPushButton *button_sys_2=new QPushButton("角色管理");
    QPushButton *button_sys_3=new QPushButton("图书管理");
    QPushButton *button_sys_4=new QPushButton("资源管理");

    button_sys_1->setStyleSheet("background-color: rgb(29, 123, 255);"
                            "color: rgb(255, 255, 255);");
    ui->treeWidget->setItemWidget(subItem_book_1,0,button_book_1);
    ui->treeWidget->setItemWidget(subItem_book_2,0,button_book_2);

    ui->treeWidget->setItemWidget(subItem_sys_1,0,button_sys_1);
    ui->treeWidget->setItemWidget(subItem_sys_2,0,button_sys_2);
    ui->treeWidget->setItemWidget(subItem_sys_3,0,button_sys_3);
    ui->treeWidget->setItemWidget(subItem_sys_4,0,button_sys_4);
    //connect signal
    connect(button_book_1,SIGNAL(clicked()),this,SLOT(on_button_book_1_clicked()));
    connect(button_book_2,SIGNAL(clicked()),this,SLOT(on_button_book_2_clicked()));
    //树最顶部名称
    QStringList top;
    top << "功能选择";
    ui->treeWidget->setHeaderLabels(top);
    //expand
    topItem1->setExpanded(true);
    topItem2->setExpanded(true);
    // 显示gif图片
    ui->label_bacgroud->setWindowFlag(Qt::FramelessWindowHint);// 设置无边框
    static QMovie movie(":/images/3.gif");
    ui->label_bacgroud->setMovie(&movie);
    ui->label_bacgroud->setScaledContents(true);
    movie.start();
}

ManagerMainWindow::~ManagerMainWindow()
{
    delete ui;
}

void ManagerMainWindow::on_button_book_1_clicked()
{

    ui->stackedWidget->setCurrentIndex(page_BookInfoMana);

}

void ManagerMainWindow::on_button_book_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(page_BookClassMana);

}

