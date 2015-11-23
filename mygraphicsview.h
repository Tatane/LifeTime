#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QDateTime>

class MyGraphicsView : public QGraphicsView
{
public:
    MyGraphicsView(QWidget * parent);
    void initiateItems();

    // QObject interface
public:
    bool event(QEvent *e);
/*
    // QAbstractScrollArea interface
protected:
    void scrollContentsBy(int dx, int dy);
*/
private:
    qreal previousScale, scale;
    QDateTime ribbonDebut, ribbonFin;



private slots:
    void scaleChanged(qreal scale);


};

#endif // MYGRAPHICSVIEW_H
