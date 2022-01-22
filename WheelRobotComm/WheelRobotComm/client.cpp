#include "client.h"

Client::Client( const QString _HostAddr,
                int _PortNum ,
                QObject *parent) : QObject(parent)
{
    ConnectionStatus = false;

    HostAddr = _HostAddr;
    PortNum = _PortNum;

    SocketDesc = new QTcpSocket(this);

    connect(SocketDesc, &QTcpSocket::disconnected, this, &Client::ClientDisconnect);

    timeoutConnection = new QTimer();
    timeoutConnection->setSingleShot(true);

    connect(timeoutConnection, &QTimer::timeout, this, &Client::ConnectionTimeout);

}

void Client::ClientConnect()
{
    timeoutConnection->start(300);

    SocketDesc->connectToHost(HostAddr,PortNum);

    connect(SocketDesc, &QTcpSocket::connected, this, &Client::Connected);
    connect(SocketDesc, &QTcpSocket::readyRead, this, &Client::ReadyToRead);
}

void Client::ConnectionTimeout()
{

    if (SocketDesc->state() == QAbstractSocket::ConnectingState)
    {
        SocketDesc->abort();
        emit SocketDesc->error(QAbstractSocket::SocketTimeoutError);
    }
}

void Client::Connected()
{
    ConnectionStatus = true;
    emit StatusChanged(ConnectionStatus);
}

bool Client::GetStatus()
{
    return ConnectionStatus;
}

void Client::ReadyToRead()
{
    QDataStream input(SocketDesc);
    QString msg;
    qint64 numberOfBytes = SocketDesc->bytesAvailable();
    char singleChar = 0;

    while(numberOfBytes >= 0)
    {
        input.readRawData(&singleChar,1);
        if(singleChar != '\n')
            msg.append(singleChar);
        numberOfBytes--;
    }
    emit ReadDone(msg);
}

bool Client::SetIP(QString _ip, int _port)
{

    ConnectionStatus = false;

    HostAddr = _ip;
    PortNum = _port;

    SocketDesc = new QTcpSocket(this);

    connect(SocketDesc, &QTcpSocket::disconnected, this, &Client::ClientDisconnect);

    return 0;
}






void Client::ClientDisconnect()
{
    timeoutConnection->stop();

    //qDebug() << tcpSocket->state();
    disconnect(SocketDesc, &QTcpSocket::connected, 0, 0);
    disconnect(SocketDesc, &QTcpSocket::readyRead, 0, 0);

    bool shouldEmit = false;
    switch (SocketDesc->state())
    {
    case QAbstractSocket::UnconnectedState:
        SocketDesc->disconnectFromHost();
        shouldEmit = true;
        break;
    case QAbstractSocket::ConnectingState:
        SocketDesc->abort();
        shouldEmit = true;
        break;
    default:
        SocketDesc->abort();
    }

    if (shouldEmit)
    {
        ConnectionStatus = false;
        emit StatusChanged(ConnectionStatus);
    }
}

