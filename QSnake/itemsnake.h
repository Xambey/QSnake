#ifndef ITEMSNAKE_H
#define ITEMSNAKE_H

#include <QtWidgets>

class SnakeBase;
class ItemSnake : public QGraphicsItem
{
public:
    ItemSnake(SnakeBase* snake);
    ItemSnake(SnakeBase* snake, qreal startAngle); //create head of snake
private:
    inline QPointF getOldPoint() const;
    inline qreal getAngle() const;
    void setAngle(qreal angle);
    SnakeBase* m_snake;

    void SetAnglePrevItem();
    int length;
    qreal angle;
    QPointF oldPoint;

    enum Mode{
        Piece,
        Head,
        Tail
    };
    Mode mode;
    bool active;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // ITEMSNAKE_H
