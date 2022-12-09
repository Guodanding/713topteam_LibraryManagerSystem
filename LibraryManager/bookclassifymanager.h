#ifndef BOOKCLASSIFYMANAGER_H
#define BOOKCLASSIFYMANAGER_H

#include <QWidget>

namespace Ui {
class BookClassifyManager;
}

class BookClassifyManager : public QWidget
{
    Q_OBJECT

public:
    explicit BookClassifyManager(QWidget *parent = nullptr);
    ~BookClassifyManager();
    void setWinStyle();

private slots:
    void on_AddpushButton_clicked();

private:
    Ui::BookClassifyManager *ui;
};

#endif // BOOKCLASSIFYMANAGER_H
