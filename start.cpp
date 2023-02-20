#include "start.h"
#include "ui_start.h"
using namespace std;

start::start(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::start)
{
    ui->setupUi(this);
    QString styleSheet = "* {background-color:#202020;}"
                        "QPushButton { background-color: #2e2f30; color: white;}"
                         "QLabel { color: white; font-size: 30px; }"
                         "QGridLayout { display: flex;"
                         "justify-content: flex-start;}";
    qApp->setStyleSheet(styleSheet);
    int w = ui->imageLabel->width();
    int h = ui->imageLabel->height();
    ui->lblTitle->setText("Gry karciane");
    ui->lblTitle->setAlignment(Qt::AlignCenter);

    QPixmap map("images/gryKarciane-removebg.png");
    map.size();
    ui->imageLabel->setPixmap(map.scaled(w,h,Qt::KeepAspectRatio));
}

start::~start()
{
    delete ui;
}


void start::on_btnBlackjack_clicked()
{
    bj.showFullScreen();
}


void start::on_btnTest_clicked()
{
    mk.showFullScreen();
}

