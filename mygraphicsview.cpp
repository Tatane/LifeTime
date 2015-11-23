#include "mygraphicsview.h"
#include <QGestureEvent>

#include <QGraphicsItem>
#include <evenementgraphicsitem.h>
#include <QDateTime>
#include <QRectF>

#include "periodetempsgraphicsitem.h"

MyGraphicsView::MyGraphicsView(QWidget * parent)
    : QGraphicsView(parent)
    , previousScale(0)
    , scale(1)
    , ribbonDebut(QDate(2015, 01, 01))
    , ribbonFin(QDate(2015, 12, 31))
{
    grabGesture(Qt::SwipeGesture);
    grabGesture(Qt::PinchGesture);
    grabGesture(Qt::PanGesture);
}



bool MyGraphicsView::event(QEvent * e)
{
    QGestureEvent * gestureEvent = dynamic_cast<QGestureEvent*>(e);
    if (gestureEvent != 0) {

        foreach (QGesture * gesture, gestureEvent->activeGestures()) {
            switch(gesture->gestureType()) {
            case Qt::PinchGesture:
            {
                QPinchGesture * pinchGesture = dynamic_cast<QPinchGesture*>(gesture);
                switch (pinchGesture->state()) {
                case Qt::GestureStarted:
                    previousScale = scale;
                    break;
                case Qt::GestureUpdated:
                case Qt::GestureFinished:
                {
                    qreal computedScale = previousScale * pinchGesture->totalScaleFactor();
                    //if
                    scale = computedScale;
                    //update();
                    emit scaleChanged(scale);
                }
                    break;
                default:
                    break;
                }
                break;
            }
            case Qt::SwipeGesture:
            {
                int c = 0;
            }
            case Qt::PanGesture:
            {
                int d = 0;
            }
            default:
                int b = 0;
                //Q_ASSERT_X(false, "TimeRibbon::event", "Gesture type not managed");
            }
        }
    }
    return QGraphicsView::event(e);
}

void MyGraphicsView::initiateItems()
{
    QList<QGraphicsItem*> listeItems = scene()->items();
    foreach (QGraphicsItem* item, listeItems) {
        EvenementGraphicsItem * rectItem = dynamic_cast<EvenementGraphicsItem *>(item);
        if (rectItem != 0) {
            Evenement * ev = rectItem->evenement();
            qreal yDebut = ribbonDebut.secsTo(ev->debut()) * height() / ribbonDebut.secsTo(ribbonFin);
            qreal yFin = ribbonDebut.secsTo(ev->fin()) * height() / ribbonDebut.secsTo(ribbonFin);
            //rectItem->setRect(0, yDebut, 100, yFin-yDebut);
            rectItem->setInitialRect(QRectF(0, yDebut, 100, yFin-yDebut));
        }
    }
}

/*
void MyGraphicsView::scrollContentsBy(int dx, int dy)
{
    QGraphicsView::scrollContentsBy(0, dy);
}
*/
void MyGraphicsView::scaleChanged(qreal scale)
{/*
    QList<QGraphicsItem*> listeItems = scene()->items();
    foreach (QGraphicsItem* i, listeItems) {
        PeriodeTempsGraphicsItem * item = dynamic_cast<PeriodeTempsGraphicsItem *>(i);
        if (item != 0) {
            QRectF initialRect = item->initialRect();
            //rectItem->setRect(INITIALE_POS_X, INITIALE_POS_Y*scale, INITIALE_WIDTH, INITIALE_HEIGHT*scale);
            QRectF rect;
            rect.setY(initialRect.y() * scale);
            rect.setHeight(initialRect.height() * scale);
        }
    }*/
}
