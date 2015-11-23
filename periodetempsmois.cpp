#include "periodetempsmois.h"

PeriodeTempsMois::PeriodeTempsMois(int annee, int mois)
    : PeriodeTemps()
{
    int nbJoursDansMois = QDate(annee, mois, 01).daysInMonth();
    _debut = QDateTime(QDate(annee, mois, 01));
    _fin = QDateTime(QDate(annee, mois, nbJoursDansMois));
    _label = QDate(annee, mois, 01).longMonthName(mois);
}

