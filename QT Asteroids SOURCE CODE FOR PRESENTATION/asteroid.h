#ifndef ASTEROID_H
#define ASTEROID_H

#include "globalvars.h"


#include <QGraphicsItem>
#include <QtCore/qmath.h>


class Asteroid : public QGraphicsItem
{
public:
    Asteroid();

    Asteroid(qreal, qreal);

   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

   void updateAsteroidCords();

   QRectF boundingRect() const
   { return QRectF(-25, -25, 35, 35); }

private:

   qreal xCoor;
   qreal yCoor;

};

#endif // ASTEROID_H
