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
    string getSuit();
    static vector<Card> getCardSet();
    QPixmap* getFace();
    QString getImgSrc();
private:
    int value;
    string suit;
};

#endif // CARD_H
