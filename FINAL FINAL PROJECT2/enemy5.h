#ifndef ENEMY5_H
#define ENEMY5_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
class Enemy5: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy5(QGraphicsItem* parent = 0);
public slots:
    void move();
};

#endif // ENEMY5_H
