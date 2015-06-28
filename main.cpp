#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QtGui>
#include <QPalette>
#include <QBrush>
#include <QGridLayout>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QEvent>
#include <QSlider>
#include <QDebug>
#include <QFocusEvent>
#include <QTimer>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *w=new QWidget;
    //w->resize(300,500);
    //QPushButton *startgame = new QPushButton(w);
    //startgame->setGeometry(100,200,100,50);
    game *g = new game(w);
    w->show();
    return a.exec();
}

