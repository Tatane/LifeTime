#ifndef RUBAN_H
#define RUBAN_H

#include <QDateTime>
#include "periodetempsmois.h"

class Ruban
{
public:
    Ruban(QDateTime debut, QDateTime fin);

    int getNbPeriodeMois() const;
    PeriodeTemps * getPeriodeMois(int index) const;

    QDateTime debut() const;
    QDateTime fin() const;

private:
    QDateTime _debut, _fin;
    QList<PeriodeTemps*> listeMois;

    void createListeMois();
};

#endif // RUBAN_H
