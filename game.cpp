#include <fstream>
#include <iostream>
#include <string>
#include "game.h"
#include "global.h"
#include "startbutton.h"
#include <QDebug>
#include <QInputDialog>
using namespace std;
Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);
    scene->setSceneRect(0,0,1024,768);
    scene->setBackgroundBrush(QBrush(QImage(":/images/kitchen.png")));
    setScene(scene);
}

void Game::start()
{

    QMediaPlayer *awesome = new QMediaPlayer();
    awesome->setMedia(QUrl("qrc:/sounds/nom.wav"));
    awesome->play();

    scene->clear();
    Player * player = new Player();
    player->setPixmap(QPixmap(":/images/player.png"));


    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    Timer * counter = new Timer();
    scene->addItem(counter);

    /*QGraphicsView * view;
    view = new QGraphicsView(scene);
    view->show();*/

    Paul * paul = new Paul();
    scene->addItem(paul);


    player->setPos(scene->width()/2, scene->height() - player->boundingRect().height());

    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(500);

    QTimer * fishTimer = new QTimer();
    QObject::connect(fishTimer, SIGNAL(timeout()), player, SLOT(spawnEnemy()));
    fishTimer->start(3600);

    QTimer * anvilTimer = new QTimer();
    QObject::connect(anvilTimer, SIGNAL(timeout()), player, SLOT(spawnAnvil()));
    anvilTimer->start(6000);



    QTimer * countdown = new QTimer();
    QObject::connect(countdown, SIGNAL(timeout()), counter, SLOT(countdown()));
    countdown->start(1000);

}

void Game::displayMainMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Paddy's Pie Challenge"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tYpos = 150;
    titleText->setPos(txPos, tYpos-27);
    scene->addItem(titleText);

    StartButton* playButton = new StartButton(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos, byPos);
    connect(playButton, SIGNAL(clicked()),this,SLOT(intro()));
    scene->addItem(playButton);

    StartButton* quitButton = new StartButton(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    QGraphicsPixmapItem* story = new QGraphicsPixmapItem();
    story->setPos(0, 468);
    story->setPixmap(QPixmap(":/images/story.png"));
    scene->addItem(story);



}

void Game::intro()
{
    QGraphicsPixmapItem* intro = new QGraphicsPixmapItem();
    intro->setPixmap(QPixmap(":/images/intro.png"));
    scene->addItem(intro);

    StartButton* playButton = new StartButton(QString("Let's Go!"));
    int bxPos = this->width() - playButton->boundingRect().width()-50;
    int byPos = this->height()/2 - playButton->boundingRect().height()/2;
    playButton->setPos(bxPos, byPos);
    connect(playButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);
}

void Game::endGame()
{


    scene->clear();
    Score * finalScore;
    finalScore = new Score;
    finalScore->setPlainText(QString("Your Score: ") + QString::number(myScore));
    finalScore->setFont(QFont("times", 36));
    finalScore->setPos(500, 500);
    scene->addItem(finalScore);


    QFile myFile ("scores.txt");
    myFile.open(QIODevice::ReadOnly);
    QTextStream in(&myFile);

    QString qName = in.readLine();
    QString qScore = in.readLine();
    myFile.close();

    bool ok;
    if(qScore.toInt() < myScore)
    {
        QMediaPlayer *player = new QMediaPlayer();
        player->setMedia(QUrl("qrc:/sounds/highscore.wav"));
        player->play();

        QInputDialog* inputDialog = new QInputDialog();
        inputDialog->setOptions(QInputDialog::NoButtons);
        qName =  inputDialog->getText(NULL ,"High Score!",
                                             "Enter Name:", QLineEdit::Normal,
                                             "Grandma", &ok);
        if (ok && !qName.isEmpty())
        {
            qDebug() << "Good Job!";
        }

        qScore = QString::number(myScore);
        string nameS, scoreS;
        nameS = qName.toStdString();
        scoreS = qScore.toStdString();
        myFile.open(QIODevice::WriteOnly);
        QTextStream out (&myFile);
        out << nameS.c_str() << endl << scoreS.c_str();
        myFile.flush();
        myFile.close();

    }

    else{
        QMediaPlayer *player = new QMediaPlayer();
        player->setMedia(QUrl("qrc:/sounds/awwman.wav"));
        player->play();
    }



    Score * highScore;
    highScore = new Score;
    highScore->setPlainText(QString("High Score: ") + QString(qName) + QString(" ") + QString(qScore));
    highScore->setFont(QFont("times", 36));
    highScore->setPos(200, 170);
    scene->addItem(highScore);

    /*StartButton* playButton = new StartButton(QString("Play Again"));
    int bxPos = 300;
    int byPos = 350;
    playButton->setPos(bxPos, byPos);
    connect(playButton, SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);*/

    StartButton* quitButton = new StartButton(QString("Quit"));
    int qxPos = 350;
    int qyPos = 350;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    myScore = 0;

    //
}
