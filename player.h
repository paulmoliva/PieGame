#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsPixmapItem>
#include<QKeyEvent>
#include <QObject>
#include <QGraphicsScene>
#include<QGraphicsTextItem>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();
    void timeDown(int *time, QGraphicsTextItem *display);
    void spawnEnemy();
    void spawnAnvil();
};

#endif // MYRECT_H
