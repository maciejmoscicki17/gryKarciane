/********************************************************************************
** Form generated from reading UI file 'makao.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKAO_H
#define UI_MAKAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Makao
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *oppLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *playerCardsLayout;
    QWidget *gridLayoutWidget_3;
    QGridLayout *tableCardsLayout;
    QPushButton *btnGivePlayerCard;
    QPushButton *btnStart;
    QPushButton *btnRestart;
    QPushButton *btnExit;
    QLabel *lblState;

    void setupUi(QDialog *Makao)
    {
        if (Makao->objectName().isEmpty())
            Makao->setObjectName("Makao");
        Makao->resize(1920, 1080);
        gridLayoutWidget = new QWidget(Makao);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 180, 1921, 151));
        oppLayout = new QGridLayout(gridLayoutWidget);
        oppLayout->setObjectName("oppLayout");
        oppLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        oppLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(Makao);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 570, 1921, 151));
        playerCardsLayout = new QGridLayout(gridLayoutWidget_2);
        playerCardsLayout->setObjectName("playerCardsLayout");
        playerCardsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        playerCardsLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_3 = new QWidget(Makao);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(0, 370, 1921, 151));
        tableCardsLayout = new QGridLayout(gridLayoutWidget_3);
        tableCardsLayout->setObjectName("tableCardsLayout");
        tableCardsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        tableCardsLayout->setContentsMargins(0, 0, 0, 0);
        btnGivePlayerCard = new QPushButton(Makao);
        btnGivePlayerCard->setObjectName("btnGivePlayerCard");
        btnGivePlayerCard->setGeometry(QRect(450, 800, 951, 71));
        btnStart = new QPushButton(Makao);
        btnStart->setObjectName("btnStart");
        btnStart->setGeometry(QRect(1720, 860, 151, 51));
        btnRestart = new QPushButton(Makao);
        btnRestart->setObjectName("btnRestart");
        btnRestart->setGeometry(QRect(1720, 920, 151, 51));
        btnExit = new QPushButton(Makao);
        btnExit->setObjectName("btnExit");
        btnExit->setGeometry(QRect(1720, 980, 151, 51));
        lblState = new QLabel(Makao);
        lblState->setObjectName("lblState");
        lblState->setGeometry(QRect(770, 60, 431, 51));

        retranslateUi(Makao);

        QMetaObject::connectSlotsByName(Makao);
    } // setupUi

    void retranslateUi(QDialog *Makao)
    {
        Makao->setWindowTitle(QCoreApplication::translate("Makao", "Dialog", nullptr));
        btnGivePlayerCard->setText(QCoreApplication::translate("Makao", "Dodaj karte", nullptr));
        btnStart->setText(QCoreApplication::translate("Makao", "Start", nullptr));
        btnRestart->setText(QCoreApplication::translate("Makao", "Restart", nullptr));
        btnExit->setText(QCoreApplication::translate("Makao", "Wyj\305\233cie", nullptr));
        lblState->setText(QCoreApplication::translate("Makao", "Stan gry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Makao: public Ui_Makao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKAO_H
