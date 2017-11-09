#include "mainwindow.h"
#include "scene.h"
#include "ship.h"
#include "asteroid.h"
#include "globalvars.h"
#include "bullet.h"

#include <QMenuBar>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow() : QMainWindow()
{

    //Create the Menu's and it's actions
    QMenu *start = menuBar()->addMenu(tr("File"));

    QAction *open = new QAction(tr("Start Game"), this );
    open->setShortcut(QKeySequence::Open);
    connect(open, SIGNAL(triggered()), this, SLOT(gameOpen()));

    QAction *closed = new QAction(tr("Exit Game"), this);
    closed->setShortcut(QKeySequence::Close);
    connect(closed, SIGNAL(triggered()), this, SLOT(gameClose()));

    start->addAction(open);
    start->addAction(closed);

    //Scene
    m_scene = new Scene();
    m_view = new QGraphicsView(m_scene);

    //Adding various properties to the view
    m_view->setRenderHint(QPainter::Antialiasing, true);
    m_view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    m_view->setFrameStyle(0);

    //For now create a fixed window of size 1024 x 768
    m_view->setFixedWidth(m_Width);
    m_view->setFixedHeight(m_Height);
    m_view->setSceneRect(0,0,m_Width,m_Height);

    //Centralize the view area.
    setCentralWidget(m_view);

    gameStarted = false;

}

//Start Game - modifies the view and scene properties
//Adds the player into the middle of the screen aswell
void MainWindow::gameOpen()
{

    if (!gameStarted){
        gameStarted = true;

        // Set background of the scene to black
        m_view->setBackgroundBrush(Qt::black);

        // Create the player and add him to the scene
        player = new Ship();
        m_view->scene()->addItem(player);

        // Create an Asteroid and add to scene
        enemy = new Asteroid();
        m_view->scene()->addItem(enemy);


        //In order for player object to recieve events such as keyboard events
        //The object must be focusable, and should be set to be the focus
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();

        //Create timer and have it's parent object be set to the MainWindow object
        //The Timer object is connected to the MainWindow object
        //Every X milliseconds, it timeouts and that sends a signal to the MainWindow
        //Object, which then proceeds to call 'updateGame()'
        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateGame()));
        timer->start(33.33);

    }

}

//Exit Functon - closes program.
void MainWindow::gameClose()
{
    this->close();

}

//This function is called every 33.33ms (30FPS)
//It is used to update objects properties, such as
//Rotation, velocity, hitpoints, etc.
//Every object that is updated in this function is rendered at 30FPS
void MainWindow::updateGame()
{


    player->updateShip();
    enemy->updateAsteroidCords();

}
