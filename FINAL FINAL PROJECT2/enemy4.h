#ifndef ENEMY4_H
#define ENEMY4_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Enemy4: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy4(QGraphicsItem* parent = 0);
public slots:
    void move();
};

#endif // ENEMY4_H
