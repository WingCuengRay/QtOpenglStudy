#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "nehewidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool fullscreen;
    //处理键盘事件
    void keyPressEvent( QKeyEvent *e );
private:
    NeHeWidget *neheWidget ;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
