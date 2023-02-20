/********************************************************************************
** Form generated from reading UI file 'dice.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICE_H
#define UI_DICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Dice
{
public:

    void setupUi(QDialog *Dice)
    {
        if (Dice->objectName().isEmpty())
            Dice->setObjectName("Dice");
        Dice->resize(640, 480);

        retranslateUi(Dice);

        QMetaObject::connectSlotsByName(Dice);
    } // setupUi

    void retranslateUi(QDialog *Dice)
    {
        Dice->setWindowTitle(QCoreApplication::translate("Dice", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dice: public Ui_Dice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICE_H
