#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // сокет для передачи данных
    socket = new QTcpSocket(this);
    // объединяем сигналы и слоты
    connect(socket, &QTcpSocket::disconnected, this, MainWindow::deleteLater);

    // запрещаем отправлять картинки, пока не подключились к серверу
    ui->getImg->setEnabled(false);
    ui->pushButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* логика передачи картинки серверу */
void MainWindow::sendToServer(QString path)
{
    // создаём картинку из пути диалогового окна
    QPixmap pix = QPixmap(path);

    // проверяем, получили ли изображение
    if(pix.isNull())
    {
        // сообщаем об ошибке
        QMessageBox msgBox;
        msgBox.setText(noFile);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
    // начинаем преобразования картинки в массив байтов
    else
    {
        // создаем массив байт для картинки
        QByteArray bytes;
        bytes.clear();
        QBuffer buffer(&bytes);// перемещаем картинку в массив с помощью буффера
        buffer.open(QIODevice::WriteOnly);
        // передаем массив данных, расширение картинки
        QString format = path.mid(path.length()-3,3).toUpper();
        QByteArray ba = format.toLocal8Bit();
        char *c_str2 = ba.data();
        // преобразование картинки в массив байтов
        pix.save(&buffer, c_str2);
        // закрыли буфер
        buffer.close();
        // создаем отдельный массив байтов для работы с QDataStream
        QByteArray databuf;
        QDataStream out(&databuf, QIODevice::WriteOnly);
        // обязательно почистили
        databuf.clear();
        // добавили фиксированный размер quint32 (4 байта) и нашу картинку
        out<<quint32(0)<<bytes;
        // перешли через QDataStream в начало байтового массива databuf
        out.device()->seek(0);
        // вместо 0 записали в зарезервированной области массива размер отправляемого
        // массива для считывания на сервере
        out << (quint32)databuf.size()-sizeof(quint32);
        // отправили данные
        socket->write(databuf);
        // ждем, когда все данные придут до конца
        socket->waitForBytesWritten();
        // очистили поле пути к картинке
        ui->lineEdit->clear();
    }
}

// отправка картинки при нажатии кнопки
void MainWindow::on_pushButton_clicked()
{
    sendToServer(ui->lineEdit->text());
}

/* при нажатии кнопки connect подключаемся к серверу */
void MainWindow::on_pushButton_2_clicked()
{
    // если ip сервера не указан - ругаемся
    if ((ui->lineIpAdress->text()).trimmed() == "")
    {
        // сообщаем об ошибке
        QMessageBox msgBox;
        msgBox.setText(errorIP);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
    else
    {
        // подключаемся к серверу
        socket->connectToHost(ui->lineIpAdress->text(), 2324);
        // запрещаем повторное подключение
        ui->pushButton_2->setEnabled(false);
        // разрешаем отправлять картинки, после подключения к серверу
        ui->getImg->setEnabled(true);
        ui->pushButton->setEnabled(true);
    }
}

/* выбор изображения */
void MainWindow::on_getImg_clicked()
{
    QString path; // путь до файла
    // открываем диалоговое окно
    path = QFileDialog::getOpenFileName(this, tr("Open File"),
                                           "/home",
                                           tr("Images (*.png *.bmp *.jpg)"));
    // отображаем путь
    ui->lineEdit->setText(path);
}
