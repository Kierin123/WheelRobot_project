#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    client = new Client("localhost", 5050);

    connect(client, &Client::ReadDone, this, &MainWindow::ReceivedData);
    connect(client, &Client::StatusChanged, this, &MainWindow::LabelStatusChange);
}


MainWindow::~MainWindow()
{
    delete client;
    delete ui;
}

void MainWindow::LabelStatusChange(int status)
{
    if (status)
    {
        ui->labelStatus->setText("Connected");
        ui->pushButtonConnect->setVisible(false);
        ui->pushButtonDisconnect->setVisible(true);
    }
    else
    {
        ui->labelStatus->setText("Disconnected");
        ui->pushButtonConnect->setVisible(true);
        ui->pushButtonDisconnect->setVisible(false);
    }
}

void MainWindow::ReceivedData(QString msg)
{
    ui->textEditComm->append(msg);
}

void MainWindow::GotError(QAbstractSocket::SocketError error)
{
    //qDebug() << "got error";
    QString strError = "unknown";
    switch (error)
    {
        case 0:
            strError = "Connection was refused";
            break;
        case 1:
            strError = "Remote host closed the connection";
            break;
        case 2:
            strError = "Host address was not found";
            break;
        case 5:
            strError = "Connection timed out";
            break;
        default:
            strError = "Unknown error";
    }

    ui->textEditComm->append(strError);
}

void MainWindow::on_pushButtonConnect_clicked()
{
    client->ClientConnect();
}


void MainWindow::on_pushButtonDisconnect_clicked()
{
    client->ClientDisconnect();
}


void MainWindow::on_pushButtonSend_clicked()
{
    QByteArray arrBlock;
    QDataStream output(&arrBlock, QIODevice::WriteOnly);

    output << quint16(0) << ui->lineEditSend->text();

    output.device()->seek(0);
    output << quint16(arrBlock.size() - sizeof (quint16));
    client->SocketDesc->write(arrBlock);
}
