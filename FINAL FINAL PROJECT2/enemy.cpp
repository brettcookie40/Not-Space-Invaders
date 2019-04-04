#include <enemy.h>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>
#include "game.h"
#include <iostream>
#include <typeinfo>
using namespace std;
extern Game* game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random position
    int random_number = rand() % 700;
    setPos(random_number, -150);



    //Creating Enemy size
    setPixmap(QPixmap(":/images/SmallAsteroid.png"));

    //Connect
        QTimer* timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this, SLOT(move()));
        timer->start(50);
}

void Enemy::move()
{
    //allows collision detection
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //move Enemy down
    setPos(x(),y() + 5);

    //destroy enemy when hitting player. reduce player health
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Player))
        {
            //decrease health
            game-> health->decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    //destroy enemy when leaving the screen
    if(pos().y() > 600)
    {
        //decrease the health
        //game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
