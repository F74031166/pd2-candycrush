#include "candy5.h"

candy5::candy5()
{
    //QObject::connect(button,SIGNAL(clicked()),this,SLOT(cleanc()));
}

candy5::~candy5()
{



}

void candy5::cleanc()
{
    emit value(pos_x,pos_y);
}

void candy5::setbutton(int x , int y , const QChar &tt)
{
    //button = new QPushButton(c);
    //button->setGeometry(50+x*40,80+y*40,35,35);
    qDebug()<<"type 5"<<endl;
    pos_x = x;
    pos_y = y;
    btt = tt;
    spec = 5;
    //button->setText(btt);
    //QObject::connect(button,SIGNAL(clicked()),this,SLOT(cleanc()));
}

int candy5::getspec()
{
    return spec;
}
