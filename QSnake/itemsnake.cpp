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
                        rate(50),
                        length(40)
{
}

ItemSnake::ItemSnake(QGraphicsScene &scene, int startAngle, QVector<ItemSnake *>& body) :
                        scene(scene),
                        body(&body),
                        angle(startAngle),
                        rate(50),
                        length(40)
{
    painter = new QPainter(this);
}

void ItemSnake::RotateItem(int angle)
{
    qreal x = this->x() + length/2*cos(angle);
    qreal y = this->y() + length/2*sin(angle);
}

void ItemSnake::SetAnglePrevItem()
{
    angle = body->at(index - 1)->GetAngle();
}

void ItemSnake::RenderMode()
{
    QPointF p1, p2;
    QPainter painter(this);
    painter.setPen(QPen(Qt::green, 2, Qt::SolidLine));
    painter.setBrush(Qt::green);
    painter.drawChord(x() - length/2,y(),length/2, length*1.3,0,16*180);


    //painter.translate(x(),y() - length);
    //painter.rotate(30);
    painter.
    painter.setPen(QPen(Qt::black));
    painter.setBrush(Qt::black);
    painter.drawEllipse(QRectF(x()-length/4,y() + length/4,7,7));
}

void ItemSnake::paintEvent(QPaintEvent *)
{
    //RenderMode();
}
