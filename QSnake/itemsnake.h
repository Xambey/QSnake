#ifndef ITEMSNAKE_H
#define ITEMSNAKE_H

#include <QAbstractItemModel>
#include <QtWidgets>
#include "direction.h"
#include "snake.h"

class ItemSnake : public QWidget
{
    Q_OBJECT
public:
    int GetAngle();
    void SetAngleItem(int angle);

    explicit ItemSnake(QGraphicsScene& scene);
    ItemSnake(QGraphicsScene& scene, int startAngle, QVector<ItemSnake*>& body);
private:
    void RotateItem(int angle);
    void SetAnglePrevItem();
    const int rate;
    const int length;
    int index;
    int angle;
    QGraphicsScene& scene;
    QVector<ItemSnake*>* body;
    QPainter* painter;
protected:
    void RenderMode(); //render item on the mode
    void paintEvent(QPaintEvent*);
};

#endif // ITEMSNAKE_H
