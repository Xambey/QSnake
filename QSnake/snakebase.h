#pragma once
#ifndef SNAKEBASE_H
#define SNAKEBASE_H

#include "itemsnake.h"

class SnakeBase
{
public:
    virtual ItemSnake* getPrevItem(ItemSnake* item) = 0;
};

#endif // SNAKEBASE_H
