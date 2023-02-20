#include "dice.h"
#include <iostream>
#include <map>

int dice::getPipsOfDice() { return numberOfPips; }
void dice::setPipsOfDice() { numberOfPips = rollDice(); }
int dice::rollDice() {
    srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    return rand() % 6 + 1;
}
void dice::rerollDices(std::vector<int> indexes, dice dices[]) {
    for (auto i : indexes) {
        dices[i].setPipsOfDice();
    }
}
bool dice::compare(dice a, dice b) { return a.getPipsOfDice() < b.getPipsOfDice(); }

void dice::prepare(dice dices[]) {
    std::sort(dices, dices + 5, compare);
}
void dice::check(dice dices[]) {
    std::vector<int> pips(6, 0);
    bool pair = false;
    bool triple = false;
    for (int i = 0; i < 5; i++) {
        pips[dices[i].getPipsOfDice() - 1]++;
    }
    for (int i = 0; i < 6; i++) {
        if (pips[i] == 2) {
            std::cout << "Gracz ma parę [" << i + 1 << "]" << std::endl;
            pair = true;
        }
        if (pips[i] == 3) {
            std::cout << "Gracz ma trójkę [" << i + 1  << "]" << std::endl;
            triple = true;
        }
        if (pips[i] == 4) {
            std::cout << "Gracz ma karetę [" << i + 1 << "]" << std::endl;
        }
        if (pips[i] == 5) {
            std::cout << "Gracz ma poker [" << i + 1 << "]" << std::endl;
        }
        if (triple && pair)
        {
            std::cout << "Gracz ma fulla!" << std::endl;
        }
    }

    prepare(this);
    int stritCounter = 0;
    for (int i = 0; i < 6; i++) {
        if (pips[i] == 1)  stritCounter++;
        else  stritCounter = 0;
        if (stritCounter == 5) std::cout << "Gracz ma strita!" << std::endl;
    }
}
int dice::calculateScore(dice dices[]) {
    std::vector<int> pips(6, 0);
    for (int i = 0; i < 5; i++) {
        pips[dices[i].getPipsOfDice() - 1]++;
    }

    // sprawdzanie kombinacji punktowanych
    int score = 0;
    bool pair = false;
    bool triple = false;
    for (int i = 0; i < 6; i++) {
        if (pips[i] == 2) {
            pair = true;
            score += (i + 1) * 10;
        }
        if (pips[i] == 3) {
            triple = true;
            score += (i + 1) * 100;
        }
        if (pips[i] == 4) {
            score += (i + 1) * 1000;
        }
        if (pips[i] == 5) {
            score += (i + 1) * 10000;
        }
        if (triple && pair)
        {
            score += 1000;
        }
    }

    // sprawdzanie strita
    std::sort(dices, dices + 5, dice::compare);
    int stritCounter = 0;
    for (int i = 0; i < 6; i++) {
        if (pips[i] == 1)  stritCounter++;
        else  stritCounter = 0;
        if (stritCounter == 5) {
            score += 1500;
            break;
        }
    }
    return score;
}
void dice::compareHands(dice player1[], dice player2[]) {
    int score1 = calculateScore(player1);
    int score2 = calculateScore(player2);
    if (score1 > score2) {
        std::cout << "Wygrywasz!";
    }
    else if (score2 > score1) {
        std::cout << "Przegrywasz!";
    }
    else {
        // W przypadku remisu sprawdź, która kombinacja ma wyższe wartości oczek
        for (int i = 4; i >= 0; i--) {
            if (player1[i].getPipsOfDice() > player2[i].getPipsOfDice()) {
                std::cout << "Wygrywasz!";
            }
            else if (player2[i].getPipsOfDice() > player1[i].getPipsOfDice()) {
                std::cout << "Przegrywasz!";
            }
        }
        std::cout << "Remis!"; // Remis - obaj gracze mają taką samą kombinację i takie same oczka
    }
}
dice::dice()  { setPipsOfDice(); }
