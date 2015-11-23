#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "timeribbon.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "mygraphicsview.h"

#include "ruban.h"
#include "sceneruban.h"

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
    QGraphicsScene * scene;

    QGraphicsRectItem * graphicsRectItem1, * graphicsRectItem2;
    MyGraphicsView * view;

    Ruban * _ruban;
    SceneRuban * _sceneRuban;

};

#endif // MAINWINDOW_H
