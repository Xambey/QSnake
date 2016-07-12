#include "itemsnake.h"
#include <snake.h>
#include <QPainter>
inline qreal ItemSnake::getAngle() const
{
    return angle;
}

void ItemSnake::setAngle(qreal angle)
{
    this->angle = angle;
}

ItemSnake::ItemSnake(SnakeBase* snake):
                        length(60),
                        angle(0.0),
                        mode(Mode::Piece),
                        m_snake(snake),
                        active(false)
{
}

ItemSnake::ItemSnake(SnakeBase* snake, qreal startAngle) :
                        angle(startAngle),
                        length(60),
                        mode(Mode::Head),
                        m_snake(snake),
                        active(true)

{
}

inline QPointF ItemSnake::getOldPoint() const
{
    return oldPoint;
}

void ItemSnake::SetAnglePrevItem()
{
    angle = m_snake->getPrevItem(this)->getAngle();
}


void ItemSnake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    Q_UNUSED(option);
    Q_UNUSED(widget);

    //draw center item, test mode
    //painter->setPen(QPen(Qt::blue,6,Qt::SolidLine));
    //painter->drawPoint(QPointF(x(),y()));

    //  i-point turn     x-x()     X = i+(x-i)cos(a)-(j-y)sin(a);
    //  j-point turn     y-y()     Y = -j+(x-i)sin(a)+(j-y)cos(a);

    if(m_snake->getPrevItem(this) == nullptr) {
        mode = Mode::Tail;
    } else
        mode = Mode::Piece;


    switch (mode) {
    case Mode::Head :
        painter->setPen(QPen(Qt::green, 2, Qt::SolidLine));
        painter->setBrush(Qt::green);

        painter->drawChord(x()-length/4,y()-length/2,length/2, length,0,16*180);

        painter->setPen(QPen(Qt::black));
        painter->setBrush(Qt::black);

        painter->drawEllipse(QRectF(x()-length/6,y()-length/3,7,7));
        painter->drawEllipse(QRectF(x()+length/16,y()-length/3,7,7));
        break;
    case Mode::Piece :
        if(active)
            moveBy(m_snake->getPrevItem(this)->getOldPoint().x(),m_snake->getPrevItem(this)->getOldPoint().y());
        else
            active = true;
        painter->setPen(QPen(Qt::green, 2, Qt::SolidLine));
        painter->drawLine(x()-length/4,y(),x()+length/4,y());
        SetAnglePrevItem();
        break;
    case Mode::Tail :
        if(active)
            moveBy(m_snake->getPrevItem(this)->getOldPoint().x(),m_snake->getPrevItem(this)->getOldPoint().y());
        else
            active = true;
        painter->setPen(QPen(Qt::green, 2, Qt::SolidLine));
        painter->setBrush(Qt::green);
        painter->drawChord(x()-length/4,y()-length/2,length/2, length,180,16*180);
        SetAnglePrevItem();
        break;
    default:
        //throw "Undefined mode";
        break;
    }

    setRotation(angle);

    oldPoint.setX(x());
    oldPoint.setY(y());
}

QRectF ItemSnake::boundingRect() const
{
    return QRectF(QPointF(x()-length/4,y()-length/2),QSize(length/1.5,length/1.5));
}

