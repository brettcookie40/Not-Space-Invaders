#include <QApplication>
#include "Game.h"
#include <cstdlib>
#include <iostream>
#include "homescreen.h"
HomeScreen * screen;
using namespace std;
//Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    screen = new HomeScreen();
    screen->show();
    screen->setFixedSize(800,600);
    /*
    game = new Game();
    game->show();
    */
    return a.exec();
}
