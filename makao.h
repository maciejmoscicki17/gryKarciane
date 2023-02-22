#ifndef MAKAO_H
#define MAKAO_H

#include "card.h"
#include "qlabel.h"
#include "qlayout.h"
#include <QDialog>

namespace Ui {
class Makao;
}
class ClickableLabel;

class Makao : public QDialog
{
    Q_OBJECT

public:
    explicit Makao(QWidget *parent = nullptr);
    ~Makao();
    void setupCards();
    void addOpponentCard(Card card);
    void addPlayerCard(Card card);
    void addTableCard(Card card);
    void playerCardClicked(ClickableLabel* lbl);
    Card lastCard;
    void refreshPlayerCards();
    void refreshOpponentCards();
    void refreshTableCards();
    void givePlayerCard();
    void giveOpponentCard();
    void oppTurn();
    void delay(int duration);
    int checkCardForce(Card card);
    int lastCardForce;

private slots:
    void on_btnStart_clicked();
    void on_btnGivePlayerCard_clicked();
    void on_btnRestart_clicked();
    void on_btnExit_clicked();

private:
    int w=100, h=152;
    Ui::Makao *ui;
    std::vector<Card> deck;
    std::vector<Card> oppCards;
    std::vector<Card> playerCards;
    std::vector<Card> tableCards;
};

class ClickableLabel : public QLabel {
    Q_OBJECT
public:
    Card card;

    explicit ClickableLabel(QWidget* parent = nullptr) : QLabel(parent) {}

    void mousePressEvent(QMouseEvent* event) override {
        Q_UNUSED(event);
        emit deleteRequested(this);
    }

    void addCard(Card c){
        card = c;
    }
signals:
    void deleteRequested(ClickableLabel *widget);
};
#endif // MAKAO_H
