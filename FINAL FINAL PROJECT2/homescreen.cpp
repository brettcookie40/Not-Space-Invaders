#include "homescreen.h"
#include "game.h"
#include <QMediaPlayer>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
Game * game;

HomeScreen::HomeScreen(QWidget *parent){

    QLabel * title = new QLabel("<font size=140 color=black>Asteroid Assault</font>",this);
    QLabel * how_to = new QLabel(this);
    QPushButton * play_btn = new QPushButton("Play",this);

    QString how_to_txt(QString("-move with the Up, Down, Left, and Right keys<br>") +
                       QString("-multi-directional shooting with w, a, s, and d keys<br>") +
                       QString("-Shooting an asteriod will increase your score by 1<br>") +
                       QString("-Letting an asteriod get past you will decrease your lives by 1<br>") +
                       QString("-You've only got 3 lives so be careful!!!<br>") +
                       QString("*turn up your volume (there is music!)")
                       );

    how_to->setText(how_to_txt);
    how_to->setAlignment(Qt::AlignHCenter);
    title->setAlignment(Qt::AlignHCenter);

    //QWidget *controlsRestrictorWidget = new QWidget();

    QVBoxLayout * layout = new QVBoxLayout(this);

    layout->addWidget(title);
    layout->addWidget(how_to);
    layout->addWidget(play_btn);

    setLayout(layout);

    connect(play_btn,SIGNAL(clicked()),this,SLOT(play()));
}

void HomeScreen::play()
{

    game = new Game();
    game->show();
    //close window
    close();
}


