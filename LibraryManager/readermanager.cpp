#include "readermanager.h"
#include "ui_readermanager.h"
#include "readerinformationmanageradddatadialog.h"
#include "readerinformationmanagermodifydialog.h"
#include <QStyle>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QString>
#include <QSqlRecord>

readerManager::readerManager(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::readerManager)
{
    ui->setupUi(this);
    setWindowTitle("读者信息管理模块");
    setWinStyle();
}

readerManager::~readerManager()
{
    delete ui;
}

void readerManager::setWinStyle()
{
    ui->readerInformationtableView->setAlternatingRowColors(true); // 表格数据行隔行变色
    ui->readerInformationtableView->setSelectionMode(QAbstractItemView::SingleSelection); // 单个数据格
    ui->AddpushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#00FF7F;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#00FF7F;"
                "color:white;"
                "}");
    ui->modifypushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#7B68EE;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#7B68EE;"
                "color:white;"
                "}");
    ui->deletepushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#FF3030;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#FF3030;"
                "color:white;"
                "}");
    ui->readerSearchLineEdit->setPlaceholderText("搜索用户名");
}

void readerManager::databaseOperate()
{

    model = new QSqlTableModel();
    model->setTable("readerinformation");//选择表
    //model->setSort(4,Qt::AscendingOrder); //图书类型属性，即第5列，升序排列
    model->select();//展示所有

    ui->readerInformationtableView->setModel(model);//连接数据库
    ui->readerInformationtableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //只读
    int ColumnWidth[] = {50, 50, 50, 50, 50, 50, 50, 50};//设置列宽
    for(int i = 0; i < model->columnCount(); i++)
        ui->readerInformationtableView->setColumnWidth(i, ColumnWidth[i]);
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *modifypushButton = new QPushButton("修改🔧");
        QPushButton *deletepushButton = new QPushButton("删除❌");
        modifypushButton->setStyleSheet(
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
        deletepushButton->setStyleSheet(
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
        ui->readerInformationtableView->setIndexWidget(model->index(i, 8), modifypushButton);
        ui->readerInformationtableView->setIndexWidget(model->index(i, 9), deletepushButton);

        // 添加槽
        connect(modifypushButton, SIGNAL(clicked()), this, SLOT(on_modifypushButton_clicked()));
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }

}

void readerManager::on_addpushButton_clicked()
{
    readerInformationManagerAdddatadialog readerinformationManagerAdddatadialog(this,this->model);
    readerinformationManagerAdddatadialog.exec();

    model->setFilter("");
    model->select();//展示所有
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *ModifypushButton = new QPushButton("修改🔧");
        QPushButton *CancelpushButton = new QPushButton("删除❌");
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
                    "background-color:#7B68EE;"
                    "color:white;"
                    "}");
        CancelpushButton->setStyleSheet(
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
        ui->readerInformationtableView->setIndexWidget(model->index(i, 8), ModifypushButton);
        ui->readerInformationtableView->setIndexWidget(model->index(i, 9), CancelpushButton);

        // 添加槽
        connect(ModifypushButton, SIGNAL(clicked()), this, SLOT(on_ModifypushButton_clicked()));
        connect(CancelpushButton, SIGNAL(clicked()), this, SLOT(on_CancelpushButton_clicked()));
    }
}

void readerManager::on_deletepushButton_clicked()
{

    QMessageBox::StandardButton result = QMessageBox::question(this, "删除", "是否删除？");
    if(result == QMessageBox::Yes)
    {
        int row = ui->readerInformationtableView->currentIndex().row();
        model->removeRow(row);

        if(model->submitAll())
            QMessageBox::about(this, "删除", "删除成功！");
        else
            QMessageBox::critical(this, "删除", "删除失败！请重试。");
    }
    else
        return;

    model->select();//展示所有
    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *modifypushButton = new QPushButton("修改🔧");
        QPushButton *deletepushButton = new QPushButton("删除❌");
        modifypushButton->setStyleSheet(
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
                    "background-color:#7B68EE;"
                    "color:white;"
                    "}");
        deletepushButton->setStyleSheet(
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
                    "background-color:#FF3030;"
                    "color:white;"
                    "}");
        ui->readerInformationtableView->setIndexWidget(model->index(i, 8), modifypushButton);
        ui->readerInformationtableView->setIndexWidget(model->index(i, 9), deletepushButton);

        // 添加槽
        connect(modifypushButton, SIGNAL(clicked()), this, SLOT(on_modifypushButton_clicked()));
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }

}

void readerManager::on_modifypushButton_clicked()
{
    QSqlRecord *record = new QSqlRecord(model->record(ui->readerInformationtableView->currentIndex().row()));
    int r = ui->readerInformationtableView->currentIndex().row();
    int *row = &r;
    readerInformationManagerModifydialog readerInformationManagerModifyDialog(this, model, record, row);
    readerInformationManagerModifyDialog.exec();

    for(int i = 0; i < model->rowCount(); i++)//设置按钮
    {
        QPushButton *ModifypushButton = new QPushButton("修改🔧");
        QPushButton *deletepushButton = new QPushButton("删除❌");
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
        deletepushButton->setStyleSheet(
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
        ui->readerInformationtableView->setIndexWidget(model->index(i, 8), ModifypushButton);
        ui->readerInformationtableView->setIndexWidget(model->index(i, 9), deletepushButton);

        // 添加槽
        connect(ModifypushButton, SIGNAL(clicked()), this, SLOT(on_ModifypushButton_clicked()));
        connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
    }
}

void readerManager::on_searchpushButton_clicked()
{
   QString username = ui->readerSearchLineEdit->text();

   if(username.isEmpty())
   {
       QMessageBox::StandardButton result = QMessageBox::warning(this, "错误", "请输入查询信息！");
       if(result == QMessageBox::Ok)
           return;
   }
   else
   {
//       if(!BookID.isEmpty())
//            model->setFilter(QObject::tr("图书ID = '%1'").arg(BookID)); //根据ID进行筛选
//       if(!BookName.isEmpty())
//            model->setFilter(QObject::tr("图书名 = '%1'").arg(BookName)); //根据图书名进行筛选
//       if(!Writer.isEmpty())
//            model->setFilter(QObject::tr("作者 = '%1'").arg(Writer)); //根据姓名进行筛选

       model->select();//展示所有
       for(int i = 0; i < model->rowCount(); i++)//设置按钮
       {
           QPushButton *modifypushButton = new QPushButton("修改🔧");
           QPushButton *deletepushButton = new QPushButton("删除❌");
           modifypushButton->setStyleSheet(
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
                       "background-color:#7B68EE;"
                       "color:white;"
                       "}");
           deletepushButton->setStyleSheet(
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
                       "background-color:#FF3030;"
                       "color:white;"
                       "}");
           ui->readerInformationtableView->setIndexWidget(model->index(i, 8), modifypushButton);
           ui->readerInformationtableView->setIndexWidget(model->index(i, 9), deletepushButton);

           // 添加槽
           connect(modifypushButton, SIGNAL(clicked()), this, SLOT(on_ModifypushButton_clicked()));
           connect(deletepushButton, SIGNAL(clicked()), this, SLOT(on_deletepushButton_clicked()));
       }
   }
}

void readerManager::on_SurepushButton_clicked()
{
    QMessageBox::StandardButton result = QMessageBox::question(this, "确认", "是否确认？");
    if(result == QMessageBox::Yes)
    {
        if(model->submitAll())
            QMessageBox::about(this, "确认", "确认成功！");
        else
            QMessageBox::critical(this, "确认", "确认失败！请重试。");
    }
}



