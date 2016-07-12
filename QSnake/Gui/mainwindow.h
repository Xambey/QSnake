#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include "Include/snake.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Snake* snake;
protected:
    void resizeEvent(QResizeEvent*);
};

#endif // MAINWINDOW_H
