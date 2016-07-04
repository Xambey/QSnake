#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QVector>
#include "itemsnake.h"
class ItemSnake;
class Snake : public QWidget
{
    Q_OBJECT
public:
    explicit Snake(QGraphicsScene& scene);
private:
    QGraphicsScene& scene;
    QVector<ItemSnake*> body;
};

#endif // SNAKE_H
