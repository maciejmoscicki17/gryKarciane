#include "makao.h"
#include "qlabel.h"
#include "qtimer.h"
#include "ui_makao.h"
#include <random>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QMessageBox>

Makao::Makao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Makao)
{
    ui->setupUi(this);
    ui->oppLayout->setAlignment(Qt::AlignHCenter);
    ui->tableCardsLayout->setAlignment(Qt::AlignHCenter);
    ui->playerCardsLayout->setAlignment(Qt::AlignHCenter);
    ui->btnGivePlayerCard->hide();
    ui->lblState->setAlignment(Qt::AlignCenter);
}

Makao::~Makao()
{
    delete ui;
}

void Makao::addOpponentCard(Card card)
{
    oppCards.push_back(card);
    refreshOpponentCards();
}

void Makao::addPlayerCard(Card card)
{
    playerCards.push_back(card);
    refreshPlayerCards();
}

void Makao::addTableCard(Card card)
{
    if(ui->oppLayout->count() != oppCards.size()) refreshOpponentCards();

    card.printInfo();
    tableCards.push_back(card);
    QPixmap *image1 = card.getFace();
    ClickableLabel * label = new ClickableLabel(this);
    label->resize(w,h);
    label->setPixmap((*image1).scaled(w,h,Qt::KeepAspectRatio));
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(label);
    label->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(500);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->start();
    label->addCard(card);
    QLayoutItem *item;
    while ((item = ui->tableCardsLayout->takeAt(0)) != nullptr) {
        if (item->widget() != nullptr) {
            delete item->widget();
        }
        delete item;
    }
    ui->tableCardsLayout->addWidget(label,0,0);
    lastCard = card;
}

void Makao::playerCardClicked(ClickableLabel* lbl)
{
    bool isValid = ((lbl->card.getMakaoValue() == lastCard.getMakaoValue()) || (lbl->card.getSuit() == lastCard.getSuit()));

    if(isValid){

        ui->playerCardsLayout->removeWidget(lbl);
        auto it = std::find(playerCards.begin(), playerCards.end(), lbl->card);
        if (it != playerCards.end()) {
            playerCards.erase(it);
            lbl->hide();
        }
        addTableCard(lbl->card);

        lastCardForce = checkCardForce(lbl->card);
        if(lastCardForce == 2 || lastCardForce == 3 || lastCardForce == 5){
            for(int i = 0; i < lastCardForce; i++){
                delay(1000);
                giveOpponentCard();
            }
        }

        if(playerCards.size() == 0){
            QMessageBox::information(this, "Message", "Wygrana");
            return;
        }
        if(lastCardForce == 4) return;
        oppTurn();
    } else {
        QMessageBox::information(this, "Message", "Nie możesz użyć tej karty");
    }
}

void Makao::refreshPlayerCards()
{
    QLayoutItem *item;
    while ((item = ui->playerCardsLayout->takeAt(0)) != nullptr) {
        if (item->widget() != nullptr) {
            delete item->widget();
        }
        delete item;
    }
    for(auto c : playerCards){

        QPixmap *image1 = c.getFace();
        ClickableLabel * label = new ClickableLabel(this);
        connect(label, &ClickableLabel::deleteRequested, this, &Makao::playerCardClicked);
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
        label->addCard(c);
        ui->playerCardsLayout->addWidget(label,0,items);
    }
}

void Makao::refreshOpponentCards()
{
    QLayoutItem *item;
    while ((item = ui->oppLayout->takeAt(0)) != nullptr) {
        if (item->widget() != nullptr) {
            delete item->widget();
        }
        delete item;
    }
    for(auto c : oppCards){
        QPixmap *image1 = new QPixmap("images/karty/back-removebg-preview.png");
        ClickableLabel * label = new ClickableLabel(this);
        label->resize(w,h);
        label->setPixmap((*image1).scaled(w,h,Qt::KeepAspectRatio));
        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(label);
        label->setGraphicsEffect(effect);

        QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
        animation->setDuration(500);
        animation->setStartValue(0.0);
        animation->setEndValue(1.0);
        animation->start();
        auto items = ui->oppLayout->count();
        label->addCard(c);
        ui->oppLayout->addWidget(label,0,items);
    }
}

