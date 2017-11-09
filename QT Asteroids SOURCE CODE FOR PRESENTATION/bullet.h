#ifndef BULLET_H
#define BULLET_H

#include "globalvars.h"

#include <QtCore/qmath.h>
#include <QGraphicsObject>

class Bullet : public QGraphicsObject
{
    Q_OBJECT
public:

   Bullet();

   Bullet(qreal, qreal, qreal);

   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

   QRectF boundingRect() const
   { return QRectF(-25, -25, 35, 35); }

public slots:
   void updateBulletCords();

private:
   qreal xCoor;
   qreal yCoor;

};

#endif // BULLET_H
