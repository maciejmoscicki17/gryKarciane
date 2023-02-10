#include "start.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Roboto", 12);
    a.setFont(font);
    start w;
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    return a.exec();
}
