#include "snake.h"

Snake::Snake(QGraphicsScene& scene) : scene(scene)
{
    scene.setSceneRect(0,0,800,800);
    //for(int i = 0; i < 3; i++) {
        ItemSnake* t = new ItemSnake(scene,90,body);
        scene.addItem(t);
        t->moveBy(100,100);
        //}
}
