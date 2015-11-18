#ifndef TIMERIBBON_H
#define TIMERIBBON_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class TimeRibbon : public QWidget
{
    Q_OBJECT
public:
    explicit TimeRibbon(QWidget *parent = 0);

signals:

public slots:

private:
    qreal previousScale;
    qreal scale;
    void dessinerAnnees();
    QLabel * label1, * label2, *label3;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);

    // QObject interface
public:
    bool event(QEvent * e);
};

#endif // TIMERIBBON_H
