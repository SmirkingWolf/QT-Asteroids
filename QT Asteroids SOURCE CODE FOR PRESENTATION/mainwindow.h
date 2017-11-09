#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ship.h"
#include "asteroid.h"
#include "bullet.h"

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QGraphicsView>

//Forward declaration
class Scene;

//Class MainWindow derived from QMainWindow
class MainWindow : public QMainWindow
{
    //Needed for signals and slots for use with menu actions.
    Q_OBJECT

public:

    //Constructor
    MainWindow();

private slots:

    //Functions which execute when Menu actions are clicked
    void gameOpen();
    void gameClose();

    //Updates the game every X seconds, where X is milliseconds
    void updateGame();

private:

    //Scene and QGraphicsView pointer variables
    Scene *m_scene;
    QGraphicsView *m_view;

    //Create pointer variables to game objects
    Ship *player;
    Asteroid *enemy;

    //Check if the game has started.
    bool gameStarted;


};

#endif //MAINWINDOW_H
