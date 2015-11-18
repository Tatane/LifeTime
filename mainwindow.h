#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "timeribbon.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TimeRibbon * timeRibbon;
};

#endif // MAINWINDOW_H
