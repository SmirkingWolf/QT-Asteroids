#include "bullet.h"

#include <QPainter>
#include <qmath.h>

//Create bullet at the middle of screen
Bullet::Bullet()
{
    qreal x = (m_Width + 17)/2;
    qreal y = (m_Height + 15)/2;
    setPos(x,y);
}

//Creates a bullet with the specified x/y coordinates and rotation
Bullet::Bullet(qreal x, qreal y, qreal rotation)
{
    setPos( x, y );
    setRotation( rotation );
}

void Bullet::updateBulletCords()
{
    //.00174 is the length of the curve
    xCoor =  0.5 * qSin( 0.0174533 * rotation() );
    yCoor =  0.5 * -qCos( 0.0174533 * rotation()) ;
    setPos( x() + xCoor, y() + yCoor);


}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen((QPen(Qt::white, 2)) );
    painter->drawLine(-8.5, -25, -7, 11);
}
