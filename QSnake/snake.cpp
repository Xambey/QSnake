#include "snake.h"

Snake::Snake(QGraphicsScene& scene) : scene(scene)
{
    //for(int i = 0; i < 3; i++) {
       ItemSnake* t = new ItemSnake(scene,CommonDate::TurnLeftUp);
        scene.addWidget(t);
        t->move(100, 100);
    //}
}
