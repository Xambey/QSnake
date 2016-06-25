#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene scene(0,0,700,700, this);
    scene.addRect(100,100,100,100,QPen(QColor(Qt::yellow)),QBrush(Qt::HorPattern));
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setBaseSize(QSize(700,700));
}

MainWindow::~MainWindow()
{
    delete ui;
}
