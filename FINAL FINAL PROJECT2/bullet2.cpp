#include <bullet2.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <enemy.h>
#include <typeinfo>
#include "game.h"
#include "enemy2.h"
#include <QKeyEvent>
#include "enemy3.h"
#include "enemy4.h"
#include "enemy5.h"
#include "enemy6.h"
//#include "player.h"

extern Game* game; //external global object called game

Bullet2::Bullet2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //Draw graphics
    setPixmap(QPixmap(":/images/lazerBall.png"));

    //Connect
        QTimer* timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this, SLOT(move()));
        timer->start(50);
}

/*
void Bullet::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_D)
    {
        //move bullet right
        setPos(x() + 15, y());
    }

    else if(event->key() == Qt::Key_W)
    {
        //move bullet up
        setPos(x(), y() - 15);
    }

    else if(event->key() == Qt::Key_S)
    {
        //move bullet down
        setPos(x(), y() + 10);
    }

    else if(event->key() == Qt::Key_A)
    {
        //move bullet left
        setPos(x() - 10, y());
    }
}
*/

void Bullet2::move()
{
    //gets list of all items currently colliding with bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //if one of the colliding items is an enemy destroy both bullet and enemy
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy) ||
           typeid(*(colliding_items[i])) == typeid(Enemy2)||
           typeid(*(colliding_items[i])) == typeid(Enemy3)||
           typeid(*(colliding_items[i])) == typeid(Enemy4)||
           typeid(*(colliding_items[i])) == typeid(Enemy5)||
           typeid(*(colliding_items[i])) == typeid(Enemy6))
        {
            //increase the score
            game->score->increase();
            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(), y() + 10);

    //If bullet is off the screen delete it
    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
    else if(pos().x() < 0)
    {
        scene()-> removeItem(this);
        delete this;
    }

    else if(pos().y() > 600)
    {
        scene()->removeItem(this);
        delete this;
    }

    else if(pos().x() > 800)
    {
        scene()->removeItem(this);
        delete this;
    }
}
