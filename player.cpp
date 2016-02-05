#include "player.h"
#include "pie.h"
#include "enemy.h"
#include <QDebug>



void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if(pos().x()>0)
        {
            setPos(x()-10, y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if(pos().x()<1014-this->boundingRect().width())
        {
        setPos(x()+10, y());
        }
    }
    else if (event->key() == Qt::Key_Up)
    {
        setPos(x(), y()-10);
    }
    else if (event->key() == Qt::Key_Down)
    {
        setPos(x(), y()+10);
    }
}

void Player::spawn()
{
    Pie *pie = new Pie();
    scene()->addItem(pie);

}
void Player::spawnEnemy()
{
    Enemy *fish = new Enemy();
    scene()->addItem(fish);
    //qDebug() << "Fish added!";
}

void Player::spawnAnvil()
{
    Enemy *anvil = new Enemy(1);
    scene()->addItem(anvil);
    //qDebug() << "Fish added!";
}

void Player::timeDown(int * time, QGraphicsTextItem * display)
{

    *time--; // decrement counter
    scene()->removeItem(display);
    scene()->addItem(display);
    if (time==0) // countdown has finished
    {
        // timeout
    }
    else // re-start counter
    {

    }
}
