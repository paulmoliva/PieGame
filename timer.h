#ifndef TIMER_H
#define TIMER_H
#include <QGraphicsTextItem>
#include<QObject>
#include "game.h"

class Timer: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Timer();

private:
    int time;

public slots:
    void countdown();
};

#endif // TIMER_H
