#include "itemsnake.h"

ItemSnake::ItemSnake(QGraphicsScene& scene, CommonDate::Direction dir)
    : direction(dir), scene(scene), offest(30)
{
    scene.setSceneRect(0,0,500,500);
    //resize(offest + 50,offest + 50);
//    QPalette pal;
//    pal.setColor(backgroundRole(),Qt::green);
//    setAutoFillBackground(true);
//    setPalette(pal);
}

void ItemSnake::RenderMode(Direction dir)
{
    QPainter painter(this);

    painter.setPen(QPen(Qt::green,2,Qt::SolidLine));

    if(dir == CommonDate::Down || dir == CommonDate::Up) {
        painter.drawLine(x() - offest, y() - offest, x() - offest, y() + offest);
        painter.drawLine(x() + offest, y() - offest, x() + offest, y() + offest);
        //painter.setBackground(QBrush(Qt::green));
        painter.setBrush(Qt::green);
//        QPalette pal;
//        pal.setColor(this->backgroundRole(), Qt::green);

//        this->setPalette(pal);
//        this->setAutoFillBackground(true);
//        qDebug() << scene.sceneRect();
    }

    if(dir == CommonDate::Right || dir == CommonDate::Left) {
        painter.drawLine(x() - offest, y() - offest, x() + offest, y() - offest);
        painter.drawLine(x() - offest, y() + offest, x() + offest, y() + offest);
        painter.setBackground(QBrush(Qt::green));
    }
    switch (dir) {
        case CommonDate::DownHead:
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.drawLine(x() - offest, y() - offest, x() - offest, y() + offest);
            painter.drawLine(x() + offest, y() - offest, x() + offest, y() + offest);
            painter.setClipRect(x(), y() , offest, offest);
            painter.drawEllipse(x(), y() + offest, offest, offest);

            painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));

            painter.drawPoint(x() - offest / 2, y());
            painter.drawPoint(x() + offest / 2, y());
            break;
        case CommonDate::LeftHead :
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.drawLine(x() - offest, y() - offest, x() + offest, y() - offest);
            painter.drawLine(x() - offest, y() + offest, x() + offest, y() + offest);
            painter.setClipRect(x(), y() , offest, offest);
            painter.drawEllipse(x() - offest, y(), offest, offest);

            painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));

            painter.drawPoint(x() , y() - offest / 2);
            painter.drawPoint(x() , y() + offest / 2);
            break;
        case CommonDate::RightHead :
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.drawLine(x() - offest, y() - offest, x() + offest, y() - offest);
            painter.drawLine(x() - offest, y() + offest, x() + offest, y() + offest);
            painter.setClipRect(x(), y() , offest, offest);
            painter.drawEllipse(x() + offest, y(), offest, offest);

            painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));

            painter.drawPoint(x() , y() - offest / 2);
            painter.drawPoint(x() , y() + offest / 2);
            break;
        case CommonDate::UpHead :
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.drawLine(x() - offest, y() - offest, x() - offest, y() + offest);
            painter.drawLine(x() + offest, y() - offest, x() + offest, y() + offest);
            painter.setClipRect(x(), y() , offest, offest);
            painter.drawEllipse(x(), y() - offest, offest, offest);

            painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));

            painter.drawPoint(x() - offest / 2, y());
            painter.drawPoint(x() + offest / 2, y());
            break;
        case CommonDate::TurnLeftDown :
            for(int i = 0; i <= offest; i++ ) {
                painter.drawPoint(x() - offest - i, y() - offest + i);
                painter.drawPoint(x() - offest - i, y() + offest + i);
            }
            painter.setBackground(QBrush(Qt::green));
            break;
        case CommonDate::TurnLeftUp :
            for(double ix = 0, iy = 0; ix <= 45; ix+= 0.5, iy++) {
                painter.drawPoint(x() - 2 * offest + offest * cos(ix), y() - 2 * offest + offest * sin(iy));
                painter.drawPoint(x() - 2 * offest + offest * sin(ix), y() + 2 * offest + offest * cos(iy));
            }
            painter.setBackground(QBrush(Qt::green));
            break;
        case CommonDate::TurnRightDown :
            for(int i = 0; i <= offest; i++ ) {
                painter.drawPoint(x() - offest + i, y() + offest + i);
                painter.drawPoint(x() + offest + i, y() + offest + i);
            }
            painter.setBackground(QBrush(Qt::green));
            break;
        case CommonDate::TurnRightUp :
            for(int i = 0; i <= offest; i++ ) {
                painter.drawPoint(x() - offest + i, y() - offest - i);
                painter.drawPoint(x() + offest + i, y() - offest - i);
            }
            painter.setBackground(QBrush(Qt::green));
            break;
        default:
            //throw UnknownDirection;
            break;
    }
}

void ItemSnake::paintEvent(QPaintEvent *)
{
    RenderMode(direction);
}