void Makao::refreshTableCards()
{
    QLayoutItem *item;
    while ((item = ui->tableCardsLayout->takeAt(0)) != nullptr) {
        if (item->widget() != nullptr) {
            delete item->widget();
        }
        delete item;
    }
    for(auto c : tableCards){

        QPixmap *image1 = c.getFace();
        ClickableLabel * label = new ClickableLabel(this);
        connect(label, &ClickableLabel::deleteRequested, this, &Makao::playerCardClicked);
        label->resize(w,h);
        label->setPixmap((*image1).scaled(w,h,Qt::KeepAspectRatio));
        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(label);
        label->setGraphicsEffect(effect);

        QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
        animation->setDuration(500);
        animation->setStartValue(0.0);
        animation->setEndValue(1.0);
        animation->start();
        auto items = ui->tableCardsLayout->count();
        label->addCard(c);
        ui->tableCardsLayout->addWidget(label,0,items);
    }
}

void Makao::givePlayerCard()
{
    if(deck.empty())
        deck = Card::getCardSet();
    int r = rand() % deck.size();
    addPlayerCard(deck.at(r));
    deck.erase(next(deck.begin(), r));
}

void Makao::giveOpponentCard()
{
    if(deck.empty())
        deck = Card::getCardSet();
    int r = rand() % deck.size();
    addOpponentCard(deck.at(r));
    deck.erase(next(deck.begin(), r));
    refreshOpponentCards();
}

void Makao::oppTurn()
{
    ui->lblState->setText("Ruch przeciwnika");
    ui->btnGivePlayerCard->hide();
    delay(2000);
    bool hasCard = false;
    Card card;
    for(auto c : oppCards){
        if((c.getMakaoValue() == lastCard.getMakaoValue()) || (c.getSuit() == lastCard.getSuit())){
            card = c;
            hasCard = true;
        }
    }

    if(hasCard){
        auto it = std::find(oppCards.begin(), oppCards.end(), card);
        if (it != oppCards.end()) {
            oppCards.erase(it);
            addTableCard(card);
            refreshOpponentCards();

            lastCardForce = checkCardForce(card);
            if(lastCardForce == 2 || lastCardForce == 3 || lastCardForce == 5){
                for(int i = 0; i < lastCardForce; i++){
                    delay(1000);
                    givePlayerCard();
                }
            }
        }


        if(oppCards.size() == 0)QMessageBox::information(this, "Message", "Przegrana");
        if(lastCardForce == 4){
            oppTurn();
        }
    } else {
        giveOpponentCard();
        refreshOpponentCards();
    }

    delay(1000);
    ui->lblState->setText("Twój ruch");
    ui->btnGivePlayerCard->show();
}

void Makao::delay(int duration)
{
    QEventLoop eventLoop;
    QTimer::singleShot(duration, &eventLoop, &QEventLoop::quit);
    eventLoop.exec();
}

int Makao::checkCardForce(Card card)
{
    auto suit = card.getSuit();
    auto value = card.getMakaoValue();
    if(value == 2 || value == 3 || value == 4 || value == 11 || value == 14) return value;
    if(value == 13 && (suit == "kier" || suit == "pik")) return 5;
    return 0;
}

void Makao::on_btnStart_clicked()
{
    ui->btnGivePlayerCard->show();
    srand((unsigned)time(NULL));

    deck = Card::getCardSet();

    int r;

    for(int i=0; i<5; i++){
        r = rand() % deck.size();
        addPlayerCard(deck.at(r));
        deck.erase(next(deck.begin(), r));

        r = rand() % deck.size();
        addOpponentCard(deck.at(r));
        deck.erase(next(deck.begin(), r));
    }
    refreshPlayerCards();
    refreshOpponentCards();
    r = rand() % deck.size();
    auto startCard = deck.at(r);
    addTableCard(startCard);
}


void Makao::on_btnGivePlayerCard_clicked()
{
    givePlayerCard();
    oppTurn();
}


void Makao::on_btnRestart_clicked()
{
    playerCards.clear();
    oppCards.clear();
    tableCards.clear();
    refreshOpponentCards();
    refreshPlayerCards();
    refreshTableCards();
    on_btnStart_clicked();
}


void Makao::on_btnExit_clicked()
{
    playerCards.clear();
    oppCards.clear();
    tableCards.clear();
    refreshOpponentCards();
    refreshPlayerCards();
    refreshTableCards();
    this->close();
}

