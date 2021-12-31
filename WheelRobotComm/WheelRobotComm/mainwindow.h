#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <client.h>

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

private:
    Ui::MainWindow *ui;
    Client *client;
};
#endif // MAINWINDOW_H
