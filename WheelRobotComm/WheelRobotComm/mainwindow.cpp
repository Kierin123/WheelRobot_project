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

void MainWindow::on_pushButtonSearch_clicked()
{

}

//####################################################
//          EDIT commands
//####################################################

void MainWindow::on_pushButtonForwardDistance_clicked()
{
    Command TemporaryCommand;
    QString StrCommand;
    StrCommand.push_back(FORWARD_DISTANCE);
    StrCommand.push_back( ui->lineEditDistance->text());
    StrCommand.push_back(',');
    TemporaryCommand.CommandToSend = StrCommand;
    TemporaryCommand.CommandName = ("Forward " + ui->lineEditDistance->text() + " mm");
    CommandVect.push_back(TemporaryCommand);
    ui->listWidget->addItem((CommandVect.end()-1)->CommandName);
}

void MainWindow::on_pushButtonBackwardDistance_clicked()
{
    Command TemporaryCommand;
    QString StrCommand;
    StrCommand.push_back(BACKWARD_DISTANCE);
    StrCommand.push_back( ui->lineEditDistance->text());
    StrCommand.push_back(',');
    TemporaryCommand.CommandToSend = StrCommand;
    TemporaryCommand.CommandName = ("Backward " + ui->lineEditDistance->text() + " mm");
    CommandVect.push_back(TemporaryCommand);
    ui->listWidget->addItem((CommandVect.end()-1)->CommandName);
}

void MainWindow::on_pushButtonForwardSpeed_clicked()
{

}

void MainWindow::on_pushButtonBackwardSpeed_clicked()
{

}

void MainWindow::on_pushButtonTurnLeft_clicked()
{
    Command TemporaryCommand;
    QString StrCommand;
    StrCommand.push_back(TURN_LEFT);
    StrCommand.push_back("000,");
    TemporaryCommand.CommandToSend = StrCommand;
    TemporaryCommand.CommandName = ("Rotate Left");
    CommandVect.push_back(TemporaryCommand);
    ui->listWidget->addItem((CommandVect.end()-1)->CommandName);

}

void MainWindow::on_pushButtonTurnRight_clicked()
{
    Command TemporaryCommand;
    QString StrCommand;
    StrCommand.push_back(TURN_RIGHT);
    StrCommand.push_back("000,");
    TemporaryCommand.CommandToSend = StrCommand;
    TemporaryCommand.CommandName = ("Rotate right");
    CommandVect.push_back(TemporaryCommand);
    ui->listWidget->addItem((CommandVect.end()-1)->CommandName);

}

void MainWindow::on_pushButtonMotorRight_clicked()
{
    Command TemporaryCommand;
    QString StrCommand;
    StrCommand.push_back(MOTOR_RIGHT);
    StrCommand.push_back(ui->lineEditSpeed->text());
    StrCommand.push_back(',');
    TemporaryCommand.CommandToSend = StrCommand;
    TemporaryCommand.CommandName = ("Motor Right " + ui->lineEditSpeed->text());
    CommandVect.push_back(TemporaryCommand);
    ui->listWidget->addItem((CommandVect.end()-1)->CommandName);

}

void MainWindow::on_pushButtonMotorLeft_clicked()
{
    Command TemporaryCommand;
    QString StrCommand;
    StrCommand.push_back(MOTOR_LEFT);
    StrCommand.push_back(ui->lineEditSpeed->text());
    StrCommand.push_back(',');
    TemporaryCommand.CommandToSend = StrCommand;
    TemporaryCommand.CommandName = ("Motor Left " + ui->lineEditSpeed->text());
    CommandVect.push_back(TemporaryCommand);
    ui->listWidget->addItem((CommandVect.end()-1)->CommandName);

}

void MainWindow::on_pushButtonStop_clicked()
{
    Command TemporaryCommand;
    QString StrCommand;
    StrCommand.push_back(STOP);
    StrCommand.push_back("000,");
    TemporaryCommand.CommandToSend = StrCommand;
    TemporaryCommand.CommandName = "Stop";
    CommandVect.push_back(TemporaryCommand);
    ui->listWidget->addItem((CommandVect.end()-1)->CommandName);

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
        SendData(var.CommandToSend.toStdString().c_str(), strlen(var.CommandToSend.toStdString().c_str()));
        //        SendData(var.toStdString().c_str(), strlen(var.toStdString().c_str()));
    }
    CommandVect.clear();
    ui->listWidget->clear();

}

void MainWindow::on_pushButtonArcLeft_clicked()
{
    Command TemporaryCommand;
    QString StrCommand;
    StrCommand.push_back(ARC_LEFT);
    StrCommand.push_back(ui->lineEditArc->text());
    StrCommand.push_back(",");
    TemporaryCommand.CommandToSend = StrCommand;
    TemporaryCommand.CommandName = ("Arc left " + ui->lineEditArc->text() + " deg");
    CommandVect.push_back(TemporaryCommand);
    ui->listWidget->addItem((CommandVect.end()-1)->CommandName);

}

void MainWindow::on_pushButtonArcRight_clicked()
{
    Command TemporaryCommand;
    QString StrCommand;
    StrCommand.push_back(ARC_RIGHT);
    StrCommand.push_back(ui->lineEditArc->text());
    StrCommand.push_back(",");
    TemporaryCommand.CommandToSend = StrCommand;
    TemporaryCommand.CommandName = ("Arc right " + ui->lineEditArc->text() + " deg");
    CommandVect.push_back(TemporaryCommand);
    ui->listWidget->addItem((CommandVect.end()-1)->CommandName);
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
                CommandVect.push_back(TemporaryCommand);
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
                    return Command(arrayIndex.getCommand(), arrayIndex.getCommandName());
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

void MainWindow::clearCommandVector()
{
    CommandVect.clear();
    ui->listWidget->clear();
}

void MainWindow::on_pushButtonClearCommand_clicked()
{
    clearCommandVector();
}
