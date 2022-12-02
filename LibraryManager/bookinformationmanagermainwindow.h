#ifndef BOOKINFORMATIONMANAGERMAINWINDOW_H
#define BOOKINFORMATIONMANAGERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class BookInformationManagerMainWindow;
}

class BookInformationManagerMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookInformationManagerMainWindow(QWidget *parent = nullptr);
    ~BookInformationManagerMainWindow();

private:
    Ui::BookInformationManagerMainWindow *ui;
};

#endif // BOOKINFORMATIONMANAGERMAINWINDOW_H
