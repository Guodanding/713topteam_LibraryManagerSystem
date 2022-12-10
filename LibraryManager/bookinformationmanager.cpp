#include "bookinformationmanager.h"
#include "ui_bookinformationmanager.h"
#include "bookinformationmanageradddatadialog.h"
#include "QMessageBox"
#include <QPushButton>
#include <QStyle>
#include <QSqlTableModel>

BookManager::BookManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookManager)
{
    ui->setupUi(this);
    setWindowTitle("图书信息管理模块");
    setWinStyle();
    //连接数据库
    database.DBOpen();
    databaseOperate();
}

BookManager::~BookManager()
{
    database.DBClose();
    delete ui;
}

void BookManager::setWinStyle()
{
    ui->BookInformationtableView->setAlternatingRowColors(true); // 表格数据行隔行变色
    ui->BookInformationtableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单个数据格

    ui->AddpushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#FFA500;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FF8C00;"
                "color:white;"
                "}");
    ui->SearchpushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#ADFF2F;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FFD700;"
                "color:white;"
                "}");
    ui->SurepushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#FF0000;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#8B4513;"
                "color:white;"
                "}");
    /*ui->CanclepushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#8470FF;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FF8C00;"
                "color:white;"
                "}");*/
    ui->DeletepushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#8470FF;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FF8C00;"
                "color:white;"
                "}");
    ui->BookInformationManagerTitle->setStyleSheet(
                "QLabel{"
                "background-color:#DDDDDD;"
                "}");
    ui->BookIDlineEdit->setPlaceholderText("请输入图书ID");
    ui->BookNamelineEdit->setPlaceholderText("请输入图书名");
    ui->WriterNamelineEdit->setPlaceholderText("请输入作者名");
}

void BookManager::databaseOperate()
{

    model = new QSqlTableModel();
    model->setTable("bookinformation");//选择表
    //model->setSort(4,Qt::AscendingOrder); //图书类型属性，即第5列，升序排列
    model->select();//展示所有

    ui->BookInformationtableView->setModel(model);//连接数据库
    ui->BookInformationtableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //只读
    int ColumnWidth[] = {40, 90, 90, 120, 90, 120, 160, 90, 70, 70};//设置列宽
    for(int i = 0; i < model->columnCount(); i++)
        ui->BookInformationtableView->setColumnWidth(i, ColumnWidth[i]);
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *ModifypushButton = new QPushButton("修改🔧");
        QPushButton *CanclepushButton = new QPushButton("删除❌");
        ModifypushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#FFA500;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#FF8C00;"
                    "color:white;"
                    "}");
        CanclepushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#8470FF;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#6A5ACD;"
                    "color:white;"
                    "}");
        ui->BookInformationtableView->setIndexWidget(model->index(i, 8), ModifypushButton);
        ui->BookInformationtableView->setIndexWidget(model->index(i, 9), CanclepushButton);

        // 添加槽
        connect(ModifypushButton, SIGNAL(clicked()), this, SLOT(on_ModifypushButton_clicked()));
        connect(CanclepushButton, SIGNAL(clicked()), this, SLOT(on_CanclepushButton_clicked()));
    }

}

void BookManager::on_AddpushButton_clicked()
{
    BookInformationManagerAddDataDialog BookInformationManagerAddDataDialog(this, this->model);
    BookInformationManagerAddDataDialog.exec();

    model->select();//展示所有
    ui->BookInformationtableView->setModel(model);//连接数据库
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *ModifypushButton = new QPushButton("修改🔧");
        QPushButton *CanclepushButton = new QPushButton("删除❌");
        ModifypushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#FFA500;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#FF8C00;"
                    "color:white;"
                    "}");
        CanclepushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#8470FF;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#6A5ACD;"
                    "color:white;"
                    "}");
        ui->BookInformationtableView->setIndexWidget(model->index(i, 8), ModifypushButton);
        ui->BookInformationtableView->setIndexWidget(model->index(i, 9), CanclepushButton);

        // 添加槽
        connect(ModifypushButton, SIGNAL(clicked()), this, SLOT(on_ModifypushButton_clicked()));
        connect(CanclepushButton, SIGNAL(clicked()), this, SLOT(on_CanclepushButton_clicked()));
    }
}

void BookManager::on_ModifypushButton_clicked()
{
    BookInformationManagerAddDataDialog BookInformationManagerAddDataDialog(this);
    BookInformationManagerAddDataDialog.setWindowTitle("修改");
    BookInformationManagerAddDataDialog.exec();
}

void BookManager::on_CanclepushButton_clicked()
{

    QMessageBox::StandardButton result = QMessageBox::question(this, "删除", "是否删除？");
    if(result == QMessageBox::Yes)
    {
        int row = ui->BookInformationtableView->currentIndex().row();
        model->removeRow(row);

        if(model->submitAll())
            QMessageBox::about(this, "删除", "删除成功！");
        else
            QMessageBox::critical(this, "删除", "删除失败！请重试。");
    }
    else
        return;

    model->select();//展示所有
    ui->BookInformationtableView->setModel(model);//连接数据库
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *ModifypushButton = new QPushButton("修改🔧");
        QPushButton *CanclepushButton = new QPushButton("删除❌");
        ModifypushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#FFA500;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#FF8C00;"
                    "color:white;"
                    "}");
        CanclepushButton->setStyleSheet(
                    "QPushButton{"
                    "font-style:italic;" //斜体
                    "font-weight: bold;" //粗体
                    "font-size: 13px;" //字体大小
                    "font-family: 'Microsoft YaHei UI';"//字体
                    "background-color:#8470FF;"
                    "border-radius:3px;"//设置圆角半径
                    "color:white;"
                    "border-width:71;"//按钮大小设置
                    "}"
                    "QPushButton:hover{"
                    "background-color:#6A5ACD;"
                    "color:white;"
                    "}");
        ui->BookInformationtableView->setIndexWidget(model->index(i, 8), ModifypushButton);
        ui->BookInformationtableView->setIndexWidget(model->index(i, 9), CanclepushButton);

        // 添加槽
        connect(ModifypushButton, SIGNAL(clicked()), this, SLOT(on_ModifypushButton_clicked()));
        connect(CanclepushButton, SIGNAL(clicked()), this, SLOT(on_CanclepushButton_clicked()));
    }

}

void BookManager::on_SurepushButton_clicked()
{
    QMessageBox::StandardButton result = QMessageBox::question(this, "确认", "是否确认？");
    if(result == QMessageBox::Yes)
    {
        if(model->submitAll())
            QMessageBox::about(this, "确认", "确认成功！");
        else
            QMessageBox::critical(this, "确认", "确认失败！请重试。");
    }
    else;
}

void BookManager::on_DeletepushButton_clicked()
{
    this->~BookManager();
}

