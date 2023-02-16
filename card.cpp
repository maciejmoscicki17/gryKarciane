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

std::vector<Card> Card::getCardSet()
{
//    std::vector<Card> cards;
//    cards.push_back(Card("kier", 2));
//    cards.push_back(Card("kier", 3));
//    cards.push_back(Card("kier", 4));
//    cards.push_back(Card("kier", 5));
//    cards.push_back(Card("kier", 6));
//    cards.push_back(Card("kier", 7));
//    cards.push_back(Card("kier", 8));
//    cards.push_back(Card("kier", 9));
//    cards.push_back(Card("kier", 10));
//    cards.push_back(Card("kier", 11));
//    cards.push_back(Card("kier", 12));
//    cards.push_back(Card("kier", 13));
//    cards.push_back(Card("kier", 14));
//    cards.push_back(Card("karo", 2));
//    cards.push_back(Card("karo", 3));
//    cards.push_back(Card("karo", 4));
//    cards.push_back(Card("karo", 5));
//    cards.push_back(Card("karo", 6));
//    cards.push_back(Card("karo", 7));
//    cards.push_back(Card("karo", 8));
//    cards.push_back(Card("karo", 9));
//    cards.push_back(Card("karo", 10));
//    cards.push_back(Card("karo", 11));
//    cards.push_back(Card("karo", 12));
//    cards.push_back(Card("karo", 13));
//    cards.push_back(Card("karo", 14));
//    cards.push_back(Card("pik", 2));
//    cards.push_back(Card("pik", 3));
//    cards.push_back(Card("pik", 4));
//    cards.push_back(Card("pik", 5));
//    cards.push_back(Card("pik", 6));
//    cards.push_back(Card("pik", 7));
//    cards.push_back(Card("pik", 8));
//    cards.push_back(Card("pik", 9));
//    cards.push_back(Card("pik", 10));
//    cards.push_back(Card("pik", 11));
//    cards.push_back(Card("pik", 12));
//    cards.push_back(Card("pik", 13));
//    cards.push_back(Card("pik", 14));
//    cards.push_back(Card("trefl", 2));
//    cards.push_back(Card("trefl", 3));
//    cards.push_back(Card("trefl", 4));
//    cards.push_back(Card("trefl", 5));
//    cards.push_back(Card("trefl", 6));
//    cards.push_back(Card("trefl", 7));
//    cards.push_back(Card("trefl", 8));
//    cards.push_back(Card("trefl", 9));
//    cards.push_back(Card("trefl", 10));
//    cards.push_back(Card("trefl", 11));
//    cards.push_back(Card("trefl", 12));
//    cards.push_back(Card("trefl", 13));
//    cards.push_back(Card("trefl", 14));
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
    /*
    if(suit=="trefl" && value == 2) return new QPixmap("images/karty/trefl/2.png");
    if(suit=="trefl" && value == 3) return new QPixmap("images/karty/trefl/3.png");
    if(suit=="trefl" && value == 4) return new QPixmap("images/karty/trefl/4.png");
    if(suit=="trefl" && value == 5) return new QPixmap("images/karty/trefl/5.png");
    if(suit=="trefl" && value == 6) return new QPixmap("images/karty/trefl/6.png");
    if(suit=="trefl" && value == 7) return new QPixmap("images/karty/trefl/7.png");
    if(suit=="trefl" && value == 8) return new QPixmap("images/karty/trefl/8.png");
    if(suit=="trefl" && value == 9) return new QPixmap("images/karty/trefl/9.png");
    if(suit=="trefl" && value == 10) return new QPixmap("images/karty/trefl/10.png");
    if(suit=="trefl" && value == 11) return new QPixmap("images/karty/trefl/walet.png");
    if(suit=="trefl" && value == 12) return new QPixmap("images/karty/trefl/dama.png");
    if(suit=="trefl" && value == 13) return new QPixmap("images/karty/trefl/krol.png");
    if(suit=="trefl" && value == 14) return new QPixmap("images/karty/trefl/as.png");

    if(suit=="kier" && value == 2) return new QPixmap("images/karty/kier/2.png");
    if(suit=="kier" && value == 3) return new QPixmap("images/karty/kier/3.png");
    if(suit=="kier" && value == 4) return new QPixmap("images/karty/kier/4.png");
    if(suit=="kier" && value == 5) return new QPixmap("images/karty/kier/5.png");
    if(suit=="kier" && value == 6) return new QPixmap("images/karty/kier/6.png");
    if(suit=="kier" && value == 7) return new QPixmap("images/karty/kier/7.png");
    if(suit=="kier" && value == 8) return new QPixmap("images/karty/kier/8.png");
    if(suit=="kier" && value == 9) return new QPixmap("images/karty/kier/9.png");
    if(suit=="kier" && value == 10) return new QPixmap("images/karty/kier/10.png");
    if(suit=="kier" && value == 11) return new QPixmap("images/karty/kier/walet.png");
    if(suit=="kier" && value == 12) return new QPixmap("images/karty/kier/dama.png");
    if(suit=="kier" && value == 13) return new QPixmap("images/karty/kier/krol.png");
    if(suit=="kier" && value == 14) return new QPixmap("images/karty/kier/as.png");

    if(suit=="pik" && value == 2) return new QPixmap("images/karty/pik/2.png");
    if(suit=="pik" && value == 3) return new QPixmap("images/karty/pik/3.png");
    if(suit=="pik" && value == 4) return new QPixmap("images/karty/pik/4.png");
    if(suit=="pik" && value == 5) return new QPixmap("images/karty/pik/5.png");
    if(suit=="pik" && value == 6) return new QPixmap("images/karty/pik/6.png");
    if(suit=="pik" && value == 7) return new QPixmap("images/karty/pik/7.png");
    if(suit=="pik" && value == 8) return new QPixmap("images/karty/pik/8.png");
    if(suit=="pik" && value == 9) return new QPixmap("images/karty/pik/9.png");
    if(suit=="pik" && value == 10) return new QPixmap("images/karty/pik/10.png");
    if(suit=="pik" && value == 11) return new QPixmap("images/karty/pik/walet.png");
    if(suit=="pik" && value == 12) return new QPixmap("images/karty/pik/dama.png");
    if(suit=="pik" && value == 13) return new QPixmap("images/karty/pik/krol.png");
    if(suit=="pik" && value == 14) return new QPixmap("images/karty/pik/as.png");

    if(suit=="karo" && value == 2) return new QPixmap("images/karty/karo/2.png");
    if(suit=="karo" && value == 3) return new QPixmap("images/karty/karo/3.png");
    if(suit=="karo" && value == 4) return new QPixmap("images/karty/karo/4.png");
    if(suit=="karo" && value == 5) return new QPixmap("images/karty/karo/5.png");
    if(suit=="karo" && value == 6) return new QPixmap("images/karty/karo/6.png");
    if(suit=="karo" && value == 7) return new QPixmap("images/karty/karo/7.png");
    if(suit=="karo" && value == 8) return new QPixmap("images/karty/karo/8.png");
    if(suit=="karo" && value == 9) return new QPixmap("images/karty/karo/9.png");
    if(suit=="karo" && value == 10) return new QPixmap("images/karty/karo/10.png");
    if(suit=="karo" && value == 11) return new QPixmap("images/karty/karo/walet.png");
    if(suit=="karo" && value == 12) return new QPixmap("images/karty/karo/dama.png");
    if(suit=="karo" && value == 13) return new QPixmap("images/karty/karo/krol.png");
    if(suit=="karo" && value == 14) return new QPixmap("images/karty/karo/as.png");*/

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
