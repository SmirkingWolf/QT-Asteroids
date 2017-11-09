#include "scene.h"
#include "ship.h"
#include "globalvars.h"

// Constructor
Scene::Scene() : QGraphicsScene()
{
    //invisible item to provide default top-left anchor to scene
    addLine(0, 0, 0, 1, QPen(Qt::transparent, 1) );

    /*
    //DEBUGGING PURPOSES - CENTER SHIP
    //A line from the corner of the screen (0,0) to (x,y)
    qreal x = m_Width/2;
    qreal y = m_Height/2;
    this->addLine(0, 0, x, y, QPen(Qt::green, 1));
    */

}
