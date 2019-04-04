#include "Health.h"
#include <QFont>
#include "game.h"
#include "endscreen.h"

extern Game * game;

EndScreen * FinalScreen;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the health to 3
    health = 3;
    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{

    //Exit if health drops below 0
    if(health == 1) // < 1)//for some reason this works. it was == 0
    {
            FinalScreen = new EndScreen();
            FinalScreen->show();
            FinalScreen->setFixedSize(600,400);
            FinalScreen->setAutoFillBackground(":/Images/Background.png");
            game->close();
        //exit(1);
    }
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

int Health::getHealth()
{
    return health;
}
