#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsScene>
#include <QObject>
#include<QGraphicsPixmapItem>
class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
    Enemy(int i);
    int type;


public slots:
    void move();

};


#endif // ENEMY_H
