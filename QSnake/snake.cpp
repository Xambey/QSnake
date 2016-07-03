#include "snake.h"

Snake::Snake(QGraphicsScene& scene) : scene(scene)
{
    scene.setSceneRect(0,0,800,800);
    //for(int i = 0; i < 3; i++) {
       ItemSnake* t = new ItemSnake(scene,0,body);
        scene.addWidget(t);
        t->move(100, 100);
        //}
}
