#include "ship.h"
#include "globalvars.h"
#include "bullet.h"

#include <QPainter>
#include <QDebug>
#include <QtCore/qmath.h>
#include <QTimer>


Ship::Ship()
{
    keyCCWPressed = false;
    keyCWPressed = false;
    keyMove = false;
    keyShoot = false;
    angle = 0;
    xCoor = 10 * qSin( 0.0174533 * rotation() );
    yCoor = 10 * -qCos( 0.0174533 * rotation() );

    qreal x = (m_Width + 17)/2;
    qreal y = (m_Height + 15)/2;
    setPos(x,y);


}

//Updates various properties of the ship such as:
//rotaton, new position, bullet creation
void Ship::updateShip()
{
    if(keyMove)
    {
    setPos( x() + xCoor, y() + yCoor);
    keyMove = false;
    }
    else if(keyCCWPressed)
    {
        setRotation( angle -=5 );
        keyCCWPressed = false;
        xCoor =  10 * qSin( 0.0174533 * rotation() );
        yCoor =  10 * -qCos( 0.0174533 * rotation() );
    }

    else if(keyCWPressed)
    {
        setRotation( angle += 5);
        keyCWPressed = false;
        xCoor =  10 * qSin( 0.0174533 * rotation() );
        yCoor =  10 * -qCos( 0.0174533 * rotation() );
    }
   else if(keyShoot)
    {
        //If Shoot key was presed, create a bullet object with the ships position
        //and rotation in mind. Then add to scene
        Bullet *newBullet = new Bullet();
        scene()->addItem(newBullet);
        newBullet->setPos( this->x(), this->y() );
        newBullet->setRotation(this->rotation());

        QTimer *temp = new QTimer(scene());
        connect(temp, SIGNAL(timeout()), newBullet, SLOT( updateBulletCords() ) );
        temp->start(33.33);

        keyShoot = false;
    }
    else{}

}

// Ship movement keys
// Up key moves the ship forwards, left and right keys turn the ship by -/+ 5 degrees respectively
void Ship::keyPressEvent(QKeyEvent *event)
{
    //Set the origin point to center of the ship
    setTransformOriginPoint(-7.5, -7);

    switch ( event->key() ){
       case Qt::Key_Up:
           keyMove = true;
           break;
       case Qt::Key_Left:
           keyCCWPressed = true;
           break;
       case Qt::Key_Right:
            keyCWPressed = true;
           break;
       case Qt::Key_W:
            keyShoot = true;
            break;
       default:
           //else do nothing - no reaction
           break;
    }

}

//Draws the ship by creating 3 lines that all have connecting endpoints
void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::red, 1));

    /*
    //DEBUGGING PURPOSES - boundingRectF BOUNDS
    //This is a visualization of the boundingRectF (AKA Hitbox)
    //rect = x,y, width, height
    painter->drawRect(-20, -25, 25, 36);
    */

    //This is the ship - Triangle Shape
    painter->setPen(QPen(Qt::blue, 1));
    //Right Side
    painter->drawLine(-7.5, -25, 5, 11);
    //Bottom
    painter->drawLine(-20, 11, 5, 11);
    //Left Side
    painter->drawLine(-7.5, -25, -20, 11);

     /*
    //DEBUGGING PURPOSES - CENTER OF THE SHIP
    //(-8.5, -7) is roughly the center of the triangle
    painter->setPen(QPen(Qt::red, 1));
    painter->drawPoint(-7.5, -7);
    */

}

