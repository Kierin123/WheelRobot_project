#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QTimer>
#include <QDataStream>
#include <QTcpSocket>


class Client : public QObject
{
    Q_OBJECT

    QString HostAddr;
    int PortNum;
    uint16_t NextBlockSize;
    QTimer *timeoutConnection;

public:
    bool ConnectionStatus;

    Client(const QString _HostAddr, int _PortNum ,QObject *parent = nullptr);

    QTcpSocket *SocketDesc;
    bool GetStatus();
    bool SetIP(QString _ip, int _port);

signals:
    void StatusChanged(bool);
    void ReadDone(QString _message);

public slots:
    void ClientDisconnect();
    void ClientConnect();

private slots:
    void ReadyToRead();
    void Connected();
    void ConnectionTimeout();


};

#endif // CLIENT_H
