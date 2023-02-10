#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <QDialog>
#include "card.h"

namespace Ui {
class blackjack;
}

class blackjack : public QDialog
{
    Q_OBJECT

public:
    explicit blackjack(QWidget *parent = nullptr);
    ~blackjack();
    void buttonClicked();
    void setupCards();
    Card getCard();
    void resetAll();
private slots:
    void on_btnStart_clicked();

    void on_btnReset_clicked();

    void on_btnExit_clicked();

private:
    int w=100, h=152;
    Ui::blackjack *ui;
    std::vector<Card> cards;

};

#endif // BLACKJACK_H
