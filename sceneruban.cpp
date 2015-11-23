#include "sceneruban.h"

#include "periodetempsgraphicsitem.h"

SceneRuban::SceneRuban(Ruban *ruban)
    : QGraphicsScene()
    , _ruban(ruban)
    , _hauteur(400)
{
    createListePeriodeItems();
}

void SceneRuban::setHauteur(int hauteur)
{
    _hauteur = hauteur;


    // Recalculer les pos et tailles de tous les items
    foreach (QGraphicsItem* i, items()) {
        PeriodeTempsGraphicsItem * item = dynamic_cast<PeriodeTempsGraphicsItem *>(i);
        if (item != 0) {
            PeriodeTemps * periodeTemps = item->periodeTemps();
            qreal yDebut = _ruban->debut().secsTo(periodeTemps->debut()) * _hauteur / _ruban->debut().secsTo(_ruban->fin());
            qreal yFin = _ruban->debut().secsTo(periodeTemps->fin()) * _hauteur / _ruban->debut().secsTo(_ruban->fin());
            //rectItem->setRect(0, yDebut, 100, yFin-yDebut);
            item->setRect(QRectF(0, yDebut, 100, yFin-yDebut));
        }
    }
}

void SceneRuban::createListePeriodeItems()
{
    for(int i = 0; i < _ruban->getNbPeriodeMois(); i++) {
        PeriodeTemps * periodeTemps = _ruban->getPeriodeMois(i);

        PeriodeTempsGraphicsItem * item = new PeriodeTempsGraphicsItem(periodeTemps);
        //_listePeriodeItem.push_back(item);
        addItem(item);
    }
}
