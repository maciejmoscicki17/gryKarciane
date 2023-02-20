#ifndef START_H
#define START_H

#include <QMainWindow>
#include "blackjack.h"
#include "makao.h"
QT_BEGIN_NAMESPACE
namespace Ui { class start; }
QT_END_NAMESPACE

class start : public QMainWindow
{
    Q_OBJECT

public:
    start(QWidget *parent = nullptr);
    ~start();
    blackjack bj;
    Makao mk;

private slots:
    void on_btnBlackjack_clicked();

    void on_btnTest_clicked();

private:
    Ui::start *ui;
};
#endif // START_H
