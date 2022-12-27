#include "bookinformationmanagermodifydialog.h"
#include "ui_bookinformationmanagermodifydialog.h"
#include <QString>
#include <QVariant>
#include <QSqlRecord>
#include "QMessageBox"

BookInformationManagerModifyDialog::BookInformationManagerModifyDialog(QWidget *parent, QSqlTableModel *_model, QSqlRecord *_record, int *_row) :
    QDialog(parent),
    ui(new Ui::BookInformationManagerModifyDialog),
    model(_model),
    record(_record),
    row(_row)
{
    ui->setupUi(this);
    setWindowTitle("修改");
    QStringList cbList;
    cbList << "马克思主义、列宁主义、毛泽东思想、邓小平理论" << "哲学、宗教" << "社会科学总论" << "政治、法律" << "军事";
    cbList << "经济" << "文化、科学、教育、体育" << "语言、文字" << "文学" << "艺术";
    cbList << "历史、地理" << "自然科学总论" << "数理科学和化学" << "天文学、地球科学" << "生物科学";
    cbList << "医药、卫生" << "农业科学" << "工业技术" << "交通运输" << "航空、航天";
    cbList << "环境科学、劳动保护科学（安全科学）" << "综合性图书";
    ui->BookTypedepcbBox->addItems(cbList);


    ui->BookIDlineEdit->setText(record->value("图书ID").toString());
    ui->BookNUMlineEdit->setText(record->value("图书号").toString());
    ui->BookNamelineEdit->setText(record->value("图书名").toString());
    ui->WriterlineEdit->setText(record->value("作者").toString());
    ui->BookTypedepcbBox->setCurrentText(record->value("图书类型").toString());
    ui->PublisherlineEdit->setText(record->value("出版社").toString());
    ui->PublishTimelineEdit->setText(record->value("出版时间").toString());
    ui->NumberlineEdit->setText(record->value("数量").toString());
}

BookInformationManagerModifyDialog::~BookInformationManagerModifyDialog()
{
    delete ui;
}

void BookInformationManagerModifyDialog::on_buttonBox_accepted()
{
    if(ui->BookNamelineEdit->text().isEmpty() || ui->WriterlineEdit->text().isEmpty() ||
       ui->BookIDlineEdit->text().isEmpty() || ui->BookNUMlineEdit->text().isEmpty() ||
       ui->BookTypedepcbBox->currentText().isEmpty() || ui->NumberlineEdit->text().isEmpty() ||
       ui->PublisherlineEdit->text().isEmpty() || ui->PublishTimelineEdit->text().isEmpty())
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
    QString PublishTime = ui->PublishTimelineEdit->text();

    model->setData(model->index(*row, 0), QVariant(BookID));
    model->setData(model->index(*row, 1), QVariant(BookNum));
    model->setData(model->index(*row, 2), QVariant(BookName));
    model->setData(model->index(*row, 3), QVariant(Writer));
    model->setData(model->index(*row, 4), QVariant(BookType));
    model->setData(model->index(*row, 5), QVariant(Publisher));
    model->setData(model->index(*row, 6), QVariant(PublishTime));
    model->setData(model->index(*row, 7), QVariant(Number));
    model->setData(model->index(*row, 8), QVariant(""));
    model->setData(model->index(*row, 9), QVariant(""));

    model->submitAll();
}

