#ifndef PERIODETEMPS_H
#define PERIODETEMPS_H

#include <QDateTime>

class PeriodeTemps
{
public:

    QDateTime debut() const;
    QDateTime fin() const;

protected:
    PeriodeTemps();
    QDateTime _debut, _fin;
    QString _label;

};

#endif // PERIODETEMPS_H
