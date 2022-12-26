#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // создаём сервер
    ser = new Server;
    // объединяем сигналы и слоты
    connect(ser, &Server::sendPixmap, this, MainWindow::setPixmap);

    // создаём сцену
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene); // устанавливаем сцену
}

// установка картинки
void MainWindow::setPixmap(QPixmap pix)
{
    // очищаем сценц для новой картинк
    scene->clear();
    // устанавливаем новую картинку
    scene->addPixmap(pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}


