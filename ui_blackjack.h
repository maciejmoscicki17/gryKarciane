/********************************************************************************
** Form generated from reading UI file 'blackjack.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLACKJACK_H
#define UI_BLACKJACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_blackjack
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *dealerCardsLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *playerCardsLayout;
    QPushButton *btnStart;
    QLabel *lblPlayerScore;
    QLabel *lblDealerScore;
    QLabel *lblResult;
    QPushButton *btnReset;
    QPushButton *btnExit;

    void setupUi(QDialog *blackjack)
    {
        if (blackjack->objectName().isEmpty())
            blackjack->setObjectName("blackjack");
        blackjack->resize(1920, 1080);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(blackjack->sizePolicy().hasHeightForWidth());
        blackjack->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(blackjack);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(310, 140, 1081, 151));
        dealerCardsLayout = new QGridLayout(gridLayoutWidget);
        dealerCardsLayout->setObjectName("dealerCardsLayout");
        dealerCardsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        dealerCardsLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(blackjack);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(310, 590, 1081, 151));
        playerCardsLayout = new QGridLayout(gridLayoutWidget_2);
        playerCardsLayout->setObjectName("playerCardsLayout");
        playerCardsLayout->setContentsMargins(0, 0, 0, 0);
        btnStart = new QPushButton(blackjack);
        btnStart->setObjectName("btnStart");
        btnStart->setGeometry(QRect(1420, 280, 181, 101));
        lblPlayerScore = new QLabel(blackjack);
        lblPlayerScore->setObjectName("lblPlayerScore");
        lblPlayerScore->setGeometry(QRect(430, 530, 311, 41));
        lblDealerScore = new QLabel(blackjack);
        lblDealerScore->setObjectName("lblDealerScore");
        lblDealerScore->setGeometry(QRect(430, 320, 311, 41));
        lblResult = new QLabel(blackjack);
        lblResult->setObjectName("lblResult");
        lblResult->setGeometry(QRect(430, 420, 291, 51));
        lblResult->setAutoFillBackground(false);
        btnReset = new QPushButton(blackjack);
        btnReset->setObjectName("btnReset");
        btnReset->setGeometry(QRect(1420, 390, 181, 101));
        btnExit = new QPushButton(blackjack);
        btnExit->setObjectName("btnExit");
        btnExit->setGeometry(QRect(1420, 500, 181, 101));

        retranslateUi(blackjack);

        QMetaObject::connectSlotsByName(blackjack);
    } // setupUi

    void retranslateUi(QDialog *blackjack)
    {
        blackjack->setWindowTitle(QCoreApplication::translate("blackjack", "Dialog", nullptr));
        btnStart->setText(QCoreApplication::translate("blackjack", "Start", nullptr));
        lblPlayerScore->setText(QCoreApplication::translate("blackjack", "Tw\303\263j wynik", nullptr));
        lblDealerScore->setText(QCoreApplication::translate("blackjack", "Wynik dealera", nullptr));
        lblResult->setText(QCoreApplication::translate("blackjack", "Rezultat", nullptr));
        btnReset->setText(QCoreApplication::translate("blackjack", "Reset", nullptr));
        btnExit->setText(QCoreApplication::translate("blackjack", "Wyj\305\233cie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class blackjack: public Ui_blackjack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLACKJACK_H
