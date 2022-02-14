/********************************************************************************
** Form generated from reading UI file 'dialogsave.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSAVE_H
#define UI_DIALOGSAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_DialogSave
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSave)
    {
        if (DialogSave->objectName().isEmpty())
            DialogSave->setObjectName(QString::fromUtf8("DialogSave"));
        DialogSave->resize(480, 640);
        DialogSave->setMaximumSize(QSize(800, 800));
        buttonBox = new QDialogButtonBox(DialogSave);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 600, 461, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogSave);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSave, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSave, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSave);
    } // setupUi

    void retranslateUi(QDialog *DialogSave)
    {
        DialogSave->setWindowTitle(QCoreApplication::translate("DialogSave", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSave: public Ui_DialogSave {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSAVE_H
