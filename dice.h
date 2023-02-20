#ifndef DICE_H
#define DICE_H
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <chrono>
#include <algorithm>

class dice
{
private:
    int numberOfPips = 0;
public:
    void setPipsOfDice();
    int getPipsOfDice();
    int rollDice();
    void rerollDices(std::vector<int> indexes, dice dices[]);
    static bool compare(dice a, dice b);
    void prepare(dice dices[]);
    void check(dice dices[]);
    int calculateScore(dice dices[]);
    void compareHands(dice player1[], dice player2[]);
    dice();
};

#endif // DICE_H
