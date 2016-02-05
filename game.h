#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QInputDialog>
#include <QDataStream>
#include <QMediaPlayer>
#include "pie.h"
#include "score.h"
#include "timer.h"
#include "paul.h"
#include "enemy.h"


class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget * parent =0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    //Timer * timer;
    void endGame();
    void displayMainMenu();


public slots:
    void start();
    void intro();
};

#endif // GAME_H
