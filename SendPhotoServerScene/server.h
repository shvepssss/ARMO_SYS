#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QPixmap>
#include <QString>
#include <QMessageBox>

class Server:public QTcpServer
{
    Q_OBJECT // т.к. используем сигнально-слотовые связи

public:
    Server();
    // сообщения об ошибках
    const QString errorConnections = "Подключение может быть лишь 1 так как приложение по тз должно работать на 2х узлах!";

    // сокет для получения картинки
    QTcpSocket *socket;
private:
    unsigned countConnections; // количество подключений
    quint32 m_blockSize; // размер получаемых данных
public slots:
    void incomingConnection(qintptr socketDecriptor); // обработчик новых подключений
    void readyRead(); // обработчик полученных от клиента сообщений
    void disconnected(); // обработчик отключения клиента
signals:
  /* сигнал об отправленном изображении */
  void sendPixmap(QPixmap pix);
};

#endif // SERVER_H
