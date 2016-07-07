#include "itemsnake.h"

int ItemSnake::GetAngle()
{
    return angle;
}

void ItemSnake::SetAngleItem(int angle)
{
    this->angle = angle;
}

ItemSnake::ItemSnake(QGraphicsScene& s):
                        scene(s),
                        length(60),
                        body(nullptr),
                        angle(0.0)

{
}

ItemSnake::ItemSnake(QGraphicsScene &s, double startAngle, QVector<ItemSnake *>& vec) :
                        scene(s),
                        body(&vec),
                        angle(startAngle),
                        length(60)
{
}

void ItemSnake::SetAnglePrevItem()
{
    angle = body->at(body->indexOf(this) - 1)->GetAngle();
}


void ItemSnake::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //axis scene
    scene.addLine(100,0,100,200,QPen(Qt::red));
    scene.addLine(0,100,200,100,QPen(Qt::red));

    painter->setPen(QPen(Qt::blue, 3, Qt::SolidLine));
    painter->setBrush(Qt::green);

    //axis painter
    painter->drawLine(100,0,100,200);
    painter->drawLine(0,100,200,100);


    Q_UNUSED(option);
    Q_UNUSED(widget);
    //  i-point turn     x-x()     X = i+(x-i)cos(a)-(j-y)sin(a);
    //  j-point turn     y-y()     Y = -j+(x-i)sin(a)+(j-y)cos(a);
    //new Points
    QPointF p1(x()+(x() - length/4-x())*cos(angle)+(y()-y())*sin(angle), y()+(x() - length/4-x())*sin(angle)-(y()-y())*cos(angle));
    QPointF p2(x()+(x() - length/5-x())*cos(angle)+(y() + length/4-y())*sin(angle), y()+(x() - length/5-x())*sin(angle)-(y() + length/4-y())*cos(angle));
    QPointF p3(x()+(x() + length/14-x())*cos(angle)+(y() + length/4-y())*sin(angle), y()+(x() + length/14-x())*sin(angle)-(y() + length/4-y())*cos(angle));


    painter->setPen(QPen(Qt::green, 2, Qt::SolidLine));
    painter->setBrush(Qt::green);

    //painter->drawChord(p1.x(),p1.y(),length/2, length,0,16*180);
    painter->drawLine(QPointF(-length,y()),QPointF(x(),y()));
    //painter->drawLine(QPointF(x()+(x()-length/2-x())*cos(angle)-(y()-y())*sin(angle),-y()+(x()-length/2-x())*sin(angle)+(y()-y())*cos(angle)),QPointF(x()+(x()+length/2-x())*cos(angle)-(y()-y())*sin(angle),-y()+(x()+length/2-x())*sin(angle)+(y()-y())*cos(angle)));

    //this->setTransform(QTransform().translate(x()/2,y()/2).rotate(45,Qt::ZAxis).translate(-x()/2,-y()/2));
    painter->translate(x()/2,y()/2);
    painter->rotate(45);
    painter->translate(-x()/2,-y()/2);

    painter->setPen(QPen(Qt::black));
    painter->setBrush(Qt::black);
    painter->drawLine(QPointF(x(),y()),QPointF(x()+length,y()));

    //painter->drawEllipse(QRectF(x()-length/5,y()+length/4,5,5));
    //painter->drawEllipse(QRectF(p2.x(),p2.y(),5,5));

   // painter->drawEllipse(QRectF(p3.x(),p3.y(),5,5));
    //painter->end();

    oldX = x();
    oldY = y();
}

QRectF ItemSnake::boundingRect() const
{
    return QRectF(-length,-length,length,length);
}

