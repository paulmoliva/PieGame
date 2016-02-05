#ifndef PIE_H
#define PIE_H
#include <QGraphicsScene>
#include <QObject>
#include<QGraphicsPixmapItem>
#include <QMediaPlayer>
class Pie : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Pie();



public slots:
    void move();
};

#endif // PIE_H
