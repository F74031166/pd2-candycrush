#ifndef CANDY3_H
#define CANDY3_H
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

class candy3:public candy
{
public:
    candy3();
    virtual ~candy3();
    virtual void setbutton(int x , int y , const QChar &tt);
    virtual int getspec();
public slots:
    virtual void cleanc();

};

#endif // CANDY3_H
