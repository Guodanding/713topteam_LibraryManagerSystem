#include "book.h"
#include "ui_book.h"
#include "bookclassifymanager.h"
#include "ui_bookclassifymanager.h"
#include <QWidget>

Book::Book(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Book)
{
    ui->setupUi(this);
}

Book::~Book()
{
    delete ui;
}

void Book::on_pushButton_clicked()
{
    BookClassifyManager BookClassify = new BookClassifyManager();
    QWidget *test = BookClassify.
    ui->horizontalLayout->addWidget(BookClassify);
    //BookClassify->show();
}

