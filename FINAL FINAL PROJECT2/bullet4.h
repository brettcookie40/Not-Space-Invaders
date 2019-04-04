#ifndef BULLET4_H
#define BULLET4_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet4: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet4(QGraphicsItem* parent = 0);
public slots:
    void move();
};

#endif // BULLET4_H
