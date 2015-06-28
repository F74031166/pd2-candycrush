#include "candy1.h"

candy1::candy1()
{
    //QObject::connect(button,SIGNAL(clicked()),this,SLOT(cleanc()));
}

candy1::~candy1()
{



}

void candy1::cleanc()
{
    emit value(pos_x,pos_y);
}

void candy1::setbutton(int x , int y , const QChar &tt)
{
    //button = new QPushButton(c);
    //button->setGeometry(50+x*40,80+y*40,35,35);
    pos_x = x;
    pos_y = y;
    btt = tt;
    spec = 0;
    //button->setText(btt);
    //QObject::connect(button,SIGNAL(clicked()),this,SLOT(cleanc()));
}


int candy1::getspec()
{
    return spec;
}
