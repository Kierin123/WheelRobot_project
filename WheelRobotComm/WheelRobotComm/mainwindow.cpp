#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButtonDisconnect->setVisible(false);
    ui->pushButtonConnect->setVisible(true);

    client = new Client("192.168.2.100", 5050);

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
    QString str = ui->lineEditSend->text();
    QDataStream output(client->SocketDesc);

    output.writeRawData(str.toStdString().c_str(), 30);

//    ui->textEditComm->append(QString("Send!"));

}

void MainWindow::on_pushButtonSearch_clicked()
{
    quint8 _ipNumber = 0;
    QString received_message;

    QString _ip = ui->lineEditIP->text() + "." \
            + ui->lineEditIP_2->text() + "." + ui->lineEditIP_3->text() \
            + "." + QString::number(_ipNumber);


    client->SetIP(_ip);
    while(_ipNumber < 255)
    {
        client->ClientConnect();
        if(client->GetStatus() == true)
        {
            ui->labelSearch->setText(_ip);
            break;
        }

        _ipNumber++;
        QString _ip = ui->lineEditIP->text() + "." \
                + ui->lineEditIP_2->text() + "." + ui->lineEditIP_3->text() \
                + "." + QString::number(_ipNumber);


        client->SetIP(_ip);

    }

    client->ClientDisconnect();


}
