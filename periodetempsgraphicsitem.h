#ifndef PERIODETEMPSGRAPHICSITEM_H
#define PERIODETEMPSGRAPHICSITEM_H

#include "periodetemps.h"
#include <QGraphicsRectItem>

class PeriodeTempsGraphicsItem : public QGraphicsRectItem
{
public:
    PeriodeTempsGraphicsItem(PeriodeTemps *periodeTemps);

    PeriodeTemps *periodeTemps() const;

private:
    PeriodeTemps * _periodeTemps;
};

#endif // PERIODETEMPSGRAPHICSITEM_H
