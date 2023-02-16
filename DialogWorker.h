#ifndef DIALOGWORKER_H
#define DIALOGWORKER_H
#include "qmessagebox.h"
#include "qobject.h"
class DialogWorker : public QObject
{
    Q_OBJECT
public:
    DialogWorker(QString str, QObject *parent = nullptr)
        : QObject(parent)
        , str(str)
    {}

public slots:
    void process()
    {
        QString message = str + ", czy chcesz kontynuować?";
        QMessageBox msgBox;
        msgBox.setText(message);
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes, "Tak");
        msgBox.setButtonText(QMessageBox::No, "Nie");

        int ret = msgBox.exec();

        bool result = (ret == QMessageBox::Yes);

        emit finished(result);
    }

signals:
    void finished(bool result);

private:
    QString str;
};
#endif // DIALOGWORKER_H
