#include "bookclassifymanager.h"
#include "ui_bookclassifymanager.h"
#include "bookinformationmanageradddatadialog.h"
#include "bookinformationmanagermodifydialog.h"
#include "QMessageBox"
#include <QPushButton>
#include <QStyle>
#include <QSqlTableModel>
#include <QString>
#include <QSqlRecord>

BookClassifyManager::BookClassifyManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookClassifyManager)
{
    ui->setupUi(this);
    setWindowTitle("图书分类管理模块");
    setWinStyle();
    //连接数据库
    //database.DBOpen();
    databaseOperate();
}

BookClassifyManager::~BookClassifyManager()
{
    database.DBClose();
    delete ui;
}

void BookClassifyManager::setWinStyle()
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
    ui->Title->setStyleSheet(
                "QLabel{"
                "background-color:#DDDDDD;"
                "}");

    QStringList cbList;
    cbList << "马克思主义、列宁主义、毛泽东思想、邓小平理论" << "哲学、宗教" << "社会科学总论" << "政治、法律" << "军事";
    cbList << "经济" << "文化、科学、教育、体育" << "语言、文字" << "文学" << "艺术";
    cbList << "历史、地理" << "自然科学总论" << "数理科学和化学" << "天文学、地球科学" << "生物科学";
    cbList << "医药、卫生" << "农业科学" << "工业技术" << "交通运输" << "航空、航天";
    cbList << "环境科学、劳动保护科学（安全科学）" << "综合性图书";
    ui->BookTypedepcbBox->addItems(cbList);
}

void BookClassifyManager::databaseOperate()
{

    model = new QSqlTableModel();
    model->setTable("bookinformation");//选择表
    model->setSort(4,Qt::AscendingOrder); //图书类型属性，即第5列，升序排列
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

void BookClassifyManager::on_AddpushButton_clicked()
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


void BookClassifyManager::on_SearchpushButton_clicked()
{
    QString BookType = ui->BookTypedepcbBox->currentText();
    model->setFilter(QObject::tr("图书类型 like '%%1%'").arg(BookType));
    model->setSort(4,Qt::AscendingOrder); //图书类型属性，即第5列，升序排列
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

void BookClassifyManager::on_ModifypushButton_clicked()
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

void BookClassifyManager::on_CanclepushButton_clicked()
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


void BookClassifyManager::on_AllpushButton_clicked()
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

void BookClassifyManager::on_SurepushButton_clicked()
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

void BookClassifyManager::on_DeletepushButton_clicked()
{
    ;
}



