#include "mainwindow.h"
#include "linecharwidget.h"
#include <QApplication>
#include <QSqlDatabase>
#include "signin_gui.h"
#include <QTime>
#include <QWaitCondition>
void delaymsec(int msec)
{

    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Signin_GUI signin;
    MainWindow w;

    signin.show();
    if(signin.exec() == true)
    {
        delaymsec(2000);
        w.show();
        return a.exec();
    }
}
