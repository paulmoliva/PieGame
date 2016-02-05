#include "score.h"
#include "global.h"
#include<QFont>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Score::increase()
{
    score ++;
    myScore ++;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::decrease(int i)
{
    if (score > 0)
    {
        score -=i;
        myScore -=i;
        setPlainText(QString("Score: ") + QString::number(score));
    }
}

int Score::getScore()
{
   return score;
}

