#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAutoFillBackground(true);
    ui->graphicsView->setBackgroundBrush(QBrush(QColor(216,216,216)));

//    ui->graphicsView->setSceneRect(QRectF(0,0,ui->centralWidget->width()-30,ui->centralWidget->height()-60));
//    ui->graphicsView->resize(ui->centralWidget->width()-10,ui->centralWidget->height() - 40);
//    ui->centralWidget->setLayout(ui->verticalLayout);

    scene->setSceneRect(0,0,800,800);
    snake = new Snake(ui->graphicsView);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}


void MainWindow::resizeEvent(QResizeEvent *e)
{

    ui->graphicsView->resize(ui->centralWidget->width()-20,ui->centralWidget->height() - 20);
    //ui->graphicsView->updateSceneRect(QRectF(0,0,ui->centralWidget->width()-30,ui->centralWidget->height()-30));
    ui->centralWidget->setLayout(ui->verticalLayout);
    QMainWindow::resizeEvent(e);
}
