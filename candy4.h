#ifndef CANDY4_H
#define CANDY4_H
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

class candy4:public candy
{
public:
    candy4();
    virtual ~candy4();
    virtual void setbutton(int x , int y , const QChar &tt);
    virtual int getspec();
public slots:
    virtual void cleanc();
};

#endif // CANDY4_H
