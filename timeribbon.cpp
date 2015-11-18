#include "timeribbon.h"

#include <QPainter>
#include <QEvent>
#include <QGestureEvent>
#include <QGesture>
#include <QLabel>

TimeRibbon::TimeRibbon(QWidget *parent) : QWidget(parent),
    previousScale(1),
    scale(1)
{
    setAttribute(Qt::WA_AcceptTouchEvents);
    grabGesture(Qt::PinchGesture);
    setMinimumHeight(parent->height());

    label1 = new QLabel("Label 1", this);
    label2 = new QLabel("Label 2", this);
    label3 = new QLabel("Label 3", this);
}

void TimeRibbon::dessinerAnnees()
{
    label1->setGeometry(0, 0*scale, 100, 50);
    label2->setGeometry(0, 200*scale, 100, 50);

    //IL FAUT QUE TOUT CE QUE JE VEUX DESSINER DANS LE RIBBON
    //SOIT DES QWIDGET, IL NE FAUT PAS QUE JE LES PAINT EXPLICITEMENT.
    //IL FAUT LAISSER Qt FAIRE LE RENDU, IL S'ARANGERA POUR QUE CA SOIT SMOOTH,
    // ET POUR NE PAS DESSINER CEUX QUI SONT EN DEHORS DU VIEWPORT !!
}

void TimeRibbon::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    label3->setGeometry(0, 350*scale, 100, 50);

    setMinimumHeight(parentWidget()->height() * scale);
    painter.drawText(10, 10, QString::number(scale));
    //painter.drawText(10, height(), "BAS");
    painter.drawLine(0, 0, 50, 0);
    painter.drawLine(0, height()-1, 50, height()-1);

    dessinerAnnees();
}

bool TimeRibbon::event(QEvent * e)
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
                    update();
                }
                    break;
                default:
                    break;
                }
                break;
            }
            default:
                Q_ASSERT_X(false, "TimeRibbon::event", "Gesture type not managed");
            }
        }
    }
    /*
    if (e->type() == QEvent::TouchBegin) {
        int a = 0;
    }
    */
    //e->ignore();
    return QWidget::event(e);;
}


