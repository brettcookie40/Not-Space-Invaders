#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Enemy2: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy2(QGraphicsItem* parent = 0);
public slots:
    void move();
};

#endif // ENEMY2_H
