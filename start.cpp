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
                         "QLabel { color: white; }";
    qApp->setStyleSheet(styleSheet);
    qInfo() << qApp->styleSheet();
    int w = ui->imageLabel->width();
    int h = ui->imageLabel->height();

    QPixmap map("images/gryKarciane.jpg");
    map.size();
    ui->imageLabel->setPixmap(map.scaled(w,h,Qt::KeepAspectRatio));
    qInfo() << w << "  " << h;
//    ui->imageLabel
}

start::~start()
{
    delete ui;
}


void start::on_btnBlackjack_clicked()
{
    bj.showFullScreen();
}

