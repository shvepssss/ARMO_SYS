#include "server.h"

Server::Server()
{
    // принимаем сигналы с любого адреса, прослушиваем порт 2324
    this->listen(QHostAddress::Any, 2324);

    // инициализация
    countConnections = 0;
}

/* при отключении клиента */
void Server::disconnected()
{
    // уменьшаем кол-во подключений
    countConnections--;
    // и удаляем сокет
    delete  socket;
}

/* обработчик новых подключений */
void Server::incomingConnection(qintptr socketDecriptor)
{
    // по тз узла должно быть 2 -> подключение 1
    if(countConnections ==0)
    {
        // сокет для чтения картинки
        socket = new QTcpSocket;
        // устанавливаем в сокет дескриптор(нетрицательное число, идентифицирующее поток ввода-вывода)
        socket->setSocketDescriptor(socketDecriptor);
        // объединяем сигналы и слоты
        connect(socket, &QTcpSocket::readyRead, this, Server::readyRead);
        connect(socket, &QTcpSocket::disconnected, this, Server::disconnected);
        // считаем подключения
        countConnections++;
    }
    else
    {
        // сообщаем об ошибке
        QMessageBox msgBox;
        msgBox.setText(errorConnections);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
    }
}

/* чтение сообщений */
void Server::readyRead()
{
    // читаем именно тот сокет, с которого пришел запрос
    socket = (QTcpSocket*)sender();

    // ждем, когда все данные придут до конца
    socket->waitForReadyRead();

    // считали данные сокета
    QByteArray contents=socket->readAll();

    // получаем изображение
    QPixmap pix;
    pix.loadFromData(contents);
    pix.scaled(1200,1200,Qt::KeepAspectRatio,Qt::SmoothTransformation);

    // если картинка есть
    if(!pix.isNull())
    {
        // отправляем сигнал, что получили картинку
        emit sendPixmap(pix);
    }
}

