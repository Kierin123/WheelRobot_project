/********************************************************************************
** Form generated from reading UI file 'dialogload.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLOAD_H
#define UI_DIALOGLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>

QT_BEGIN_NAMESPACE

class Ui_DialogLoad
{
public:
    QDialogButtonBox *buttonBox;
    QTreeView *treeView;

    void setupUi(QDialog *DialogLoad)
    {
        if (DialogLoad->objectName().isEmpty())
            DialogLoad->setObjectName(QString::fromUtf8("DialogLoad"));
        DialogLoad->resize(480, 640);
        DialogLoad->setMaximumSize(QSize(800, 800));
        buttonBox = new QDialogButtonBox(DialogLoad);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 600, 461, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        treeView = new QTreeView(DialogLoad);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 10, 461, 581));

        retranslateUi(DialogLoad);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogLoad, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogLoad, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogLoad);
    } // setupUi

    void retranslateUi(QDialog *DialogLoad)
    {
        DialogLoad->setWindowTitle(QCoreApplication::translate("DialogLoad", "Load trajectory - WheelRobotApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogLoad: public Ui_DialogLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLOAD_H
