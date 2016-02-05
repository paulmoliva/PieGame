#include "pie.h"
#include "player.h"
#include <QTimer>

#include <QList>
#include <stdlib.h>
#include "game.h"
#include <typeinfo>
extern Game * game;
Pie::Pie(): QObject(), QGraphicsPixmapItem()
{
    int random_number = rand() % 924;
    setPos(random_number, 0);
    setPixmap(QPixmap(":/images/Pie.png"));

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);

}

void Pie::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i =0, n=colliding_items.size(); i<n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Player))
        {
            QMediaPlayer *nom = new QMediaPlayer();
            nom->setMedia(QUrl("qrc:/sounds/bunny.wav"));
            nom->play();

            game->score->increase();
            scene()->removeItem(this);

            delete this;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Paul))
        {
            QMediaPlayer *nom = new QMediaPlayer();
            nom->setMedia(QUrl("qrc:/sounds/ouch.wav"));
            nom->play();

            game->score->decrease(1);
            scene()->removeItem(this);
            delete this;

            return;
        }
    }


    setPos(x(), y()+5);
    if (pos().y() + boundingRect().height() > 768)
    {
        scene()->removeItem(this);
        delete this;
    }
}



