#ifndef SNAKE_H
#define SNAKE_H

#include <QWidget>
#include <QVector>
#include "itemsnake.h"
#include "direction.h"

class Snake : public QWidget, public CommonDate
{
    Q_OBJECT
public:
    explicit Snake(QGraphicsScene& scene);
private:
    QGraphicsScene& scene;
    QVector<ItemSnake*> body;
    CommonDate::Direction direction;
};

#endif // SNAKE_H
