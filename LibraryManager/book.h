#ifndef BOOK_H
#define BOOK_H

#include <QMainWindow>

namespace Ui {
class Book;
}

class Book : public QMainWindow
{
    Q_OBJECT

public:
    explicit Book(QWidget *parent = nullptr);
    ~Book();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Book *ui;
};

#endif // BOOK_H
