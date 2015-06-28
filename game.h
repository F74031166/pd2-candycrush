#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
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
#include "candy.h"
#include "candy1.h"
#include "candy2.h"
#include "candy3.h"
#include "candy4.h"
#include "candy5.h"

class game:public QWidget
{
    Q_OBJECT
public:
    game(QWidget *parent = 0);
    ~game();
    bool check();
    void generate();
    void fall();
    void showcandy();
    //QWidget *mainwin;
    void clean();
    bool checkchange();
    void change();
    void deletearr();
public slots:
    //void start();
    void Click(int nx, int ny);
private:
    candy *candy_b[10][10];
    QPushButton *quit;
    QPushButton *basic[10][10];
    QString sweet[12];
    QString specials[18];
    char candytable[11][11];
    int cleantarget[10][10];
    int clicktime;
    bool exchange,s,chocolate;
    int x1,y1,x2,y2;
    QLabel *p;
};

#endif // GAME_H
