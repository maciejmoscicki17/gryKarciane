#include "dice.h"
#include "ui_dice.h"
#include <iostream>
#include <map>
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
#include <QtDebug>
#include <cstdlib>
dice::dice(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dice)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    playerDices.clear();
    enemyDices.clear();
}

dice::~dice()
{
    delete ui;
}
void dice::on_btnStart_clicked()
{
    QString message = "Runda 1, przelosuj kości, aby przejść do Rundy 2!";
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
    // wypełnienie wektorów std::vector<dice>
    playerDices.resize(5);
    enemyDices.resize(5);
    qDebug() << "start";
    for (int i =0; i < 5; i++)
    {
        playerDices[i].setPipsOfDice();
        qDebug() << "p" << playerDices[i].getPipsOfDice();
        enemyDices[i].setPipsOfDice();
        qDebug() <<"e" << enemyDices[i].getPipsOfDice();
    }
    showDices(playerDices);

}

void dice::on_btnReroll_clicked()
{
    std::vector<int> indexes;
    if (ui->cbDice_1->isChecked()) { indexes.push_back(0); }
    if (ui->cbDice_2->isChecked()) { indexes.push_back(1); }
    if (ui->cbDice_3->isChecked()) { indexes.push_back(2); }
    if (ui->cbDice_4->isChecked()) { indexes.push_back(3); }
    if (ui->cbDice_5->isChecked()) { indexes.push_back(4); }
    if (!indexes.empty()) {
        rerollDices(indexes, playerDices);
        qDebug() << "-";
        for (int i = 0; i < 5; i++) {
            qDebug() << playerDices[i].getPipsOfDice();
        }
    }
    QString message = "Runda 2, Twoje kości zostały przelosowane, o to kości przeciwnika: ";
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
    ui->lblResult->setText(compareHands(playerDices, enemyDices));

}

dice &dice::operator=(const dice &other)
{
    if (this != &other) {
        this->numberOfPips = 0;
        this->numberOfPips = other.numberOfPips;
    }
    return *this;
}

dice::dice(const dice &other) : ui(new Ui::dice)
{
    this->numberOfPips = 0;
    this->numberOfPips = other.numberOfPips;
}

int dice::getPipsOfDice() const
{
    return numberOfPips;
}

void dice::setPipsOfDice()
{
    numberOfPips = rollDice();
}

int dice::rollDice()
{
    std::random_device srng;
    std::mt19937 rng;
    rng.seed(srng());
    std::uniform_int_distribution<int> range(1, 6);
    return range(rng);
}

void dice::rerollDices(std::vector<int> indexes, std::vector<dice> &dices)
{
    for (auto i : indexes) {
        dices[i].setPipsOfDice();
        qDebug() << i << "indx";
    }
}

void dice::prepare(std::vector<dice> &dices)
{
    std::sort(dices.begin(), dices.end(), &compare);
}

void dice::check(std::vector<dice> dices) {

}

bool dice::compare(const dice &a, const dice &b)
{
    return a.getPipsOfDice() < b.getPipsOfDice();
}

int dice::calculateScore(const std::vector<dice>& dices) {
    std::vector<int> pips(6, 0);
    for (size_t i = 0; i < dices.size(); i++) {
        pips[dices[i].getPipsOfDice() - 1]++;
    }

    int score = 0;

    // Sprawdzenie czy jest full, kareta lub generł (wszystkie kostki takie same)
    int maxPips = *std::max_element(pips.begin(), pips.end());
    if (maxPips == 5) { // Generał
        score += 50000;
        return score;
    } else if (maxPips == 4) { // Kareta
        score += 40000;
    } else if (maxPips == 3) { // Trójka
        score += 30000;
        if (*std::max_element(pips.begin(), pips.end()) == 2) { // Full
            score += 20000;
            return score;
        }
    } else if (*std::max_element(pips.begin(), pips.end()) == 2) { // Para lub dwie pary
        int pairs = 0;
        for (int i = 0; i < 6; i++) {
            if (pips[i] == 2) {
                pairs++;
                score += (i + 1) * 10;
            }
        }
        if (pairs == 2) { // Dwie pary
            score += 3000;
        } else { // Para
            score += 1000;
        }
    }

    // Sprawdzenie czy jest strit
    int stritCounter = 0;
    for (int i = 0; i < 6; i++) {
        if (pips[i] == 1) {
            stritCounter++;
        } else {
            stritCounter = 0;
        }
        if (stritCounter == 5) { // Duży strit
            score += 20000;
            return score;
        }
    }
    if (pips[0] == 1 && pips[1] == 1 && pips[2] == 1 && pips[3] == 1 && pips[4] == 1) { // Mały strit
        score += 10000;
        return score;
    }

    // W pozostałych przypadkach sumujemy punkty za każdą kostkę
    for (int i = 0; i < 6; i++) {
        score += (i + 1) * pips[i];
    }

    return score;
}
QString dice::compareHands(const std::vector<dice>& playerDices, const std::vector<dice>& enemyDices)
{
    int playerScore = calculateScore(playerDices);
    int enemyScore = calculateScore(enemyDices);
    if (playerScore > enemyScore) {
        return "Wygrałeś!";
    }
    else if (playerScore < enemyScore) {
        return "Przegrałeś!";
    }
    else {
        return "Remis!";
    }
}
QPixmap* dice::getFace()
{

    QString filename = QString("images/kości/%1.png");

    switch (this->getPipsOfDice()) {
    case 1: {
        filename = filename.arg("dice1");
        break;
    }
    case 2: {
        filename = filename.arg("dice2");
        break;
    }
    case 3: {
        filename = filename.arg("dice3");
        break;
    }
    case 4: {
        filename = filename.arg("dice4");
        break;
    }
    case 5: {
        filename = filename.arg("dice5");
        break;
    }
    case 6: {
        filename = filename.arg("dice6");
        break;
    }
    }

    return new QPixmap(filename);
}

void dice::showDices(std::vector<dice> dices){
    for(auto i : dices) {
        qDebug() << "a";
        QPixmap* image = i.getFace();
        QLabel * label = new QLabel(this);
        label->resize(100,100);
        qDebug() << "re";
        label->setPixmap((*image).scaled(100,100,Qt::KeepAspectRatio));
        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(label);
        label->setGraphicsEffect(effect);
        QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
        animation->setDuration(500);
        animation->setStartValue(0.0);
        animation->setEndValue(1.0);
        animation->start();
        auto items = ui->playerDicesLayout->count();
        ui->playerDicesLayout->addWidget(label,0,items);
    }


//    QLabel * label = new QLabel(this);
//    QPixmap* image = new QPixmap("images/karty/kier/10.png");
//    label->setPixmap(( *image).scaled(100,100,Qt::KeepAspectRatio));
//    ui->playerDicesLayout->addWidget(label);
}


