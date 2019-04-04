#include <player.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <bullet.h>
#include "enemy.h"
#include "enemy2.h"
#include <QTimer>
#include "enemy3.h"
#include "enemy4.h"
#include "enemy5.h"
#include "enemy6.h"
#include "bullet2.h"
#include "bullet3.h"
#include "bullet4.h"
Player::Player(QGraphicsItem* parent): QGraphicsPixmapItem(parent)
{
    //setting the bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/balloon_pop.wav"));

    //setting the graphic
    setPixmap(QPixmap(":/images/smallShip.png"));

}

//Stuff that happens when key is pressed
void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
        setPos(x() - 15, y());
    }

    else if(event->key() == Qt::Key_Right)
    {
        if(pos().x()+ 100 < 800)
        setPos(x() + 15, y());
    }

    else if(event->key() == Qt::Key_Up)
    {
        if(pos().y() > 0)
        setPos(x(), y() - 15);
    }

    else if(event->key() == Qt::Key_Down)
    {
        if(pos().y() + 80 < 600)
        setPos(x(), y() + 15);
    }

    else if(event->key() == Qt::Key_A)
    {
        //create a bullet that will move to the left
        Bullet4* bullet4 = new Bullet4();
        bullet4->setPos(x() -40 ,y() + 20);
        bullet4->setFlag(QGraphicsItem::ItemIsFocusable);
        bullet4->setFocus();
        scene()->addItem(bullet4);

        //Play bullet sound
        if(bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->setVolume(47);
            bulletsound->play();
        }
    }

    else if(event->key() == Qt::Key_S)
    {
        //create a bullet that will move downward
        Bullet2* bullet2 = new Bullet2();
        bullet2->setPos(x() + 27,y() + 60);
        bullet2->setFlag(QGraphicsItem::ItemIsFocusable);
        bullet2->setFocus();
        scene()->addItem(bullet2);

        //Play bullet sound
        if(bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->setVolume(47);
            bulletsound->play();
        }
    }

    else if(event->key() == Qt::Key_W)
    {
        //create a bullet that will move upwards
        Bullet* bullet = new Bullet();
        bullet->setPos(x() + 27,y() - 25);
        bullet->setFlag(QGraphicsItem::ItemIsFocusable);
        bullet->setFocus();
        scene()->addItem(bullet);

        //Play bullet sound
        if(bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->setVolume(47);
            bulletsound->play();
        }
    }

    else if(event->key() == Qt::Key_D)
    {
        //Create a bullet that will move to the right
        Bullet3* bullet3 = new Bullet3();
        bullet3->setPos(x() + 95, y() + 20);
        bullet3->setFlag(QGraphicsItem::ItemIsFocusable);
        bullet3->setFocus();
        scene()->addItem(bullet3);

        //Play bullet sound
        if(bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->setVolume(47);
            bulletsound->play();
        }
    }
}

void Player::spawn()
{
    //Remember that when using gui the Y-axis increases,
    //as you go down the screen and decreases as you go up.


    //Create an enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);

    //create enemies moving in the positive x and y direction
    Enemy2* enemy2 = new Enemy2();
    scene()->addItem(enemy2);

    //create enemies moving in the negative x and positive y direction
    Enemy3* enemy3 = new Enemy3();
    scene()->addItem(enemy3);

    //create enemies moving in the positive x and negative y direction
    Enemy4* enemy4 = new Enemy4();
    scene()->addItem(enemy4);

    //create enemies moving in the positive x and negative y direction
    Enemy5* enemy5 = new Enemy5();
    scene()->addItem(enemy5);

    //Create enemies moving in the negative y direction.
    Enemy6* enemy6 = new Enemy6();
    scene()->addItem(enemy6);
}
