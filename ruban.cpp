#include "ruban.h"

Ruban::Ruban(QDateTime debut, QDateTime fin)
    : _debut(debut)
    , _fin(fin)
{
    createListeMois();
}

int Ruban::getNbPeriodeMois() const
{
    return listeMois.size();
}

PeriodeTemps *Ruban::getPeriodeMois(int index) const
{
    return listeMois.at(index);
}

QDateTime Ruban::debut() const
{
    return _debut;
}

QDateTime Ruban::fin() const
{
    return _fin;
}

void Ruban::createListeMois()
{
    QDate dateDebut = _debut.date();
    QDate dateFin = _fin.date();

    int dateDebutMois = dateDebut.month();
    int dateDebutAnnee = dateDebut.year();

    for(int a=dateDebut.year(); a<=dateFin.year(); ++a){
        int mStart = (a==dateDebut.year())?dateDebut.month():1;
        int mEnd = (a==dateFin.year())?dateFin.month():12;
        for(int m=mStart; m<=mEnd; ++m) {
            PeriodeTempsMois * mois = new PeriodeTempsMois(a, m);
            listeMois.push_back(mois);
        }
    }
}

