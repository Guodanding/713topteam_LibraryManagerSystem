#ifndef BOOKMANAGERMAINWINDOW_H
#define BOOKMANAGERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class BookManagerMainWindow;
}

class BookManagerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookManagerMainWindow(QWidget *parent = nullptr);
    ~BookManagerMainWindow();

private:
    Ui::BookManagerMainWindow *ui;
};

#endif // BOOKMANAGERMAINWINDOW_H
