#include "bookinformationmanageradddatadialog.h"
#include "ui_bookinformationmanageradddatadialog.h"

BookInformationManagerAddDataDialog::BookInformationManagerAddDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookInformationManagerAddDataDialog)
{
    ui->setupUi(this);
    QStringList cbList;
    cbList << "马克思主义、列宁主义、毛泽东思想、邓小平理论" << "哲学、宗教" << "社会科学总论" << "政治、法律" << "军事";
    cbList << "经济" << "文化、科学、教育、体育" << "语言、文字" << "文学" << "艺术";
    cbList << "历史、地理" << "自然科学总论" << "数理科学和化学" << "天文学、地球科学" << "生物科学";
    cbList << "医药、卫生" << "农业科学" << "工业技术" << "交通运输" << "航空、航天";
    cbList << "环境科学、劳动保护科学（安全科学）" << "综合性图书";
    ui->depcbBox->addItems(cbList);
}

BookInformationManagerAddDataDialog::~BookInformationManagerAddDataDialog()
{
    delete ui;
}
