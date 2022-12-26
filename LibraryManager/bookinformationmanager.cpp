#include "bookinformationmanager.h"
#include "ui_bookinformationmanager.h"
#include "bookinformationmanageradddatadialog.h"
#include "bookinformationmanagermodifydialog.h"
#include "QMessageBox"
#include <QPushButton>
#include <QStyle>
#include <QSqlTableModel>
#include <QString>
#include <QSqlRecord>
#include <QDebug>

BookManager::BookManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookManager)
{
    ui->setupUi(this);
    setWindowTitle("图书信息管理模块");
    setWinStyle();
    //连接数据库
    //database.DBOpen();
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
                "background-color:#FFD700;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#DAA520;"
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
    ui->AllpushButton->setStyleSheet(
                "QPushButton{"
                "background-color:#87CEFA;"
                "border-radius:3px;"//设置圆角半径
                "color:white;"
                "}"
                "QPushButton:hover{"
                "background-color:#1E90FF;"
                "color:white;"
                "}");
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
    int ColumnWidth[] = { 70, 70, 120, 90, 160, 120, 110, 60, 70, 70};//设置列宽
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

    model->setFilter("");
    model->select();//展示所有
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
    QSqlRecord *record = new QSqlRecord(model->record(ui->BookInformationtableView->currentIndex().row()));
    int r = ui->BookInformationtableView->currentIndex().row();
    int *row = &r;
    BookInformationManagerModifyDialog BookInformationManagerModifyDataDialog(this, model, record, row);
    BookInformationManagerModifyDataDialog.exec();

    model->select();

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

void BookManager::on_CanclepushButton_clicked()
{

    QSqlTableModel *tm = new QSqlTableModel();
    tm->setTable("BorrowInfo");//选择表

    int row = ui->BookInformationtableView->currentIndex().row();
    QString BookName = model->record(row).value("图书名").toString();

    tm->setFilter(QObject::tr("BookTitle = '%1'").arg(BookName));
    tm->select();

    if(tm->rowCount() == 0)
    {
        QMessageBox::StandardButton result = QMessageBox::question(this, "删除", "是否删除？");
        if(result == QMessageBox::Yes)
        {
            model->removeRow(row);

            if(model->submitAll())
                QMessageBox::about(this, "删除", "删除成功！");
            else
                QMessageBox::critical(this, "删除", "删除失败！请重试。");
        }
        else
            return;
    }
    else
        QMessageBox::warning(this, "警告", "已有读者借阅此书，无法删除！");

    model->select();//展示所有
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

void BookManager::on_SearchpushButton_clicked()
{
   QString BookID = ui->BookIDlineEdit->text();
   QString BookName = ui->BookNamelineEdit->text();
   QString Writer = ui->WriterNamelineEdit->text();

   if(BookID.isEmpty() && BookName.isEmpty() && Writer.isEmpty())
   {
       QMessageBox::StandardButton result = QMessageBox::warning(this, "错误", "请输入查询信息！");
       if(result == QMessageBox::Ok)
           return;
   }
   else
   {
       if(!BookID.isEmpty())
            model->setFilter(QObject::tr("图书ID like '%1%'").arg(BookID)); //根据ID进行筛选
       if(!BookName.isEmpty())
            model->setFilter(QObject::tr("图书名 like '%1%'").arg(BookName)); //根据图书名进行筛选
       if(!Writer.isEmpty())
            model->setFilter(QObject::tr("作者 like '%1%'").arg(Writer)); //根据姓名进行筛选

       model->select();//展示所有
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
}

void BookManager::on_AllpushButton_clicked()
{
    model->setFilter("");
    model->select();//展示所有
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

/*if(ui->BookNamelineEdit->text().isEmpty() || ui->WriterlineEdit->text().isEmpty() ||
   ui->BookIDlineEdit->text().isEmpty() || ui->BookNUMlineEdit->text().isEmpty() ||
   ui->BookTypedepcbBox->currentText().isEmpty() || ui->NumberlineEdit->text().isEmpty() ||
   ui->PublisherlineEdit->text().isEmpty())
{
    QMessageBox::StandardButton result = QMessageBox::warning(this, "错误", "请输入完整信息！");
    if(result == QMessageBox::Ok)
        return;
}

QString BookName = ui->BookNamelineEdit->text();
QString Writer = ui->WriterlineEdit->text();
QString BookID = ui->BookIDlineEdit->text();
QString BookNum = ui->BookNUMlineEdit->text();
QString BookType = ui->BookTypedepcbBox->currentText();
QString Number = ui->NumberlineEdit->text();
QString Publisher = ui->PublisherlineEdit->text();

model->insertRows(model->rowCount(), 1);
model->setData(model->index(model->rowCount() - 1, 0), QVariant(model->rowCount()));
model->setData(model->index(model->rowCount() - 1, 1), QVariant(BookID));
model->setData(model->index(model->rowCount() - 1, 2), QVariant(BookNum));
model->setData(model->index(model->rowCount() - 1, 3), QVariant(BookName));
model->setData(model->index(model->rowCount() - 1, 4), QVariant(Writer));
model->setData(model->index(model->rowCount() - 1, 5), QVariant(BookType));
model->setData(model->index(model->rowCount() - 1, 6), QVariant(Publisher));
model->setData(model->index(model->rowCount() - 1, 7), QVariant(Number));
model->setData(model->index(model->rowCount() - 1, 8), QVariant(""));
model->setData(model->index(model->rowCount() - 1, 9), QVariant(""));

model->submitAll();*/

void BookManager::on_DeletepushButton_clicked()
{
    ;
}


