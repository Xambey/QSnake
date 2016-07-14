#pragma once
#ifndef SNAKE_H
#define SNAKE_H


#include <QVector>
#include <QGraphicsView>
#include "snakebase.h"
#include "mode.h"

class Snake : protected SnakeBase
{
public:
    explicit Snake(QGraphicsView* view);

    // next is direction to Head, prev is direction from Head
    ItemSnake* getNextItem(ItemSnake *item);
    ItemSnake* getPrevItem(ItemSnake *item);
private:
    QGraphicsView* view;
    QVector<ItemSnake*> body;
};



#endif // SNAKE_H
