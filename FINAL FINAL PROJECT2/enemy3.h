#ifndef ENEMY3_H
#define ENEMY3_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Enemy3: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy3(QGraphicsItem* parent = 0);
public slots:
    void move();
};

#endif // ENEMY3_H
