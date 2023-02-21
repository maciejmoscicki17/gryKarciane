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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dice
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *enemyDicesLayout;
    QPushButton *btnStart;
    QPushButton *btnExit;
    QPushButton *btnReset;
    QWidget *gridLayoutWidget_2;
    QGridLayout *playerDicesLayout;
    QLabel *lblResult;
    QCheckBox *cbDice_1;
    QCheckBox *cbDice_2;
    QCheckBox *cbDice_3;
    QCheckBox *cbDice_4;
    QCheckBox *cbDice_5;
    QPushButton *btnReroll;

    void setupUi(QDialog *dice)
    {
        if (dice->objectName().isEmpty())
            dice->setObjectName("dice");
        dice->resize(1920, 1080);
        gridLayoutWidget = new QWidget(dice);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(260, 390, 851, 151));
        enemyDicesLayout = new QGridLayout(gridLayoutWidget);
        enemyDicesLayout->setObjectName("enemyDicesLayout");
        enemyDicesLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        enemyDicesLayout->setContentsMargins(0, 0, 0, 0);
        btnStart = new QPushButton(dice);
        btnStart->setObjectName("btnStart");
        btnStart->setGeometry(QRect(1230, 540, 181, 101));
        btnExit = new QPushButton(dice);
        btnExit->setObjectName("btnExit");
        btnExit->setGeometry(QRect(1230, 770, 181, 101));
        btnReset = new QPushButton(dice);
        btnReset->setObjectName("btnReset");
        btnReset->setGeometry(QRect(1230, 660, 181, 101));
        gridLayoutWidget_2 = new QWidget(dice);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(260, 840, 851, 151));
        playerDicesLayout = new QGridLayout(gridLayoutWidget_2);
        playerDicesLayout->setObjectName("playerDicesLayout");
        playerDicesLayout->setContentsMargins(0, 0, 0, 0);
        lblResult = new QLabel(dice);
        lblResult->setObjectName("lblResult");
        lblResult->setGeometry(QRect(290, 650, 291, 51));
        lblResult->setAutoFillBackground(false);
        cbDice_1 = new QCheckBox(dice);
        cbDice_1->setObjectName("cbDice_1");
        cbDice_1->setGeometry(QRect(270, 790, 78, 22));
        cbDice_2 = new QCheckBox(dice);
        cbDice_2->setObjectName("cbDice_2");
        cbDice_2->setGeometry(QRect(410, 790, 78, 22));
        cbDice_3 = new QCheckBox(dice);
        cbDice_3->setObjectName("cbDice_3");
        cbDice_3->setGeometry(QRect(580, 790, 78, 22));
        cbDice_4 = new QCheckBox(dice);
        cbDice_4->setObjectName("cbDice_4");
        cbDice_4->setGeometry(QRect(740, 790, 78, 22));
        cbDice_5 = new QCheckBox(dice);
        cbDice_5->setObjectName("cbDice_5");
        cbDice_5->setGeometry(QRect(880, 790, 78, 22));
        btnReroll = new QPushButton(dice);
        btnReroll->setObjectName("btnReroll");
        btnReroll->setGeometry(QRect(980, 790, 131, 24));

        retranslateUi(dice);

        QMetaObject::connectSlotsByName(dice);
    } // setupUi

    void retranslateUi(QDialog *dice)
    {
        dice->setWindowTitle(QCoreApplication::translate("dice", "Dialog", nullptr));
        btnStart->setText(QCoreApplication::translate("dice", "Start", nullptr));
        btnExit->setText(QCoreApplication::translate("dice", "Wyj\305\233cie", nullptr));
        btnReset->setText(QCoreApplication::translate("dice", "Reset", nullptr));
        lblResult->setText(QCoreApplication::translate("dice", "Rezultat", nullptr));
        cbDice_1->setText(QString());
        cbDice_2->setText(QString());
        cbDice_3->setText(QString());
        cbDice_4->setText(QString());
        cbDice_5->setText(QString());
        btnReroll->setText(QCoreApplication::translate("dice", "Przelosuj wybrane", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dice: public Ui_dice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICE_H
