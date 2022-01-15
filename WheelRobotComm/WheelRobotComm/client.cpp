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
    char single_char[30];
    QString msg;
    qint64 numberOfBytes = SocketDesc->bytesAvailable();

    if(numberOfBytes > 0)
    {
        input.readRawData(single_char,numberOfBytes);
        msg.append(single_char);
    }
    emit ReadDone(msg);
//    if(SocketDesc->bytesAvailable())
//    {
//        input.readRawData(single_char,1);
//        msg.append(*single_char);

//        if(*single_char == '\n')
//        {
//            emit ReadDone(QString(msg));
//        }
//    }


    //in.setVersion(QDataStream::Qt_5_10);
    //    while(1)
    //    {
    //        if (!NextBlockSize)
    //        {
    //            if (SocketDesc->bytesAvailable() < sizeof(uint16_t)) { break; }
    //            input >> NextBlockSize;
    //        }

    //        if (SocketDesc->bytesAvailable() < NextBlockSize) { break; }


    //       char msg[4];
    //        input.readRawData(msg, 4);
    //  QString str(msg);
    //        //input >> str;

    //        if (str == "0")
    //        {
    //            str = "Connection closed";
    //            ClientDisconnect();
    //        }

    //        emit ReadDone( str);
    //        NextBlockSize = 0;
    //    }

}

bool Client::SetIP(QString _ip)
{

    ConnectionStatus = false;

    HostAddr = _ip;

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

