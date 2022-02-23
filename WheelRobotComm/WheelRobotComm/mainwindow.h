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
#include <command.h>


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


    void on_pushButtonForwardDistance_clicked();

    void on_pushButtonBackwardDistance_clicked();

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

    void on_pushButtonMotorLeftFactor_clicked();

    void on_pushButtonMotorRightFactor_clicked();

private:

    Ui::MainWindow *ui;
    Client *client;
    CommandVector CommandVect;
//    std::vector<Command> CommandVect;

    void clearCommandVector();
    void AddCommandToVector(char prefixCommand, QString valueCommand);

    Command isCommandAvailable(QString inputString);
    bool checkIfNumericOnPlace(QString strToCheck, quint32 positionToCheck);
    bool checkColonOnPlace(QString strToCheck, quint32 positionToCheck);
    void SendData(const char* data, int len);


};
#endif // MAINWINDOW_H
