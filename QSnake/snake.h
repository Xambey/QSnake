#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QVector>
#include "direction.h"
#include "itemsnake.h"
class ItemSnake;
class Snake : public QWidget, public CommonDate
{
    Q_OBJECT
public:
    explicit Snake(QGraphicsScene& scene);
private:
    QGraphicsScene& scene;
    QVector<ItemSnake*> body;
    CommonDate::Direction direction;
};

#endif // SNAKE_H
