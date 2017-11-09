#ifndef SHIP_H
#define SHIP_H

#include "scene.h"

#include <QKeyEvent>
#include <QGraphicsObject> //A combination of QGraphicsItem and QObject

class Ship : public QGraphicsObject
{
public:

    //Default constructor - positions the ship to the middle of the screen.
    Ship();

    //Updates the ship position
    void updateShip();

    //Reimplementation of the keyPressEvent
    void keyPressEvent(QKeyEvent *);

    //Paint and Hitbox functions for the Ship
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const
        {return QRectF(-20, -25, 25, 36); }

private:

    //Angle of the Ship, used to set it's rotation
    qreal angle;

    //These values take into account the rotation of the ship
    //Which are then used to move the ship to the proper position
    qreal xCoor;
    qreal yCoor;

    //Determines whether the ship's action key(s) have been pressed.
    bool keyCCWPressed;
    bool keyCWPressed;
    bool keyMove;
    bool keyShoot;


};

#endif
