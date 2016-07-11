#include "snake.h"

Snake::Snake(QGraphicsView *view)
{
    ItemSnake* head = new ItemSnake(20,this);
    ItemSnake* piece = new ItemSnake(this);

    view->scene()->addItem(head);
    view->scene()->addItem(piece);
    head->moveBy(100,100);
    piece->moveBy(100,102);
}

ItemSnake* Snake::getPrevItem(ItemSnake *item)
{
    if(body.indexOf(item) == body.size()-1) return nullptr;
    return body.at(body.indexOf(item)+1);
}
