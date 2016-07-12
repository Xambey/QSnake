#ifndef ITEMSNAKE_H
#define ITEMSNAKE_H

#include "snake.h"
#include <QGraphicsItem>

class SnakeBase;
class ItemSnake : public QGraphicsItem
{
public:
    ItemSnake(SnakeBase* snake, QPointF point, Mode mode, qreal startAngle = 0);
    ItemSnake(SnakeBase* snake, qreal x, qreal y, Mode mode, qreal startAngle = 0); //create head of snake

    inline Mode getMode() const;
    inline QPointF getOldPoint() const;
    inline qreal getAngle() const;
    inline void setAngle(qreal angle);
    inline void setOldPoint(qreal x, qreal y);
    inline void setOldPoint(QPointF point);
    enum Mode{
        Piece,
        Head,
        Tail
    };
private:
    SnakeBase* m_snake;
    void SetAnglePrevItem();

    int length;
    qreal angle;
    QPointF oldPoint;

    Mode mode;
    bool active;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // ITEMSNAKE_H
