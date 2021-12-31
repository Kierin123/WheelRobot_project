/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnectClick;
    QWidget *centralwidget;
    QPushButton *pushButtonConnect;
    QTextEdit *textEditComm;
    QLineEdit *lineEditIP;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonDisconnect;
    QLabel *labelIP;
    QLabel *labelPort;
    QLabel *labelStatus;
    QLineEdit *lineEditSend;
    QPushButton *pushButtonSend;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(561, 600);
        actionConnectClick = new QAction(MainWindow);
        actionConnectClick->setObjectName(QString::fromUtf8("actionConnectClick"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setGeometry(QRect(10, 10, 91, 27));
        pushButtonConnect->setMaximumSize(QSize(91, 16777215));
        textEditComm = new QTextEdit(centralwidget);
        textEditComm->setObjectName(QString::fromUtf8("textEditComm"));
        textEditComm->setGeometry(QRect(10, 90, 181, 411));
        lineEditIP = new QLineEdit(centralwidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
        lineEditIP->setGeometry(QRect(150, 10, 113, 27));
        lineEditPort = new QLineEdit(centralwidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(150, 40, 113, 27));
        pushButtonDisconnect = new QPushButton(centralwidget);
        pushButtonDisconnect->setObjectName(QString::fromUtf8("pushButtonDisconnect"));
        pushButtonDisconnect->setGeometry(QRect(10, 40, 91, 27));
        labelIP = new QLabel(centralwidget);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));
        labelIP->setGeometry(QRect(110, 10, 66, 19));
        labelPort = new QLabel(centralwidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setGeometry(QRect(110, 40, 66, 19));
        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));
        labelStatus->setGeometry(QRect(270, 10, 101, 19));
        lineEditSend = new QLineEdit(centralwidget);
        lineEditSend->setObjectName(QString::fromUtf8("lineEditSend"));
        lineEditSend->setGeometry(QRect(310, 90, 113, 27));
        pushButtonSend = new QPushButton(centralwidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(200, 90, 87, 27));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 561, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnectClick->setText(QCoreApplication::translate("MainWindow", "ConnectClick", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        labelIP->setText(QCoreApplication::translate("MainWindow", "IP:", nullptr));
        labelPort->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
