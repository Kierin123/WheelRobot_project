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
    timeoutConnection->start(5000);

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

    //in.setVersion(QDataStream::Qt_5_10);
    while(1)
    {
        if (!NextBlockSize)
        {
            if (SocketDesc->bytesAvailable() < sizeof(uint16_t)) { break; }
            input >> NextBlockSize;
        }

        if (SocketDesc->bytesAvailable() < NextBlockSize) { break; }

        QString str;
        input >> str;

        if (str == "0")
        {
            str = "Connection closed";
            ClientDisconnect();
        }

        emit ReadDone(str);
        NextBlockSize = 0;
    }

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

