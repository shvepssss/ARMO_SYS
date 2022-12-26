#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QFileDialog>
#include <QBuffer>

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
    // сообщения об ошибках
    const QString errorIP="Укажите ip адрес сервера!";
    const QString noFile="Не удалось получить изображение, укажите путь заново!";

    Ui::MainWindow *ui;
    QTcpSocket *socket; // сокет для передачи данный
    void sendToServer(QString path); // отправка картинки на сервер
private slots:
    // отправка сообщения
    void on_pushButton_clicked();
    // подключение к серверу
    void on_pushButton_2_clicked();
    /* выбор изображения */
    void on_getImg_clicked();
};

#endif // MAINWINDOW_H
