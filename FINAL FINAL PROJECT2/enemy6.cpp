#include "enemy6.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QList>
#include "game.h"
#include <iostream>
#include "enemy.h"
#include <typeinfo>
using namespace std;
extern Game* game;

Enemy6::Enemy6(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random position
    int random_number = rand() % 700;
    setPos(random_number, 599);

    //Creating Enemy size
    setPixmap(QPixmap(":/images/SmallAsteroid.png"));

    //Connect
        QTimer* timer = new QTimer();
        connect(timer, SIGNAL(timeout()),this, SLOT(move()));
        timer->start(50);
}

void Enemy6::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //move Enemy straight up from the bottom
    setPos(x(), y() - 5);

    //destroy enemy when leaving the screen
    if(pos().y() < -150)
    {
        //decrease the health
        //game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

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
    //destroy enemy when passing the end of the x-axis
    if(pos().x() > 800)
    {
        scene()->removeItem(this);
        delete this;
    }
}
