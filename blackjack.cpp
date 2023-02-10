#include "blackjack.h"
#include "ui_blackjack.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QTimer>
#include <thread>

blackjack::blackjack(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::blackjack)
{
    int w=100, h=152;
    ui->setupUi(this);
    this->setFixedSize(this->size());

//    QPixmap image1("images/karty/as-kier.png");
//    QPixmap image2("images/karty/as-pik.png");
//    QPixmap image3("images/karty/as-karo.png");
//    QPixmap image4("images/karty/trefl/as-trefl.png");
//    QGridLayout *layout = new QGridLayout();
//    QLabel * Label = new QLabel(this);
//    Label->resize(w,h);
//    Label->setPixmap(image1.scaled(w,h,Qt::KeepAspectRatio));
//    QLabel * Label2 = new QLabel(this);
//    Label2->resize(w,h);
//    Label2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
//    QLabel * Label3 = new QLabel(this);
//    Label3->resize(w,h);
//    Label3->setPixmap(image3.scaled(w,h,Qt::KeepAspectRatio));
//    QLabel * Label4 = new QLabel(this);
//    Label4->resize(w,h);
//    Label4->setPixmap(image4.scaled(w,h,Qt::KeepAspectRatio));
//    layout->addWidget(Label,0,0);
//    layout->addWidget(Label2,0,1);
//    Label2->setGeometry(QRect(50,50,w,h));
//    layout->addWidget(Label3,0,2);
//    Label3->setGeometry(QRect(100,50,w,h));

//    layout->addWidget(Label4,0,3);
//    Label4->setGeometry(QRect(150,50,w,h));

//    QLabel * Label11 = new QLabel(this);
//    Label11->resize(w,h);
//    Label11->setPixmap(image1.scaled(w,h,Qt::KeepAspectRatio));
//    QLabel * Label12 = new QLabel(this);
//    Label12->resize(w,h);
//    Label12->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
//    QLabel * Label13 = new QLabel(this);
//    Label13->resize(w,h);
//    Label13->setPixmap(image3.scaled(w,h,Qt::KeepAspectRatio));
//    QLabel * Label14 = new QLabel(this);
//    Label14->resize(w,h);
//    Label14->setPixmap(image4.scaled(w,h,Qt::KeepAspectRatio));
//    layout->addWidget(Label11,1,0);
//    layout->addWidget(Label12,1,1);
//    Label12->setGeometry(QRect(50,50,w,h));
//    layout->addWidget(Label13,1,2);
//    Label13->setGeometry(QRect(100,50,w,h));

//    layout->addWidget(Label14,1,3);
//    Label14->setGeometry(QRect(150,50,w,h));
//    qInfo() << Label14->geometry();
//    this->setLayout(layout);

}



blackjack::~blackjack()
{
    delete ui;
}

void blackjack::buttonClicked()
{

}

void blackjack::setupCards()
{
    cards.clear();
    cards = Card::getCardSet();
}

Card blackjack::getCard()
{
    srand((unsigned)time(NULL));
    int r = rand() % cards.size();

    Card c = cards.at(r);
    cards.erase(next(cards.begin(), r));
    return c;
}

void blackjack::resetAll()
{
    while (QLayoutItem *item = ui->dealerCardsLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    ui->dealerCardsLayout->setContentsMargins(0, 0, 0, 0);

    while (QLayoutItem *item = ui->playerCardsLayout->takeAt(0)) {
        delete item->widget();
        delete item;
    }
    ui->playerCardsLayout->setContentsMargins(0, 0, 0, 0);

    ui->lblPlayerScore->setText("Twój wynik");
    ui->lblDealerScore->setText("Wynik dealera");
    ui->lblResult->setText("");
    setupCards();

}

void blackjack::on_btnStart_clicked()
{
    ui->btnStart->setDisabled(true);
    setupCards();
    int w=100, h=152;
    int wynik = 0;
        bool gameOn = true;
        while (gameOn)
        {
            auto los = getCard();

            QPixmap *image1 = los.getFace();
            QLabel * label = new QLabel(this);
            label->resize(w,h);
            label->setPixmap((*image1).scaled(w,h,Qt::KeepAspectRatio));
            auto items = ui->playerCardsLayout->count();
            qInfo() << "Items1: " << items;

            ui->playerCardsLayout->addWidget(label,0,items);
            los.printInfo();
            int val = los.getValue(true);
            if(val == 14){
                QString message = "Jaką wartość ma mieć as?";
                QMessageBox msgBox;
                msgBox.setText(message);
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::No);
                msgBox.setButtonText(QMessageBox::Yes, "1");
                msgBox.setButtonText(QMessageBox::No, "10");
                int ret = msgBox.exec();
                val = (ret == QMessageBox::Yes) ? 1 : 10;
            }

            wynik += val;
            QString str = "Twój wynik: " + QString::number(wynik);
            ui->lblPlayerScore->setText(str);
            if (wynik > 21) break;

            qInfo() << "Items2: " << items;
            QString message = str + ", czy chcesz kontynuować?";
            QMessageBox msgBox;
            msgBox.setText(message);
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            msgBox.setButtonText(QMessageBox::Yes, "Tak");
            msgBox.setButtonText(QMessageBox::No, "Nie");

            int ret = msgBox.exec();

            bool result = (ret == QMessageBox::Yes);

            gameOn = result;

        }

        ui->lblPlayerScore->setText("Twoj ostateczny wynik to: " + QString::number(wynik));

        int wynikD = 0;
        bool gameOnD = true;
        while (gameOnD)
        {
            auto los = getCard();
            QPixmap *image1 = los.getFace();
            QLabel * label = new QLabel(this);
            label->resize(w,h);
            label->setPixmap((*image1).scaled(w,h,Qt::KeepAspectRatio));
            auto items = ui->dealerCardsLayout->count();
            ui->dealerCardsLayout->addWidget(label,0,items);
            los.printInfo();
            wynikD += los.getValue(false);
            if (wynikD > 21) break;
            ui->lblDealerScore->setText("Wynik dealera: " + QString::number(wynikD));
            if (wynikD >= 18) {
                gameOnD = false;
            }
        }

        ui->lblDealerScore->setText("Ostateczny wynik dealera to: " + QString::number(wynikD));

        ui->lblResult->setText("");
        if (wynik > 21 && wynikD > 21) ui->lblResult->setText("Remis");
        else if (wynik > 21) ui->lblResult->setText("Przegrana.");
        else if (wynikD > 21) ui->lblResult->setText("Wygrana");
        else if (wynik > wynikD) ui->lblResult->setText("Wygrana");
        else if (wynik == wynikD) ui->lblResult->setText("Remis");
        else ui->lblResult->setText("Przegrana");

        ui->btnStart->setDisabled(false);

}


void blackjack::on_btnReset_clicked()
{
    resetAll();
}


void blackjack::on_btnExit_clicked()
{
    this->close();
}

