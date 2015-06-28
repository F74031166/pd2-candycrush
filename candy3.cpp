#include "candy3.h"

candy3::candy3()
{
    //QObject::connect(button,SIGNAL(clicked()),this,SLOT(cleanc()));
}

candy3::~candy3()
{



}

void candy3::cleanc()
{
    emit value(pos_x,pos_y);
}

void candy3::setbutton(int x , int y , const QChar &tt)
{
    //button = new QPushButton(c);
    //button->setGeometry(50+x*40,80+y*40,35,35);
    qDebug()<<"type 8"<<endl;
    pos_x = x;
    pos_y = y;
    btt = tt;
    spec = 8;
    //button->setText(btt);
    //QObject::connect(button,SIGNAL(clicked()),this,SLOT(cleanc()));
}

int candy3::getspec()
{
    return spec;
}
