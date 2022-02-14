#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <client.h>
#include <vector>
#include <map>
#include <chrono>
#include <ctime>
#include <ratio>
#include <QMessageBox>
#include <QFileDialog>
#include <QThread>
#include <dialogsave.h>
#include <dialogload.h>
#include <iostream>


enum
{
    FORWARD_SPEED = 'X',
    BACKWARD_SPEED = 'Z',
    STOP = 'S',
    FORWARD_DISTANCE = 'F',
    BACKWARD_DISTANCE = 'B',
    TURN_LEFT = 'L',
    TURN_RIGHT = 'R',
    MOTOR_LEFT = 'M',
    MOTOR_RIGHT = 'N',
    EXIT = 'E',
    ARC_RIGHT = 'W',
    ARC_LEFT = 'Q',
};



//const char availableCommandArray[14] = {'X','Z','S','F','B','L','R','M','N','E','H','G','W','Q'};




class Command
{

public:
    QString CommandToSend;
    QString CommandName;

    Command() : CommandToSend(""), CommandName("") {}
    Command(QString ToSend, QString Name) : CommandToSend(ToSend), CommandName(Name) {}

    QString getCommand(){return CommandToSend;}
    QString getCommandName(){return CommandName;}
    void setCommand(QString ToSend) { CommandToSend = ToSend; }
    void setCommandName(QString Name) { CommandName = Name; }
    bool isEmpty() {
        if(CommandToSend.isEmpty() || (CommandName.isEmpty()))
            return true;
        else
            return false;
    }

};

const Command availableCommandArray[] =
{
    Command(QString(FORWARD_SPEED),"Forward with speed "),
    Command(QString(BACKWARD_SPEED),"Backward with speed "),
    Command(QString(STOP),"Stop"),
    Command(QString(FORWARD_DISTANCE),"Forward by distance"),
    Command(QString(BACKWARD_DISTANCE),"Backward by distance"),
    Command(QString(TURN_LEFT),"Turn Left"),
    Command(QString(TURN_RIGHT),"Turn Right"),
    Command(QString(MOTOR_LEFT),"Motor left set speed "),
    Command(QString(MOTOR_RIGHT),"Motor right set speed "),
    Command(QString(EXIT),"Exit"),
    Command(QString(ARC_RIGHT),"Arc right by "),
    Command(QString(ARC_LEFT),"Arc left by "),
};



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void LabelStatusChange(int status);
    void ReceivedData(QString msg);
    void GotError(QAbstractSocket::SocketError error);

private slots:
    void on_pushButtonConnect_clicked();
    void on_pushButtonDisconnect_clicked();

    void on_pushButtonSend_clicked();

    void on_pushButtonSearch_clicked();

    void on_pushButtonForwardDistance_clicked();

    void on_pushButtonBackwardDistance_clicked();

    void on_pushButtonForwardSpeed_clicked();

    void on_pushButtonBackwardSpeed_clicked();

    void on_pushButtonTurnLeft_clicked();

    void on_pushButtonTurnRight_clicked();

    void on_pushButtonMotorRight_clicked();

    void on_pushButtonMotorLeft_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonSend_2_clicked();

    void on_pushButtonArcLeft_clicked();

    void on_pushButtonArcRight_clicked();

    void on_pushButton_clicked();

    void on_pushButtonLoadFile_clicked();

    void on_pushButtonSaveFile_clicked();

    void on_pushButtonClearCommand_clicked();

private:

    Ui::MainWindow *ui;
    Client *client;
    std::vector<Command> CommandVect;
//    QString answer;


//        FORWARD_SPEED = 'X',
//        BACKWARD_SPEED = 'Z',
//        STOP = 'S',
//        FORWARD_DISTANCE = 'F',
//        BACKWARD_DISTANCE = 'B',
//        TURN_LEFT = 'L',
//        TURN_RIGHT = 'R',
//        MOTOR_LEFT = 'M',
//        MOTOR_RIGHT = 'N',
//        EXIT = 'E',
//        ARC_RIGHT = 'W',
//        ARC_LEFT = 'Q',
//    void AddCommand(char CommandID, QString CommandText);

    void clearCommandVector();
    Command isCommandAvailable(QString inputString);
    bool checkIfNumericOnPlace(QString strToCheck, quint32 positionToCheck);
    bool checkColonOnPlace(QString strToCheck, quint32 positionToCheck);
    void SendData(const char* data, int len);

};
#endif // MAINWINDOW_H
