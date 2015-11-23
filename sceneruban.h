#ifndef SCENERUBAN_H
#define SCENERUBAN_H

#include <QGraphicsScene>
#include "ruban.h"
#include "periodetempsgraphicsitem.h"

class SceneRuban : public QGraphicsScene
{
    Q_OBJECT
public:
    SceneRuban(Ruban * ruban);

private:
    Ruban * _ruban;
    //QList<PeriodeTempsGraphicsItem*> _listePeriodeItem;
    int _hauteur; // en pixels

    void createListePeriodeItems();

public slots:
    void setHauteur(int hauteur);
};

#endif // SCENERUBAN_H
