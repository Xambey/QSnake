#include "itemsnake.h"

int ItemSnake::GetAngle()
{
    return angle;
}

void ItemSnake::SetAngleItem(int angle)
{
    this->angle = angle;
}

ItemSnake::ItemSnake(QGraphicsScene& scene):
                        scene(scene),
                        length(60)
{
}

ItemSnake::ItemSnake(QGraphicsScene &scene, int startAngle, QVector<ItemSnake *>& body) :
                        scene(scene),
                        body(&body),
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
    QPointF p1, p2;
    qDebug() << x() << " " << y();
    painter->setTransform(QTransform()
            .translate(x()/ 2, y()/ 2)
//            .rotate(angle, Qt::XAxis)
//            .rotate(angle, Qt::YAxis)
            .rotate(angle, Qt::ZAxis)
            .translate(-x()/2, -y())/2);
    qDebug() << x() << " " << y();
    painter->setPen(QPen(Qt::green, 2, Qt::SolidLine));
    painter->setBrush(Qt::green);
    painter->drawChord(x() - length/4 + length/2*cos(angle),y()+length/2*sin(angle),length/2, length,0,16*180);

    painter->setPen(QPen(Qt::black));
    painter->setBrush(Qt::black);
    painter->drawEllipse(QRectF(x() - length/5 + length/2*cos(angle),y() + length/4+length/2*sin(angle),5,5));
    painter->drawEllipse(QRectF(x() + length/14 +length/2*cos(angle),y() + length/4+length/2*sin(angle),5,5));
    painter->end();
}

QRectF ItemSnake::boundingRect() const
{
    return QRectF(QPointF(x(),y()),QSizeF(length/2,length*1.3));
}

