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

    Snake snake(*scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}


void MainWindow::resizeEvent(QResizeEvent *)
{

    ui->graphicsView->setSceneRect(QRectF(0,0,ui->centralWidget->width()-30,ui->centralWidget->height()-60));
    ui->graphicsView->resize(ui->centralWidget->width()-10,ui->centralWidget->height() - 40);
    ui->centralWidget->setLayout(ui->verticalLayout);
    //    QSizePolicy policy;
//    policy.setHorizontalPolicy(QSizePolicy::Expanding);
//    policy.setVerticalPolicy(QSizePolicy::Expanding);

//    ui->centralWidget->setSizePolicy(policy);
//    ui->graphicsView->setSizePolicy(policy);
    //ui->graphicsView->fitInView(scene->sceneRect());
    //ui->graphicsView->setSizePolicy(QSizePolicy(2));
    //ui->graphicsView->setSceneRect(300,300,ui->graphicsView->width(),ui->graphicsView->height());
}
