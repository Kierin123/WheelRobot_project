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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonSend;
    QLineEdit *lineEditSend;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QHBoxLayout *horizontalLayout;
    QLabel *labelIP;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEditIP1;
    QTextEdit *textEditComm;
    QPushButton *pushButtonDisconnect;
    QLabel *label_2;
    QPushButton *pushButtonConnect;
    QLabel *labelStatus;
    QLabel *label;
    QLabel *label_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelPort_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *lineEditDistance;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonForwardDistance;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButtonTurnLeft;
    QPushButton *pushButtonTurnRight;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonBackwardDistance;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLineEdit *lineEditArc;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButtonArcLeft;
    QPushButton *pushButtonArcRight;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QLineEdit *lineEditSpeed;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *pushButtonMotorLeft;
    QPushButton *pushButtonMotorRight;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButtonStop;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_19;
    QListWidget *listWidget;
    QPushButton *pushButtonClearCommand;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *pushButtonSaveFile;
    QPushButton *pushButtonLoadFile;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *pushButtonSend_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(800, 620);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(800, 620));
        actionConnectClick = new QAction(MainWindow);
        actionConnectClick->setObjectName(QString::fromUtf8("actionConnectClick"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 0, 301, 541));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonSend = new QPushButton(gridLayoutWidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setEnabled(true);

        gridLayout->addWidget(pushButtonSend, 7, 0, 1, 1);

        lineEditSend = new QLineEdit(gridLayoutWidget);
        lineEditSend->setObjectName(QString::fromUtf8("lineEditSend"));

        gridLayout->addWidget(lineEditSend, 7, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelPort = new QLabel(gridLayoutWidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));

        horizontalLayout_2->addWidget(labelPort);

        lineEditPort = new QLineEdit(gridLayoutWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setMaxLength(4);

        horizontalLayout_2->addWidget(lineEditPort);


        gridLayout->addLayout(horizontalLayout_2, 3, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelIP = new QLabel(gridLayoutWidget);
        labelIP->setObjectName(QString::fromUtf8("labelIP"));

        horizontalLayout->addWidget(labelIP);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        lineEditIP1 = new QLineEdit(gridLayoutWidget);
        lineEditIP1->setObjectName(QString::fromUtf8("lineEditIP1"));
        lineEditIP1->setMaxLength(15);

        horizontalLayout->addWidget(lineEditIP1);


        gridLayout->addLayout(horizontalLayout, 1, 2, 2, 1);

        textEditComm = new QTextEdit(gridLayoutWidget);
        textEditComm->setObjectName(QString::fromUtf8("textEditComm"));

        gridLayout->addWidget(textEditComm, 5, 0, 1, 3);

        pushButtonDisconnect = new QPushButton(gridLayoutWidget);
        pushButtonDisconnect->setObjectName(QString::fromUtf8("pushButtonDisconnect"));

        gridLayout->addWidget(pushButtonDisconnect, 3, 0, 1, 2);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 4, 0, 1, 3);

        pushButtonConnect = new QPushButton(gridLayoutWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setMaximumSize(QSize(600, 16777215));

        gridLayout->addWidget(pushButtonConnect, 1, 0, 2, 2);

        labelStatus = new QLabel(gridLayoutWidget);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));

        gridLayout->addWidget(labelStatus, 0, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 6, 0, 1, 3);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(530, 0, 256, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelPort_2 = new QLabel(verticalLayoutWidget);
        labelPort_2->setObjectName(QString::fromUtf8("labelPort_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(100);
        sizePolicy1.setHeightForWidth(labelPort_2->sizePolicy().hasHeightForWidth());
        labelPort_2->setSizePolicy(sizePolicy1);
        labelPort_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(labelPort_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        lineEditDistance = new QLineEdit(verticalLayoutWidget);
        lineEditDistance->setObjectName(QString::fromUtf8("lineEditDistance"));
        lineEditDistance->setMaxLength(3);

        horizontalLayout_6->addWidget(lineEditDistance);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        pushButtonForwardDistance = new QPushButton(verticalLayoutWidget);
        pushButtonForwardDistance->setObjectName(QString::fromUtf8("pushButtonForwardDistance"));

        horizontalLayout_9->addWidget(pushButtonForwardDistance);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButtonTurnLeft = new QPushButton(verticalLayoutWidget);
        pushButtonTurnLeft->setObjectName(QString::fromUtf8("pushButtonTurnLeft"));

        horizontalLayout_8->addWidget(pushButtonTurnLeft);

        pushButtonTurnRight = new QPushButton(verticalLayoutWidget);
        pushButtonTurnRight->setObjectName(QString::fromUtf8("pushButtonTurnRight"));

        horizontalLayout_8->addWidget(pushButtonTurnRight);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);

        pushButtonBackwardDistance = new QPushButton(verticalLayoutWidget);
        pushButtonBackwardDistance->setObjectName(QString::fromUtf8("pushButtonBackwardDistance"));

        horizontalLayout_10->addWidget(pushButtonBackwardDistance);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        lineEditArc = new QLineEdit(verticalLayoutWidget);
        lineEditArc->setObjectName(QString::fromUtf8("lineEditArc"));
        lineEditArc->setEnabled(true);
        lineEditArc->setMaxLength(3);

        horizontalLayout_7->addWidget(lineEditArc);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pushButtonArcLeft = new QPushButton(verticalLayoutWidget);
        pushButtonArcLeft->setObjectName(QString::fromUtf8("pushButtonArcLeft"));

        horizontalLayout_11->addWidget(pushButtonArcLeft);

        pushButtonArcRight = new QPushButton(verticalLayoutWidget);
        pushButtonArcRight->setObjectName(QString::fromUtf8("pushButtonArcRight"));

        horizontalLayout_11->addWidget(pushButtonArcRight);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_13->addWidget(label_9);

        lineEditSpeed = new QLineEdit(verticalLayoutWidget);
        lineEditSpeed->setObjectName(QString::fromUtf8("lineEditSpeed"));
        lineEditSpeed->setMaxLength(3);

        horizontalLayout_13->addWidget(lineEditSpeed);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_13->addWidget(label_10);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        pushButtonMotorLeft = new QPushButton(verticalLayoutWidget);
        pushButtonMotorLeft->setObjectName(QString::fromUtf8("pushButtonMotorLeft"));

        horizontalLayout_14->addWidget(pushButtonMotorLeft);

        pushButtonMotorRight = new QPushButton(verticalLayoutWidget);
        pushButtonMotorRight->setObjectName(QString::fromUtf8("pushButtonMotorRight"));

        horizontalLayout_14->addWidget(pushButtonMotorRight);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pushButtonStop = new QPushButton(verticalLayoutWidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

        horizontalLayout_12->addWidget(pushButtonStop);


        verticalLayout->addLayout(horizontalLayout_12);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(310, 0, 218, 541));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_16->addWidget(label_8);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        listWidget = new QListWidget(verticalLayoutWidget_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_19->addWidget(listWidget);


        verticalLayout_2->addLayout(horizontalLayout_19);

        pushButtonClearCommand = new QPushButton(verticalLayoutWidget_2);
        pushButtonClearCommand->setObjectName(QString::fromUtf8("pushButtonClearCommand"));

        verticalLayout_2->addWidget(pushButtonClearCommand);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        pushButtonSaveFile = new QPushButton(verticalLayoutWidget_2);
        pushButtonSaveFile->setObjectName(QString::fromUtf8("pushButtonSaveFile"));

        horizontalLayout_20->addWidget(pushButtonSaveFile);

        pushButtonLoadFile = new QPushButton(verticalLayoutWidget_2);
        pushButtonLoadFile->setObjectName(QString::fromUtf8("pushButtonLoadFile"));

        horizontalLayout_20->addWidget(pushButtonLoadFile);


        verticalLayout_2->addLayout(horizontalLayout_20);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        pushButtonSend_2 = new QPushButton(verticalLayoutWidget_2);
        pushButtonSend_2->setObjectName(QString::fromUtf8("pushButtonSend_2"));
        pushButtonSend_2->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonSend_2->sizePolicy().hasHeightForWidth());
        pushButtonSend_2->setSizePolicy(sizePolicy2);
        pushButtonSend_2->setIconSize(QSize(16, 16));

        horizontalLayout_18->addWidget(pushButtonSend_2);


        verticalLayout_2->addLayout(horizontalLayout_18);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
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
#if QT_CONFIG(accessibility)
        MainWindow->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        actionConnectClick->setText(QCoreApplication::translate("MainWindow", "ConnectClick", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", " Send message", nullptr));
        labelPort->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        lineEditPort->setText(QCoreApplication::translate("MainWindow", "5050", nullptr));
        labelIP->setText(QCoreApplication::translate("MainWindow", "IP:", nullptr));
        lineEditIP1->setText(QCoreApplication::translate("MainWindow", "192.168.2.100", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Robot Terminal", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Send command", nullptr));
        labelPort_2->setText(QCoreApplication::translate("MainWindow", "Command sequence Editor", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Distance:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "[mm]", nullptr));
        pushButtonForwardDistance->setText(QCoreApplication::translate("MainWindow", "Forward", nullptr));
        pushButtonTurnLeft->setText(QCoreApplication::translate("MainWindow", "Rotate Left", nullptr));
        pushButtonTurnRight->setText(QCoreApplication::translate("MainWindow", "Rotate Right", nullptr));
        pushButtonBackwardDistance->setText(QCoreApplication::translate("MainWindow", "Backward", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Arc:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "[deg]", nullptr));
        pushButtonArcLeft->setText(QCoreApplication::translate("MainWindow", "Arc Left", nullptr));
        pushButtonArcRight->setText(QCoreApplication::translate("MainWindow", "Arc Right", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Speed(0-1024):", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "[pwm]", nullptr));
        pushButtonMotorLeft->setText(QCoreApplication::translate("MainWindow", "Motor left speed", nullptr));
        pushButtonMotorRight->setText(QCoreApplication::translate("MainWindow", "Motor right speed", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Command Sequence", nullptr));
        pushButtonClearCommand->setText(QCoreApplication::translate("MainWindow", "Clear command sequence", nullptr));
        pushButtonSaveFile->setText(QCoreApplication::translate("MainWindow", "Save to file", nullptr));
        pushButtonLoadFile->setText(QCoreApplication::translate("MainWindow", "Load form file", nullptr));
        pushButtonSend_2->setText(QCoreApplication::translate("MainWindow", "Send commands", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
