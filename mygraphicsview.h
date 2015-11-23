#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QDateTime>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:

    MyGraphicsView(QWidget * parent);

    // QObject interface
public:
    bool event(QEvent *e);
/*
    // QAbstractScrollArea interface
protected:
    void scrollContentsBy(int dx, int dy);
*/

signals:
    void sceneHeightChanged(int hauteur);

private:
    qreal previousScale, scale;
    QDateTime ribbonDebut, ribbonFin;
    int previousSceneHeight;


private slots:
    void scaleChanged(qreal scale);

};

#endif // MYGRAPHICSVIEW_H
