#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "timeribbon.h"
#include <qscroller.h>
#include <QPinchGesture>
#include "mygraphicsview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timeRibbon(0),
    scene(0),
    _sceneRuban(0)
{
    ui->setupUi(this);
    timeRibbon = new TimeRibbon(ui->scrollArea);
    timeRibbon->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //timeRibbon->setMinimumHeight(600);
    //timeRibbon->setGeometry(0,0,100, 300);

    ui->scrollArea->setWidget(timeRibbon);
    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture); // Permet au ScrollArea de gérer les Touch et l'inertie.

    //********************************

    view = new MyGraphicsView(ui->centralWidget);
    view->setGeometry(10, 10, 200, 400);
/*
    scene = new QGraphicsScene(this);
    //scene->setSceneRect(0, 0, 10, 500);
    view->setScene(scene);
    graphicsRectItem1 = scene->addRect(0, 0, view->viewport()->contentsRect().width()+10, 50, QPen(), QBrush(Qt::darkRed)); // TODO Mieux calculer la largeur du rectangle, pour qu'il fit parfaitement.
    graphicsRectItem2 = scene->addRect(20, 390, 50, 50, QPen(), QBrush(Qt::darkRed)); // TODO Mieux calculer la largeur du rectangle, pour qu'il fit parfaitement.
    scene->addItem(graphicsItem1);

    view->initiateItems();

    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
*/
    QScroller::grabGesture(view, QScroller::LeftMouseButtonGesture); // Permet au view de gérer les Touch et l'inertie.
    //view->viewport()->grabGesture(Qt::SwipeGesture);

    _ruban = new Ruban(QDateTime(QDate(2014, 9, 01)), QDateTime(QDate(2015, 03, 31)));
    _sceneRuban = new SceneRuban(_ruban);

    view->setScene(_sceneRuban);
    _sceneRuban->setHauteur(view->height());

    connect(view, SIGNAL(sceneHeightChanged(int)), _sceneRuban, SLOT(setHauteur(int)));

}

MainWindow::~MainWindow()
{
    if (timeRibbon != 0) {
        delete timeRibbon;
        timeRibbon = 0;
    }

    delete ui;
}
