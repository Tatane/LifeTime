#include "periodetemps.h"

PeriodeTemps::PeriodeTemps()
    : _debut(QDateTime())
    , _fin(QDateTime())
    , _label("")
{

}
QDateTime PeriodeTemps::fin() const
{
    return _fin;
}

QDateTime PeriodeTemps::debut() const
{
    return _debut;
}


