#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <QtWidgets>
#include <QVector>
#include "snakebase.h"

class Snake : protected SnakeBase
{
public:
    explicit Snake(QGraphicsView* view);
    ItemSnake* getPrevItem(ItemSnake *item);
private:
    QGraphicsView* view;
    QVector<ItemSnake*> body;
protected:
};



#endif // SNAKE_H
