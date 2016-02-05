#include "enemy.h"
#include "player.h"
#include <QTimer>

#include <QList>
#include <stdlib.h>
#include "game.h"
#include <typeinfo>
extern Game * game;
Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{
    type = 0;
    int random_number = rand() % 924;
    setPos(random_number, 0);
    setPixmap(QPixmap(":/images/fish.png"));

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);

}

Enemy::Enemy(int i): QObject(), QGraphicsPixmapItem()
{
    type =1;
    int random_number = rand() % 924;
    setPos(random_number, 0);
    setPixmap(QPixmap(":/images/anvil.png"));

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);

}



void Enemy::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i =0, n=colliding_items.size(); i<n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {

            QMediaPlayer *effect = new QMediaPlayer();
            if (this->type == 0)
                effect->setMedia(QUrl("qrc:/sounds/eww.wav"));

            if (this->type == 1)
                effect->setMedia(QUrl("qrc:/sounds/ahh.wav"));

            effect->play();


            game->score->decrease(1);
            scene()->removeItem(this);
            delete this;
            return;
        }
       /* else if (typeid(*(colliding_items[i])) == typeid(Paul))
        {
           // if (this->type == 0){
                QMediaPlayer *nom = new QMediaPlayer();
                nom->setMedia(QUrl("qrc:/sounds/ouch.wav"));
                nom->play();
          /*  }

            if (this->type == 1) {
                QMediaPlayer *ouch = new QMediaPlayer();
                ouch->setMedia(QUrl("qrc:/sounds/ouch.wav"));
                ouch->play();
                //scene()->removeItem(colliding_items[i]);
                //delete colliding_items[i];
            }*/



           /* game->score->increase();
            scene()->removeItem(this);
            delete this;

            return;
        }*/
    }


    setPos(x(), y()+12);
    if (pos().y() + boundingRect().height() > 768)
    {
        scene()->removeItem(this);
        delete this;
    }
}
