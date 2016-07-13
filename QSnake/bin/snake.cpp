#include "Include/snake.h"

Snake::Snake(QGraphicsView *view)
{
    ItemSnake* head = new ItemSnake(this,100,100,Mode::Head,0);
    ItemSnake* piece = new ItemSnake(this,105,105,Mode::Piece,0);

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

ItemSnake *Snake::getNextItem(ItemSnake *item)
{
    if(!body.indexOf(item)) return nullptr;
    return body.at(body.indexOf(item)-1);
}
