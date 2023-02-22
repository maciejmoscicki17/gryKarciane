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
    resetAll();
    playerDices.clear();
    enemyDices.clear();
    ui->btnReroll->setEnabled(false);
    this->setWindowTitle("Dices");
}

dice::~dice()
{
    delete ui;
}
void dice::on_btnStart_clicked()
{
    resetAll();
    QString message = "Runda 1, przelosuj kości, aby przejść do Rundy 2!";
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
    // wypełnienie wektorów std::vector<dice>
    playerDices.resize(5);
    enemyDices.resize(5);
    for (int i =0; i < 5; i++)
    {
        playerDices[i].setPipsOfDice();
        enemyDices[i].setPipsOfDice();
    }
    showDices(playerDices);
    ui->btnReroll->setEnabled(true);
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
    }
    QString message = "Runda 2, Twoje kości zostały przelosowane, o to kości przeciwnika: ";
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();

   resetAll();

    showDices(playerDices);
    showeEnemyDices(enemyDices);
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

    int maxPips = *std::max_element(pips.begin(), pips.end());
    if (maxPips == 5) {
        score += 50000;
        return score;
    } else if (maxPips == 4) {
        score += 40000;
    } else if (maxPips == 3) {
        score += 30000;
        if (*std::max_element(pips.begin(), pips.end()) == 2) {
            score += 20000;
            return score;
        }
    } else if (*std::max_element(pips.begin(), pips.end()) == 2) {
        int pairs = 0;
        for (int i = 0; i < 6; i++) {
            if (pips[i] == 2) {
                pairs++;
                score += (i + 1) * 10;
            }
        }
        if (pairs == 2) {
            score += 3000;
        } else {
            score += 1000;
        }
    }

    int stritCounter = 0;
    for (int i = 0; i < 6; i++) {
        if (pips[i] == 1) {
            stritCounter++;
        } else {
            stritCounter = 0;
        }
        if (stritCounter == 5) {
            score += 20000;
            return score;
        }
    }
    if (pips[0] == 1 && pips[1] == 1 && pips[2] == 1 && pips[3] == 1 && pips[4] == 1) {
        score += 10000;
        return score;
    }

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
        QPixmap* image = i.getFace();
        QLabel * label = new QLabel(this);
        label->resize(100,100);
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
}
void dice::showeEnemyDices(std::vector<dice> dices){
    for(auto i : dices) {
        QPixmap* image = i.getFace();
        QLabel * label = new QLabel(this);
        label->resize(100,100);
        label->setPixmap((*image).scaled(100,100,Qt::KeepAspectRatio));
        QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(label);
        label->setGraphicsEffect(effect);
        QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
        animation->setDuration(500);
        animation->setStartValue(0.0);
        animation->setEndValue(1.0);
        animation->start();
        auto items = ui->enemyDicesLayout->count();
        ui->enemyDicesLayout->addWidget(label,0,items);
    }
}
void dice::resetAll(){
    while (QLayoutItem *item = ui->enemyDicesLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    ui->enemyDicesLayout->setContentsMargins(0, 0, 0, 0);

    while (QLayoutItem *item = ui->playerDicesLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    ui->playerDicesLayout->setContentsMargins(0, 0, 0, 0);
    ui->lblResult->setText("");
    ui->cbDice_1->setChecked(false);
    ui->cbDice_2->setChecked(false);
    ui->cbDice_3->setChecked(false);
    ui->cbDice_4->setChecked(false);
    ui->cbDice_5->setChecked(false);
}



void dice::on_btnReset_clicked()
{
    resetAll();
    playerDices.clear();
    enemyDices.clear();
}


void dice::on_btnExit_clicked()
{
    resetAll();
    this->close();
}

