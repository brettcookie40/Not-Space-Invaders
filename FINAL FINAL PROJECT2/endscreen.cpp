#include "endscreen.h"
#include "score.h"
#include "game.h"

#include <QString>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QVBoxLayout>

extern Game * game;

//int score_display = game->score;

EndScreen::EndScreen(QWidget *parent){
    QLabel * title = new QLabel("<font size=150 color=black>End Game</font>",this);
    QLabel * end_game = new QLabel(this);
  //  QLCDNumber * score_label = new QLabel(game->score);
    QPushButton * exit_btn = new QPushButton("Exit",this);

    QString end_game_txt(QString("You have lost the game :(<br>") +
                         QString("Press Exit to quit<br>") );

    end_game->setText(end_game_txt);
    end_game->setAlignment(Qt::AlignHCenter);
    title->setAlignment(Qt::AlignHCenter);

    QVBoxLayout * layout = new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(end_game);
    layout->addWidget(exit_btn);

    setLayout(layout);

    connect(exit_btn,SIGNAL(clicked()),this,SLOT(end()));
}

void EndScreen::end(){

    exit(0);
}
