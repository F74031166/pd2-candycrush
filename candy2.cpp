#include "candy2.h"

candy2::candy2()
{
    //QObject::connect(button,SIGNAL(clicked()),this,SLOT(cleanc()));
}

candy2::~candy2()
{



}

void candy2::cleanc()
{
    emit value(pos_x,pos_y);
}

void candy2::setbutton(int x , int y , const QChar &tt)
{
    //button = new QPushButton(c);
    //button->setGeometry(50+x*40,80+y*40,35,35);
    qDebug()<<"type 4"<<endl;
    pos_x = x;
    pos_y = y;
    btt = tt;
    spec = 4;
    //button->setText(btt);
    //QObject::connect(button,SIGNAL(clicked()),this,SLOT(cleanc()));
}

int candy2::getspec()
{
    return spec;
}
