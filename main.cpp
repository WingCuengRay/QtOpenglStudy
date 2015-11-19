#include "mainwindow.h"
#include <QApplication>

#include <qapplication.h>
#include <qmessagebox.h>

#include "nehewidget.h"

int main(int argc, char *argv[])
{
    bool fs = false;

    QApplication a(argc,argv);

    switch( QMessageBox::information( 0,
        "Start FullScreen?",
        "Would You Like To Run In Fullscreen Mode?",
        QMessageBox::Yes,
        QMessageBox::No | QMessageBox::Default ) )
    {
    case QMessageBox::Yes:
      fs = true;
      break;
    case QMessageBox::No:
      fs = false;
      break;
    }

    NeHeWidget w;

    w.show();

    return a.exec();
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
}
