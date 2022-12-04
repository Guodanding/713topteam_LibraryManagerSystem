#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include <QWidget>

namespace Ui {
class BookManager;
}

class BookManager : public QWidget
{
    Q_OBJECT

public:
    explicit BookManager(QWidget *parent = nullptr);
    ~BookManager();
    void setWinStyle();

private:
    Ui::BookManager *ui;
};

#endif // BOOKMANAGER_H
