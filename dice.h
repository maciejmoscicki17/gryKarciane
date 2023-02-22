#ifndef DICE_H
#define DICE_H

#include <QDialog>
#include <QWidget>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <random>
#include <chrono>
#include <algorithm>
#include "ui_dice.h"
#include "qpixmap.h"

namespace Ui {
class dice;
}

class dice : public QDialog
{
    Q_OBJECT

public:
    explicit dice(QWidget *parent = nullptr);
    std::vector<dice> playerDices;
    std::vector<dice> enemyDices;
    ~dice();
    dice(const dice &other); // konstruktor kopiujący
    dice &operator=(const dice &other); // operator przypisania
    void setPipsOfDice();
    int getPipsOfDice() const;
    int rollDice();
    void rerollDices(std::vector<int> indexes, std::vector<dice> &dices);
    static bool compare(const dice &a, const dice &b);
    void check(std::vector<dice> dices);
    void prepare(std::vector<dice> &dices);
    int calculateScore(const std::vector<dice>& dices);
    QString compareHands(const std::vector<dice>& playerDices, const std::vector<dice>& enemyDices);
    QPixmap* getFace();
    void showDices(std::vector<dice> dices);
    void showeEnemyDices(std::vector<dice> dices);
    void resetAll();
private:
    Ui::dice *ui;
    int numberOfPips = 0;
    QString suit;
private slots:
    void on_btnStart_clicked();
    void on_btnReroll_clicked();
    void on_btnReset_clicked();
    void on_btnExit_clicked();
};

#endif // DICE
