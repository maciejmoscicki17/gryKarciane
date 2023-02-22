#include "blackjack.h"
#include "ui_blackjack.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QFrame>
#include <QThread>
#include <QPalette>

blackjack::blackjack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blackjack)
{
    int w=100, h=152;
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->dealerCardsLayout->setAlignment(Qt::AlignHCenter);
    ui->playerCardsLayout->setAlignment(Qt::AlignHCenter);
    connect(this, &QDialog::rejected, this, &blackjack::resetAll);
}



blackjack::~blackjack()
{
    delete ui;
}

void blackjack::setupCards()
{
    cards.clear();
    cards = Card::getCardSet();
}

Card blackjack::getCard()
{
    srand((unsigned)time(NULL));
    int r = rand() % cards.size();

    Card c = cards.at(r);
    cards.erase(next(cards.begin(), r));
    return c;
}

void blackjack::resetAll()
{
    while (QLayoutItem *item = ui->dealerCardsLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    ui->dealerCardsLayout->setContentsMargins(0, 0, 0, 0);

    while (QLayoutItem *item = ui->playerCardsLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    ui->playerCardsLayout->setContentsMargins(0, 0, 0, 0);

    ui->lblPlayerScore->setText("Twój wynik");
    ui->lblDealerScore->setText("Wynik dealera");
    ui->lblResult->setText("");
    setupCards();

}

void blackjack::delay(int duration)
{
    QEventLoop eventLoop;
    QTimer::singleShot(duration, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();
}

void blackjack::showPlayerInfo(Card card, int score)
{
    QPixmap *image1 = card.getFace();
    QLabel * label = new QLabel(this);
    label->resize(w,h);
    label->setPixmap((*image1).scaled(w,h,Qt::KeepAspectRatio));
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(label);
    label->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(500);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->start();
    auto items = ui->playerCardsLayout->count();

    ui->playerCardsLayout->addWidget(label,0,items);
}

void blackjack::showDealerCard(Card card, int score)
{
    QPixmap *image1 = card.getFace();
    QLabel * label = new QLabel(this);
    label->resize(w,h);
    label->setPixmap((*image1).scaled(w,h,Qt::KeepAspectRatio));

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(label);
    label->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(500);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->start();

    auto items = ui->dealerCardsLayout->count();
    ui->dealerCardsLayout->addWidget(label,0,items);
    ui->lblDealerScore->setText("Wynik dealera: " + QString::number(score));
}

void blackjack::on_btnStart_clicked()
{
    ui->btnStart->setDisabled(true);
    setupCards();
    bool gameOn = true;
    int wynik = 0;
    int pause = 1000;
    while (gameOn)
    {
        auto los = getCard();
        QTimer *timer = new QTimer(this);
        timer->singleShot(pause, [this, los, wynik] {
            showPlayerInfo(los, wynik);

        });
        delete timer;

        los.printInfo();
        int val = los.getValue(true);
        if(val == 14){
            delay(2000);
            QString message = "Jaką wartość ma mieć as?";
            QMessageBox msgBox;
            msgBox.setText(message);
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            msgBox.setButtonText(QMessageBox::Yes, "1");
            msgBox.setButtonText(QMessageBox::No, "10");
            int ret = msgBox.exec();
            val = (ret == QMessageBox::Yes) ? 1 : 10;

        }

        wynik += val;

        delay(2000);

        QString str = "Twój wynik: " + QString::number(wynik);
        ui->lblPlayerScore->setText(str);
        if (wynik > 21) break;
        QString message = str + ", czy chcesz kontynuować?";
        QMessageBox msgBox;
        msgBox.setText(message);
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes, "Tak");
        msgBox.setButtonText(QMessageBox::No, "Nie");

        int ret = msgBox.exec();

        bool result = (ret == QMessageBox::Yes);

        gameOn = result;

    }


    int wynikD = 0;
    bool gameOnD = true;
    pause = 1000;
    while (gameOnD)
    {
        auto los = getCard();
        wynikD += los.getValue(false);

        QTimer *timer = new QTimer(this);
        timer->singleShot(pause, [this, los, wynikD] { showDealerCard(los, wynikD); });
        delete timer;
        pause += 1000;
        los.printInfo();

        if (wynikD > 21) break;
        if (wynikD >= 18) {
            gameOnD = false;
        }
    }

    ui->lblResult->setText("");
    QTimer *timer = new QTimer(this);
    timer->singleShot(pause, [this, wynik, wynikD] {

        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(ui->lblResult);
        ui->lblResult->setGraphicsEffect(effect);

        QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
        animation->setDuration(500);
        animation->setStartValue(0.0);
        animation->setEndValue(1.0);
        animation->setLoopCount(-1);
        animation->start();
        QObject::connect(animation, &QPropertyAnimation::finished, [effect]{ effect->setOpacity(1.0); });
        QObject::connect(ui->btnReset, &QPushButton::clicked, animation, &QPropertyAnimation::stop);

        if (wynik > 21 && wynikD > 21) ui->lblResult->setText("Remis");
        else if (wynik > 21) ui->lblResult->setText("Przegrana.");
        else if (wynikD > 21) ui->lblResult->setText("Wygrana!");
        else if (wynik > wynikD) ui->lblResult->setText("Wygrana!");
        else if (wynik == wynikD) ui->lblResult->setText("Remis");
        else ui->lblResult->setText("Przegrana");
    });
    delete timer;


    ui->btnStart->setDisabled(false);

}


void blackjack::on_btnReset_clicked()
{
    resetAll();
}


void blackjack::on_btnExit_clicked()
{
    this->close();
}

