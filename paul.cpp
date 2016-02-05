#include <stdlib.h>
#include "game.h"
#include "paul.h"
#include "global.h"
#include <typeinfo>
extern Game * game;
Paul::Paul(): QObject(), QGraphicsPixmapItem()
{
    setScale(.5);
    setPos(-530, 471);
    setPixmap(QPixmap(":/images/paul.png"));

    QTimer *paultimer = new QTimer(this);
    connect(paultimer,SIGNAL(timeout()),this, SLOT(move()));

    paultimer->start(50);

}

void Paul::move()
{
        //bool gameOver;

        QList<QGraphicsItem *> colliding_items = collidingItems();

        for (int i =0, n=colliding_items.size(); i<n; i++)
        {
            if (typeid(*(colliding_items[i])) == typeid(Player))
            {



                //scene()->removeItem(colliding_items[i]);
                //QThread::msleep(100);
                hits ++;
                if (hits%5 == 1)
                {
                    game->score->decrease(1);
                    if (hits%15 ==1)
                        {
                        QMediaPlayer *nom = new QMediaPlayer();
                        nom->setMedia(QUrl("qrc:/sounds/whatdoing.wav"));
                        nom->play();
                        }
                }

                //gameOver = true;
               //return;
            }
        }

        /*if (gameOver)
            game->endGame();*/



    setPos(x()+1, y());

}
