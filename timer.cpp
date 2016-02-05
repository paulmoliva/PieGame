#include "timer.h"
#include <QFont>
extern Game * game;
Timer::Timer()
{
    time = 60;
    setPos(200,0);
    setPlainText(QString("Time: ") + QString::number(time));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

}


void Timer::countdown()
{
    time --;
    setPlainText(QString("Time: ") + QString::number(time));
    if (time == 0)
        game->endGame();
}
