#ifndef CARD_H
#define CARD_H

#include "qpixmap.h"
#include <string>
#include <vector>
using namespace std;

class Card
{
public:
    Card(string, int);
    Card();
    ~Card();
    void printInfo();
    int getValue(bool isPlayer);
    int getMakaoValue();
    string getSuit();
    static vector<Card> getCardSet();
    QPixmap* getFace();
    QString getImgSrc();
    bool operator==(const Card& other) const {
            return this->value == other.value && this->suit == other.suit;
        }

private:
    int value;
    string suit;
};

#endif // CARD_H
