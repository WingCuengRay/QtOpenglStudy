#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    neheWidget = new NeHeWidget();
//    setGeometry(100,100,1000,768);
//    setWindowTitle(tr("NeHe's OpenGL Framework"));
//    setCentralWidget(neheWidget);
}


MainWindow::~MainWindow()
{
}


void MainWindow::keyPressEvent(QKeyEvent *e)
{
    switch ( e->key() )
      {
      case Qt::Key_F2:
        fullscreen = !fullscreen;
        if ( fullscreen )
        {
          showFullScreen();
        }
        else
        {
          showNormal();
        }
      neheWidget->updateGL();
        break;
      case Qt::Key_Escape:
       close();
        break;
     }
}
