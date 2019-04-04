#ifndef BULLET3_H
#define BULLET3_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet3: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet3(QGraphicsItem* parent = 0);
public slots:
    void move();
};

#endif // BULLET3_H
