#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include "enemy2.h"
#include <QMediaPlayer>
#include <QImage>
#include <QMediaPlaylist>
#include <cstdlib>
Game::Game(QWidget *parent)
{
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/stars.gif")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->setPos(350,250); // TODO generalize to always be in the middle bottom of screen

    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    score->setPos(score->x(), score->y() + 60);
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+40);
    scene->addItem(health);

    // spawn enemies at a certain rate.
    //increasing the number lowers difficulty. Decreasing the number adds difficulty
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1800);

    //play background music
    QMediaPlayer* gameMusic = new QMediaPlayer();
    gameMusic->setMedia(QUrl("qrc:/sounds/LastStand.mp3"));
    gameMusic->play();

show();

}
