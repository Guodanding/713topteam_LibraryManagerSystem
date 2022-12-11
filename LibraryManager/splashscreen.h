#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QWidget>
#include <QSplashScreen>
#include <QMovie>
#include <QProgressBar>

namespace Ui {
class SplashScreen;
}

class SplashScreen : public QSplashScreen//继承QSplashScreen
{
    Q_OBJECT

public:
    explicit SplashScreen(QPixmap pixmap, QWidget *parent=0);
    void setRange(int min,int max);
    void sleep(int ms);

public slots:
    void updateNum(int n);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::SplashScreen *ui;
    QProgressBar *progressBar;
};

#endif // SPLASHSCREEN_H
