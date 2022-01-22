#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <client.h>
#include <vector>
#include <map>
#include <chrono>
#include <ctime>
#include <ratio>

#include <QThread>

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
};

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

private:
    Ui::MainWindow *ui;
    Client *client;
    std::map<int,QString> CommandObj;
    std::vector<QString> CommandVect;
    QString answer;
    int lastCommandID = CommandObj.end()->first;
    void AddCommand(char CommandID, QString CommandText);
    void SendData(const char* data, int len);

};
#endif // MAINWINDOW_H
