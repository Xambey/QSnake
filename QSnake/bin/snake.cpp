#include "Include/snake.h"

Snake::Snake(QGraphicsView *view)
{
    ItemSnake* head = new ItemSnake(this,100,100,Mode::Head,0);
    body.push_back(head);
    view->scene()->addItem(head);
    ItemSnake* piece = new ItemSnake(this,105,105,Mode::Piece,0);
    body.push_back(piece);
    view->scene()->addItem(piece);

    //head->moveBy(100,100);
    piece->moveBy(100,102);
}

//right to body
ItemSnake* Snake::getNextItem(ItemSnake *item)
{
    if(body.indexOf(item) == body.size()-1) return nullptr;
    return body.at(body.indexOf(item)+1);
}

//left to body
ItemSnake *Snake::getPrevItem(ItemSnake *item)
{
    if(!body.indexOf(item)) return nullptr;
    return body.at(body.indexOf(item)-1);
}
