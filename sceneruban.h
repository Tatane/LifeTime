#ifndef SCENERUBAN_H
#define SCENERUBAN_H

#include <QGraphicsScene>
#include "ruban.h"
#include "periodetempsgraphicsitem.h"

class SceneRuban : public QGraphicsScene
{
public:
    SceneRuban(Ruban * ruban);

    void setHauteur(int hauteur);

private:
    Ruban * _ruban;
    //QList<PeriodeTempsGraphicsItem*> _listePeriodeItem;
    int _hauteur; // en pixels

    void createListePeriodeItems();
};

#endif // SCENERUBAN_H
