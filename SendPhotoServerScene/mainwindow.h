#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <server.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    Server *ser; // сервер
    QGraphicsScene *scene; // сцена для картинки
public slots:
    void setPixmap(QPixmap pix); // установка картинки
};

#endif // MAINWINDOW_H
