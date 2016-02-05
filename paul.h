#ifndef PAUL_H
#define PAUL_H
#include <QGraphicsScene>
#include <QObject>
#include<QGraphicsPixmapItem>
#include<QTimer>


class Paul : public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
    Paul();
public slots:
    void move();
};

#endif // PAUL_H
