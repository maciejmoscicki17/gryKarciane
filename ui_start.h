/********************************************************************************
** Form generated from reading UI file 'start.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start
{
public:
    QWidget *centralwidget;
    QLabel *imageLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnTest;
    QPushButton *btnBlackjack;
    QLabel *lblTitle;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *start)
    {
        if (start->objectName().isEmpty())
            start->setObjectName("start");
        start->resize(1920, 1080);
        centralwidget = new QWidget(start);
        centralwidget->setObjectName("centralwidget");
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(740, 140, 801, 721));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 0, 261, 1061));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnTest = new QPushButton(verticalLayoutWidget);
        btnTest->setObjectName("btnTest");
        btnTest->setEnabled(true);
        btnTest->setMinimumSize(QSize(0, 100));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(28);
        btnTest->setFont(font);

        verticalLayout->addWidget(btnTest);

        btnBlackjack = new QPushButton(verticalLayoutWidget);
        btnBlackjack->setObjectName("btnBlackjack");
        btnBlackjack->setEnabled(true);
        btnBlackjack->setMinimumSize(QSize(0, 100));
        btnBlackjack->setFont(font);

        verticalLayout->addWidget(btnBlackjack);

        lblTitle = new QLabel(centralwidget);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setGeometry(QRect(740, 10, 801, 81));
        start->setCentralWidget(centralwidget);
        menubar = new QMenuBar(start);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        start->setMenuBar(menubar);
        statusbar = new QStatusBar(start);
        statusbar->setObjectName("statusbar");
        start->setStatusBar(statusbar);

        retranslateUi(start);

        QMetaObject::connectSlotsByName(start);
    } // setupUi

    void retranslateUi(QMainWindow *start)
    {
        start->setWindowTitle(QCoreApplication::translate("start", "start", nullptr));
        imageLabel->setText(QCoreApplication::translate("start", "TextLabel", nullptr));
        btnTest->setText(QCoreApplication::translate("start", "Makao", nullptr));
        btnBlackjack->setText(QCoreApplication::translate("start", "Blackjack", nullptr));
        lblTitle->setText(QCoreApplication::translate("start", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start: public Ui_start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
