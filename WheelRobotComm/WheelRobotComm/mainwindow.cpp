#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <qfilesystemmodel.h>
#include <qtreeview.h>
#include <QDir>
#include <QDebug>

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
    //    answer = msg;
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


//####################################################
//          EDIT commands
//####################################################

void MainWindow::on_pushButtonForwardDistance_clicked()
{
    AddCommandToVector(FORWARD_DISTANCE, ui->lineEditDistance->text());
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());
}

void MainWindow::on_pushButtonBackwardDistance_clicked()
{
    AddCommandToVector(BACKWARD_DISTANCE, ui->lineEditDistance->text());
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());
}

void MainWindow::on_pushButtonTurnLeft_clicked()
{
    AddCommandToVector(TURN_LEFT, QString("000"));
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());
}

void MainWindow::on_pushButtonTurnRight_clicked()
{
    AddCommandToVector(TURN_RIGHT, QString("000"));
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());
}

void MainWindow::on_pushButtonMotorRight_clicked()
{
    AddCommandToVector(MOTOR_RIGHT, ui->lineEditSpeed->text());
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());
}

void MainWindow::on_pushButtonMotorLeft_clicked()
{
    AddCommandToVector(MOTOR_LEFT, ui->lineEditSpeed->text());
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());
}

void MainWindow::on_pushButtonStop_clicked()
{

    AddCommandToVector(STOP, QString("000"));
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());

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
        SendData(var.getCommand().toStdString().c_str(), strlen(var.getCommand().toStdString().c_str()));
    }
    CommandVect.clear();
    ui->listWidget->clear();

}

void MainWindow::on_pushButtonArcLeft_clicked()
{
    AddCommandToVector(ARC_LEFT, ui->lineEditArc->text());
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());
}

void MainWindow::on_pushButtonArcRight_clicked()
{
    AddCommandToVector(ARC_RIGHT, ui->lineEditArc->text());
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());
}

void MainWindow::AddCommandToVector(char prefixCommand, QString valueCommand)
{
    Command temporaryCommand;
    QString nameToAdd = "";
    QString commandToAdd = "";
    for (auto commandArrayIt : availableCommandArray) {
        if(prefixCommand == commandArrayIt.getCommand()[0])
        {
            nameToAdd = commandArrayIt.getCommandName();
            commandToAdd += prefixCommand + valueCommand + ",";
            break;
        }
    }
    temporaryCommand.setCommand(commandToAdd);
    temporaryCommand.setCommandName(nameToAdd);
    CommandVect.pushBack(temporaryCommand);
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButtonLoadFile_clicked()
{
    QByteArray readLineFromFile;
    QMessageBox msgBox;
    Command TemporaryCommand;

    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Command sequence"), "",
                                                    tr("All Files (*)"));
    if (fileName.isEmpty())
    {
        return;
    }
    else {

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }
        while(!file.atEnd())
        {
            readLineFromFile = file.readLine(6);
            TemporaryCommand = isCommandAvailable(readLineFromFile);
            if(!TemporaryCommand.isEmpty())
            {

                ui->listWidget->addItem(TemporaryCommand.getCommandName());
                CommandVect.pushBack(TemporaryCommand);
            }
        }
    }
}

void MainWindow::on_pushButtonSaveFile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Address Book"), "",
                                                    tr("All Files (*)"));

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }
        for (auto commandIndex : CommandVect) {
            file.write(commandIndex.getCommand().toStdString().c_str(), commandIndex.getCommand().toStdString().length());
            file.write("\n",1);
        }
    }
}

Command MainWindow::isCommandAvailable(QString inputString)
{
    for (auto arrayIndex : availableCommandArray) {
        if(inputString[0] == arrayIndex.getCommand())
        {
            if(checkIfNumericOnPlace(inputString,1) &&  checkIfNumericOnPlace(inputString,2) && checkIfNumericOnPlace(inputString,3))
            {
                if(checkColonOnPlace(inputString,4))
                {
                    return Command(inputString, arrayIndex.getCommandName());
                } else{}
            } else{}
        } else{}

    }
    return Command("","");
}

bool MainWindow::checkIfNumericOnPlace(QString strToCheck, quint32 positionToCheck)
{
    bool output = false;
    if(strToCheck.isEmpty())
    {
        output = false;
    } else if(strToCheck.at(positionToCheck).isDigit())
    {
        output = true;
    }
    return output;
}

bool MainWindow::checkColonOnPlace(QString strToCheck, quint32 positionToCheck)
{
    bool output = false;
    if(strToCheck.isEmpty())
    {
        output = false;
    } else if(strToCheck.at(positionToCheck) == ',')
    {
        output = true;
    }
    return output;
}

//void MainWindow::clearCommandVector()
//{
//    CommandVect.clear();
//    ui->listWidget->clear();
//}

void MainWindow::on_pushButtonClearCommand_clicked()
{
//    clearCommandVector();
    CommandVect.clear();
    ui->listWidget->clear();
}

void MainWindow::on_pushButtonMotorLeftFactor_clicked()
{
    AddCommandToVector(CHANGE_FAKTOR_L, ui->lineEditFactor->text());
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());
}

void MainWindow::on_pushButtonMotorRightFactor_clicked()
{
    AddCommandToVector(CHANGE_FAKTOR_R, ui->lineEditFactor->text());
    ui->listWidget->addItem(CommandVect.getLast().getCommandName());
}
