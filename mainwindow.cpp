#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "timeribbon.h"
#include <qscroller.h>
#include <QPinchGesture>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timeRibbon(0)
{
    ui->setupUi(this);
    timeRibbon = new TimeRibbon(ui->scrollArea);
    timeRibbon->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    //timeRibbon->setMinimumHeight(600);
    //timeRibbon->setGeometry(0,0,100, 300);

    ui->scrollArea->setWidget(timeRibbon);
    QScroller::grabGesture(ui->scrollArea, QScroller::LeftMouseButtonGesture); // Permet au ScrollArea de gérer les Touch et l'inertie.
}

MainWindow::~MainWindow()
{
    if (timeRibbon != 0) {
        delete timeRibbon;
        timeRibbon = 0;
    }

    delete ui;
}
