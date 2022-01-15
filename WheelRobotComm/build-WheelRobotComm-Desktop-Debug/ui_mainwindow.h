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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
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
    QPushButton *pushButtonSearch;
    QLineEdit *lineEditIP_2;
    QLineEdit *lineEditIP_3;
    QLineEdit *lineEditIP_4;
    QLabel *labelSearch;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_7;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(835, 600);
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
        textEditComm->setGeometry(QRect(10, 90, 151, 331));
        lineEditIP = new QLineEdit(centralwidget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
        lineEditIP->setGeometry(QRect(150, 10, 31, 27));
        lineEditPort = new QLineEdit(centralwidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(150, 40, 151, 27));
        pushButtonDisconnect = new QPushButton(centralwidget);
        pushButtonDisconnect->setObjectName(QString::fromUtf8("pushButtonDisconnect"));
        pushButtonDisconnect->setGeometry(QRect(10, 40, 91, 27));
        labelIP = new QLabel(centralwidget);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));
        labelIP->setGeometry(QRect(110, 10, 31, 21));
        labelPort = new QLabel(centralwidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setGeometry(QRect(110, 40, 31, 19));
        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));
        labelStatus->setGeometry(QRect(10, 70, 101, 19));
        lineEditSend = new QLineEdit(centralwidget);
        lineEditSend->setObjectName(QString::fromUtf8("lineEditSend"));
        lineEditSend->setGeometry(QRect(170, 120, 113, 27));
        pushButtonSend = new QPushButton(centralwidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(180, 90, 87, 27));
        pushButtonSearch = new QPushButton(centralwidget);
        pushButtonSearch->setObjectName(QString::fromUtf8("pushButtonSearch"));
        pushButtonSearch->setGeometry(QRect(170, 160, 121, 27));
        lineEditIP_2 = new QLineEdit(centralwidget);
        lineEditIP_2->setObjectName(QString::fromUtf8("lineEditIP_2"));
        lineEditIP_2->setGeometry(QRect(190, 10, 31, 27));
        lineEditIP_3 = new QLineEdit(centralwidget);
        lineEditIP_3->setObjectName(QString::fromUtf8("lineEditIP_3"));
        lineEditIP_3->setGeometry(QRect(230, 10, 31, 27));
        lineEditIP_4 = new QLineEdit(centralwidget);
        lineEditIP_4->setObjectName(QString::fromUtf8("lineEditIP_4"));
        lineEditIP_4->setGeometry(QRect(270, 10, 31, 27));
        labelSearch = new QLabel(centralwidget);
        labelSearch->setObjectName(QString::fromUtf8("labelSearch"));
        labelSearch->setGeometry(QRect(170, 190, 111, 19));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(480, 60, 277, 328));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        lineEdit_5 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        verticalLayout_2->addWidget(lineEdit_5);

        lineEdit_4 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_2->addWidget(lineEdit_4);

        lineEdit_6 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        verticalLayout_2->addWidget(lineEdit_6);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_8 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        verticalLayout_2->addWidget(lineEdit_8);

        lineEdit_7 = new QLineEdit(horizontalLayoutWidget);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        verticalLayout_2->addWidget(lineEdit_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(horizontalLayoutWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_8 = new QPushButton(horizontalLayoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        verticalLayout->addWidget(pushButton_8);

        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_6 = new QPushButton(horizontalLayoutWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(horizontalLayoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout->addWidget(pushButton_7);

        pushButton_9 = new QPushButton(horizontalLayoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        verticalLayout->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(horizontalLayoutWidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        verticalLayout->addWidget(pushButton_10);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 835, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(pushButtonConnect, lineEditIP);
        QWidget::setTabOrder(lineEditIP, lineEditIP_2);
        QWidget::setTabOrder(lineEditIP_2, lineEditIP_3);
        QWidget::setTabOrder(lineEditIP_3, lineEditIP_4);
        QWidget::setTabOrder(lineEditIP_4, lineEditPort);
        QWidget::setTabOrder(lineEditPort, pushButtonSearch);
        QWidget::setTabOrder(pushButtonSearch, pushButtonSend);
        QWidget::setTabOrder(pushButtonSend, lineEditSend);
        QWidget::setTabOrder(lineEditSend, textEditComm);
        QWidget::setTabOrder(textEditComm, pushButtonDisconnect);

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
        pushButtonSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        labelSearch->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Forward distance", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Backward distance", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", " Forward speed", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Backward speed", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Turn Left", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Turn Right", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Motor right speed", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Motor left speed", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
