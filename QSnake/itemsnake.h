#ifndef ITEMSNAKE_H
#define ITEMSNAKE_H

#include <QAbstractItemModel>
#include <QtWidgets>
#include "direction.h"

class ItemSnake : public QWidget, public CommonDate
{
    Q_OBJECT
public:
    explicit ItemSnake(QGraphicsScene& scene, CommonDate::Direction dir);
private:
    CommonDate::Direction direction; //direction snake
    const int offest;
    QGraphicsScene& scene;
protected:
    void RenderMode(CommonDate::Direction dir); //render item on the mode
    void paintEvent(QPaintEvent*);
};

#endif // ITEMSNAKE_H
