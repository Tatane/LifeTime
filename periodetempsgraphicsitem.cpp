#include "periodetempsgraphicsitem.h"

#include <QPen>

PeriodeTempsGraphicsItem::PeriodeTempsGraphicsItem(PeriodeTemps *periodeTemps)
    : QGraphicsRectItem()
    , _periodeTemps(periodeTemps)
{
    //setPen(QPen(Qt::red));
    //setBrush(QBrush(Qt::SolidPattern));

    setRect(10, 10, 50, 30);
}
PeriodeTemps *PeriodeTempsGraphicsItem::periodeTemps() const
{
    return _periodeTemps;
}




