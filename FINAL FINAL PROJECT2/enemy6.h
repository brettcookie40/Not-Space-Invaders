#ifndef ENEMY6_H
#define ENEMY6_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Enemy6: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy6(QGraphicsItem* parent = 0);
public slots:
    void move();
};

#endif // ENEMY6_H
