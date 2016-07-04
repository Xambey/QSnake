#ifndef MAPVIEW_H
#define MAPVIEW_H
#include <QtWidgets>

class MapView : public QGraphicsView
{
    Q_OBJECT
public:
    MapView(QGraphicsScene* scene, QWidget* wgt = 0);
};

#endif // MAPVIEW_H
