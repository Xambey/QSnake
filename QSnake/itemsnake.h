#ifndef ITEMSNAKE_H
#define ITEMSNAKE_H

#include <QAbstractItemModel>
#include <QtWidgets>
#include "snake.h"

class ItemSnake : public QGraphicsItem
{
public:
    int GetAngle();
    void SetAngleItem(int angle);

    ItemSnake(QGraphicsScene& scene);
    ItemSnake(QGraphicsScene& scene, int startAngle, QVector<ItemSnake*>& body);
private:
    void SetAnglePrevItem();
    const int length;
    int angle;
    QGraphicsScene& scene;
    QVector<ItemSnake*>* body;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // ITEMSNAKE_H
