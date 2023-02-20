#include "Card.h"
#include <iostream>
#include <vector>
#include <QDir>
#include <QDebug>
#include <QString>
using namespace std;

Card::Card(string s, int v)
{
    suit = s;
    value = v;
}

Card::Card()
{
}

Card::~Card()
{
}

int Card::getValue(bool isPlayer) {
    if (value == 14 && isPlayer) {
        return 14;
    }
    if (value > 10) return 10;
    else return value;
}

int Card::getMakaoValue()
{
    return value;
}

std::vector<Card> Card::getCardSet()
{
    const std::array<std::string, 4> suits = {"kier", "karo", "pik", "trefl"};
    std::vector<Card> cards;
    for (const auto& suit : suits) {
        for (int value = 2; value <= 14; ++value) {
            cards.push_back(Card(suit, value));
        }
    }
    return cards;
}

QPixmap* Card::getFace()
{

    QString filename = QString("images/karty/%1/%2.png").arg(QString::fromStdString(suit));
    if (value >= 2 && value <= 10)
        filename = filename.arg(value);
    else if (value == 11)
        filename = filename.arg("walet");
    else if (value == 12)
        filename = filename.arg("dama");
    else if (value == 13)
        filename = filename.arg("krol");
    else if (value == 14)
        filename = filename.arg("as");

    return new QPixmap(filename);
}

QString Card::getImgSrc()
{
    return "";
}

void Card::printInfo() {
    if (value == 11) cout << "Jack ";
    else if (value == 12) cout << "Queen ";
    else if (value == 13) cout << "King ";
    else if (value == 14) cout << "Ace ";
    else cout << value << " ";

    cout << suit << endl;
}

string Card::getSuit() {
    return suit;
}
