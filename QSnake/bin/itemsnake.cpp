#include "Include/itemsnake.h"
#include <QPainter>
#include <QException>
#include <QErrorMessage>
#include "Include/snake.h"

inline qreal ItemSnake::getAngle() const
{
    if(angle <= 360 && angle >= 0)
        return angle;
    QErrorMessage message;
    message.setFixedSize(100,100);
    message.showMessage("Angle not defined");
}

inline void ItemSnake::setAngle(qreal angle)
{
    this->angle = angle;
}

void ItemSnake::setOldPoint(qreal x, qreal y)
{
    oldPoint.setX(x);
    oldPoint.setY(y);
}

void ItemSnake::setOldPoint(QPointF point)
{
    oldPoint.setX(point.x());
    oldPoint.setY(point.y());
}

ItemSnake::ItemSnake(SnakeBase* snake, QPointF p, Mode mode, qreal startAngle):
                        length(60),
                        angle(startAngle),
                        mode(mode),
                        m_snake(snake),
                        active(false),
                        oldPoint(p)
{
    setPos(p);
}

ItemSnake::ItemSnake(SnakeBase* snake, qreal x, qreal y, Mode mode, qreal startAngle) :
                        angle(startAngle),
                        length(60),
                        mode(mode),
                        m_snake(snake),
                        active(true),
                        oldPoint(x,y)

{
    setPos(x,y);
}

inline Mode ItemSnake::getMode() const
{
    return mode;
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

    //auto change piece to tail
    if(active && mode != Mode::Head) {
        if(m_snake->getPrevItem(this) == nullptr) {
            mode = Mode::Tail;
            if(m_snake->getNextItem(this)->getMode() != Mode::Head){}
                //m_snake->getNextItem(this)
        } else
            mode = Mode::Piece;
    }


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

