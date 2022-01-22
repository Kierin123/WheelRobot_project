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
#include <QtWidgets/QFormLayout>
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnectClick;
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelPort_2;
    QLineEdit *lineEditForwardDisctance;
    QPushButton *pushButtonForwardDistance;
    QLineEdit *lineEditBackwardDistance;
    QPushButton *pushButtonBackwardDistance;
    QLineEdit *lineEditForwardSpeed;
    QPushButton *pushButtonForwardSpeed;
    QLineEdit *lineEditBackwardSpeed;
    QPushButton *pushButtonBackwardSpeed;
    QPushButton *pushButtonTurnLeft;
    QPushButton *pushButtonTurnRight;
    QLineEdit *lineEditMotorRight;
    QPushButton *pushButtonMotorRight;
    QLineEdit *lineEditMotorLeft;
    QPushButton *pushButtonMotorLeft;
    QPushButton *pushButtonStop;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonDisconnect;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelSearch;
    QListWidget *listWidget;
    QTextEdit *textEditComm;
    QLabel *labelStatus;
    QLabel *labelPort_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPort;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonSend_2;
    QPushButton *pushButtonSend;
    QLineEdit *lineEditSend;
    QHBoxLayout *horizontalLayout;
    QLabel *labelIP;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEditIP1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(853, 604);
        actionConnectClick = new QAction(MainWindow);
        actionConnectClick->setObjectName(QString::fromUtf8("actionConnectClick"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(620, 0, 222, 331));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(6);
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelPort_2 = new QLabel(formLayoutWidget);
        labelPort_2->setObjectName(QString::fromUtf8("labelPort_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPort_2);

        lineEditForwardDisctance = new QLineEdit(formLayoutWidget);
        lineEditForwardDisctance->setObjectName(QString::fromUtf8("lineEditForwardDisctance"));
        lineEditForwardDisctance->setMaxLength(3);

        formLayout->setWidget(1, QFormLayout::LabelRole, lineEditForwardDisctance);

        pushButtonForwardDistance = new QPushButton(formLayoutWidget);
        pushButtonForwardDistance->setObjectName(QString::fromUtf8("pushButtonForwardDistance"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButtonForwardDistance);

        lineEditBackwardDistance = new QLineEdit(formLayoutWidget);
        lineEditBackwardDistance->setObjectName(QString::fromUtf8("lineEditBackwardDistance"));
        lineEditBackwardDistance->setMaxLength(3);

        formLayout->setWidget(2, QFormLayout::LabelRole, lineEditBackwardDistance);

        pushButtonBackwardDistance = new QPushButton(formLayoutWidget);
        pushButtonBackwardDistance->setObjectName(QString::fromUtf8("pushButtonBackwardDistance"));

        formLayout->setWidget(2, QFormLayout::FieldRole, pushButtonBackwardDistance);

        lineEditForwardSpeed = new QLineEdit(formLayoutWidget);
        lineEditForwardSpeed->setObjectName(QString::fromUtf8("lineEditForwardSpeed"));
        lineEditForwardSpeed->setMaxLength(3);

        formLayout->setWidget(3, QFormLayout::LabelRole, lineEditForwardSpeed);

        pushButtonForwardSpeed = new QPushButton(formLayoutWidget);
        pushButtonForwardSpeed->setObjectName(QString::fromUtf8("pushButtonForwardSpeed"));

        formLayout->setWidget(3, QFormLayout::FieldRole, pushButtonForwardSpeed);

        lineEditBackwardSpeed = new QLineEdit(formLayoutWidget);
        lineEditBackwardSpeed->setObjectName(QString::fromUtf8("lineEditBackwardSpeed"));
        lineEditBackwardSpeed->setMaxLength(3);

        formLayout->setWidget(4, QFormLayout::LabelRole, lineEditBackwardSpeed);

        pushButtonBackwardSpeed = new QPushButton(formLayoutWidget);
        pushButtonBackwardSpeed->setObjectName(QString::fromUtf8("pushButtonBackwardSpeed"));

        formLayout->setWidget(4, QFormLayout::FieldRole, pushButtonBackwardSpeed);

        pushButtonTurnLeft = new QPushButton(formLayoutWidget);
        pushButtonTurnLeft->setObjectName(QString::fromUtf8("pushButtonTurnLeft"));

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButtonTurnLeft);

        pushButtonTurnRight = new QPushButton(formLayoutWidget);
        pushButtonTurnRight->setObjectName(QString::fromUtf8("pushButtonTurnRight"));

        formLayout->setWidget(6, QFormLayout::FieldRole, pushButtonTurnRight);

        lineEditMotorRight = new QLineEdit(formLayoutWidget);
        lineEditMotorRight->setObjectName(QString::fromUtf8("lineEditMotorRight"));
        lineEditMotorRight->setMaxLength(3);

        formLayout->setWidget(7, QFormLayout::LabelRole, lineEditMotorRight);

        pushButtonMotorRight = new QPushButton(formLayoutWidget);
        pushButtonMotorRight->setObjectName(QString::fromUtf8("pushButtonMotorRight"));

        formLayout->setWidget(7, QFormLayout::FieldRole, pushButtonMotorRight);

        lineEditMotorLeft = new QLineEdit(formLayoutWidget);
        lineEditMotorLeft->setObjectName(QString::fromUtf8("lineEditMotorLeft"));
        lineEditMotorLeft->setMaxLength(3);
        lineEditMotorLeft->setFrame(true);

        formLayout->setWidget(8, QFormLayout::LabelRole, lineEditMotorLeft);

        pushButtonMotorLeft = new QPushButton(formLayoutWidget);
        pushButtonMotorLeft->setObjectName(QString::fromUtf8("pushButtonMotorLeft"));

        formLayout->setWidget(8, QFormLayout::FieldRole, pushButtonMotorLeft);

        pushButtonStop = new QPushButton(formLayoutWidget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));

        formLayout->setWidget(9, QFormLayout::FieldRole, pushButtonStop);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 615, 541));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonDisconnect = new QPushButton(gridLayoutWidget);
        pushButtonDisconnect->setObjectName(QString::fromUtf8("pushButtonDisconnect"));

        gridLayout->addWidget(pushButtonDisconnect, 2, 0, 1, 2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelSearch = new QLabel(gridLayoutWidget);
        labelSearch->setObjectName(QString::fromUtf8("labelSearch"));

        horizontalLayout_3->addWidget(labelSearch);


        gridLayout->addLayout(horizontalLayout_3, 0, 2, 1, 1);

        listWidget = new QListWidget(gridLayoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 3, 3, 1, 1);

        textEditComm = new QTextEdit(gridLayoutWidget);
        textEditComm->setObjectName(QString::fromUtf8("textEditComm"));

        gridLayout->addWidget(textEditComm, 3, 0, 1, 3);

        labelStatus = new QLabel(gridLayoutWidget);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));

        gridLayout->addWidget(labelStatus, 0, 0, 1, 2);

        labelPort_3 = new QLabel(gridLayoutWidget);
        labelPort_3->setObjectName(QString::fromUtf8("labelPort_3"));

        gridLayout->addWidget(labelPort_3, 0, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelPort = new QLabel(gridLayoutWidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));

        horizontalLayout_2->addWidget(labelPort);

        lineEditPort = new QLineEdit(gridLayoutWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setMaxLength(4);

        horizontalLayout_2->addWidget(lineEditPort);


        gridLayout->addLayout(horizontalLayout_2, 2, 2, 1, 1);

        pushButtonConnect = new QPushButton(gridLayoutWidget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));
        pushButtonConnect->setMaximumSize(QSize(91, 16777215));

        gridLayout->addWidget(pushButtonConnect, 1, 0, 1, 2);

        pushButtonSend_2 = new QPushButton(gridLayoutWidget);
        pushButtonSend_2->setObjectName(QString::fromUtf8("pushButtonSend_2"));
        pushButtonSend_2->setEnabled(true);

        gridLayout->addWidget(pushButtonSend_2, 1, 3, 1, 1);

        pushButtonSend = new QPushButton(gridLayoutWidget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setEnabled(true);

        gridLayout->addWidget(pushButtonSend, 4, 3, 1, 1);

        lineEditSend = new QLineEdit(gridLayoutWidget);
        lineEditSend->setObjectName(QString::fromUtf8("lineEditSend"));

        gridLayout->addWidget(lineEditSend, 4, 0, 1, 3);

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


        gridLayout->addLayout(horizontalLayout, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 853, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(pushButtonConnect, lineEditIP1);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnectClick->setText(QCoreApplication::translate("MainWindow", "ConnectClick", nullptr));
        labelPort_2->setText(QCoreApplication::translate("MainWindow", "Move Editor", nullptr));
        pushButtonForwardDistance->setText(QCoreApplication::translate("MainWindow", "Forward distance", nullptr));
        pushButtonBackwardDistance->setText(QCoreApplication::translate("MainWindow", "Backward distance", nullptr));
        pushButtonForwardSpeed->setText(QCoreApplication::translate("MainWindow", " Forward speed", nullptr));
        pushButtonBackwardSpeed->setText(QCoreApplication::translate("MainWindow", "Backward speed", nullptr));
        pushButtonTurnLeft->setText(QCoreApplication::translate("MainWindow", "Turn Left", nullptr));
        pushButtonTurnRight->setText(QCoreApplication::translate("MainWindow", "Turn Right", nullptr));
        pushButtonMotorRight->setText(QCoreApplication::translate("MainWindow", "Motor right speed", nullptr));
        pushButtonMotorLeft->setText(QCoreApplication::translate("MainWindow", "Motor left speed", nullptr));
        pushButtonStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        labelSearch->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        labelPort_3->setText(QCoreApplication::translate("MainWindow", "Commands", nullptr));
        labelPort->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        lineEditPort->setText(QCoreApplication::translate("MainWindow", "5050", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButtonSend_2->setText(QCoreApplication::translate("MainWindow", "Send commands", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", " Send message", nullptr));
        labelIP->setText(QCoreApplication::translate("MainWindow", "IP:", nullptr));
        lineEditIP1->setText(QCoreApplication::translate("MainWindow", "192.168.2.100", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
