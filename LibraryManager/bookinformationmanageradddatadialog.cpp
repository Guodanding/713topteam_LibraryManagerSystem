#include "bookinformationmanageradddatadialog.h"
#include "ui_bookinformationmanageradddatadialog.h"
#include <QString>
#include <QVariant>
#include "QMessageBox"

BookInformationManagerAddDataDialog::BookInformationManagerAddDataDialog(QWidget *parent, QSqlTableModel *_model) :
    QDialog(parent),
    ui(new Ui::BookInformationManagerAddDataDialog),
    model(_model)
{
    ui->setupUi(this);
    setWindowTitle("添加");
    QStringList cbList;
    cbList << "马克思主义、列宁主义、毛泽东思想、邓小平理论" << "哲学、宗教" << "社会科学总论" << "政治、法律" << "军事";
    cbList << "经济" << "文化、科学、教育、体育" << "语言、文字" << "文学" << "艺术";
    cbList << "历史、地理" << "自然科学总论" << "数理科学和化学" << "天文学、地球科学" << "生物科学";
    cbList << "医药、卫生" << "农业科学" << "工业技术" << "交通运输" << "航空、航天";
    cbList << "环境科学、劳动保护科学（安全科学）" << "综合性图书";
    ui->BookTypedepcbBox->addItems(cbList);
}

BookInformationManagerAddDataDialog::~BookInformationManagerAddDataDialog()
{
    delete ui;
}

void BookInformationManagerAddDataDialog::on_buttonBox_accepted()
{
    if(ui->BookNamelineEdit->text().isEmpty() || ui->WriterlineEdit->text().isEmpty() ||
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

    model->submitAll();
}

