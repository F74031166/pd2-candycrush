#ifndef CANDY2_H
#define CANDY2_H
#include "candy.h"
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

class candy2:public candy
{
public:
    candy2();
    virtual ~candy2();
    virtual void setbutton(int x , int y , const QChar &tt);
    virtual int getspec();
public slots:
    virtual void cleanc();

};

#endif // CANDY2_H
