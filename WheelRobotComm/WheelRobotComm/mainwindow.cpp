#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButtonDisconnect->setVisible(false);
    ui->pushButtonConnect->setVisible(true);

    client = new Client("192.168.0.57", 5050);

    connect(client, &Client::ReadDone, this, &MainWindow::ReceivedData);
    connect(client, &Client::StatusChanged, this, &MainWindow::LabelStatusChange);

    CommandObj[0] = "";

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
    answer = msg;
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
    if ((!ui->lineEditPort->text().isEmpty()) && (!ui->lineEditPort->text().isEmpty())) {
        QString _ipAddress = ui->lineEditIP1->text();
        int _port = ui->lineEditPort->text().toInt();
        client->SetIP(_ipAddress, _port);
        client->ClientConnect();
    }
}


void MainWindow::on_pushButtonDisconnect_clicked()
{
    client->ClientDisconnect();
}

void MainWindow::on_pushButtonSend_clicked()
{
    QString str = ui->lineEditSend->text();
    QDataStream output(client->SocketDesc);

    output.writeRawData(str.toStdString().c_str(), strlen(str.toStdString().c_str()));
}

void MainWindow::on_pushButtonSearch_clicked()
{

}

//####################################################
//          EDIT commands
//####################################################

void MainWindow::on_pushButtonForwardDistance_clicked()
{
    QString StrCommand = ui->lineEditForwardDisctance->text();
    StrCommand.push_front(FORWARD_DISTANCE);
    StrCommand.push_back(',');
//    CommandObj[lastCommandID] = StrCommand;
    CommandVect.push_back(StrCommand);
    ui->listWidget->addItem(*(CommandVect.end()-1));

//    ui->listWidget->addItem((CommandObj[lastCommandID]));
    lastCommandID++;
}

void MainWindow::on_pushButtonBackwardDistance_clicked()
{
    QString StrCommand = ui->lineEditBackwardDistance->text();
    StrCommand.push_front(BACKWARD_DISTANCE);
    StrCommand.push_back(',');
//    static int lastCommandID = CommandObj.end()->first;
//    CommandObj[lastCommandID] = StrCommand;
    CommandVect.push_back(StrCommand);
    ui->listWidget->addItem(*(CommandVect.end()-1));


//    ui->listWidget->addItem((CommandObj[lastCommandID]));
    lastCommandID++;
}

void MainWindow::on_pushButtonForwardSpeed_clicked()
{
    QString StrCommand = ui->lineEditForwardSpeed->text();
    StrCommand.push_front(FORWARD_SPEED);
    StrCommand.push_back(',');
//    static int lastCommandID = CommandObj.end()->first;
//    CommandObj[lastCommandID] = StrCommand;
    CommandVect.push_back(StrCommand);
    ui->listWidget->addItem(*(CommandVect.end()-1));

//    ui->listWidget->addItem((CommandObj[lastCommandID]));
    lastCommandID++;
}

void MainWindow::on_pushButtonBackwardSpeed_clicked()
{
    QString StrCommand = ui->lineEditBackwardSpeed->text();
    StrCommand.push_front(BACKWARD_SPEED);
    StrCommand.push_back(',');
//    static int lastCommandID = CommandObj.end()->first;
//    CommandObj[lastCommandID] = StrCommand;
    CommandVect.push_back(StrCommand);
    ui->listWidget->addItem(*(CommandVect.end()-1));

//    ui->listWidget->addItem((CommandObj[lastCommandID]));
    lastCommandID++;
}

void MainWindow::on_pushButtonTurnLeft_clicked()
{
    QString StrCommand = "000";
    StrCommand.push_front(TURN_LEFT);
    StrCommand.push_back(',');
//    static int lastCommandID = CommandObj.end()->first;
//    CommandObj[lastCommandID] = StrCommand;
    CommandVect.push_back(StrCommand);
    ui->listWidget->addItem(*(CommandVect.end()-1));

//    ui->listWidget->addItem((CommandObj[lastCommandID]));
    lastCommandID++;
}

void MainWindow::on_pushButtonTurnRight_clicked()
{
    QString StrCommand = "000";
    StrCommand.push_front(TURN_RIGHT);
    StrCommand.push_back(',');
//    static int lastCommandID = CommandObj.end()->first;
//    CommandObj[lastCommandID] = StrCommand;
    CommandVect.push_back(StrCommand);
    ui->listWidget->addItem(*(CommandVect.end()-1));

//    ui->listWidget->addItem((CommandObj[lastCommandID]));
    lastCommandID++;
}

void MainWindow::on_pushButtonMotorRight_clicked()
{
    QString StrCommand = ui->lineEditMotorRight->text();
    StrCommand.push_front(MOTOR_RIGHT);
    StrCommand.push_back(',');
//    static int lastCommandID = CommandObj.end()->first;
//    CommandObj[lastCommandID] = StrCommand;
    CommandVect.push_back(StrCommand);
    ui->listWidget->addItem(*(CommandVect.end()-1));

//    ui->listWidget->addItem((CommandObj[lastCommandID]));
    lastCommandID++;
}

void MainWindow::on_pushButtonMotorLeft_clicked()
{
    QString StrCommand = ui->lineEditMotorLeft->text();
    StrCommand.push_front(MOTOR_LEFT);
    StrCommand.push_back(',');
//    static int lastCommandID = CommandObj.end()->first;
//    CommandObj[lastCommandID] = StrCommand;
    CommandVect.push_back(StrCommand);
    ui->listWidget->addItem(*(CommandVect.end()-1));

//    ui->listWidget->addItem((CommandObj[lastCommandID]));
    lastCommandID++;
}

void MainWindow::on_pushButtonStop_clicked()
{
    QString StrCommand;

    StrCommand.push_front(STOP);
    StrCommand.push_back(',');
//    static int lastCommandID = CommandObj.end()->first;
//    CommandObj[lastCommandID] = StrCommand;
    CommandVect.push_back(StrCommand);
    ui->listWidget->addItem((*CommandVect.end()));

//    ui->listWidget->addItem((CommandObj[lastCommandID]));
    lastCommandID++;
}

void MainWindow::SendData(const char* data, int len)
{
    QDataStream outputStream(client->SocketDesc);
    outputStream.writeRawData(data,len);

}

void MainWindow::on_pushButtonSend_2_clicked()
{
    QString CommandOutput;
    QDataStream outputStream(client->SocketDesc);


    for (auto &var : CommandVect) {
        //        outputStream.writeRawData(var.second.toStdString().c_str(),strlen(var.second.toStdString().c_str()));
        SendData(var.toStdString().c_str(), strlen(var.toStdString().c_str()));


//        Sleeper::msleep(2000);

    }
    CommandVect.clear();
    ui->listWidget->clear();

}


