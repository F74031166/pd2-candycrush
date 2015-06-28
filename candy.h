#ifndef CANDY_H
#define CANDY_H
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


class candy:public QWidget
{
    Q_OBJECT
public:
    candy();
    virtual ~candy();
    virtual void setbutton(int x , int y , const QChar &tt) = 0;
    virtual int getspec() = 0;
    int spec;
    int pos_x,pos_y;
    QChar btt;
    //QPushButton *button;

public slots:
    virtual void cleanc() = 0;//virtual
signals:
    void value(int x,int y);


};

#endif // CANDY_H
