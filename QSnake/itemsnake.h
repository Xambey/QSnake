#ifndef ITEMSNAKE_H
#define ITEMSNAKE_H

#include <QtWidgets>
#include "snake.h"

class ItemSnake : public QGraphicsItem
{
public:
    int GetAngle();
    void SetAngleItem(int angle);

    ItemSnake(QGraphicsScene& scene);
    ItemSnake(QGraphicsScene& scene, double startAngle, QVector<ItemSnake*>& body);
private:
    void SetAnglePrevItem();
    int length;
    double angle;
    double oldX, oldY;
    QGraphicsScene& scene;
    QVector<ItemSnake*>* body;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // ITEMSNAKE_H
