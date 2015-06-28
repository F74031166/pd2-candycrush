#include "candy4.h"

candy4::candy4()
{
    //QObject::connect(button,SIGNAL(clicked()),this,SLOT(cleanc()));
}

candy4::~candy4()
{



}

void candy4::cleanc()
{
    emit value(pos_x,pos_y);
}


void candy4::setbutton(int x , int y , const QChar &tt)
{
    //button = new QPushButton(c);
    //button->setGeometry(50+x*40,80+y*40,35,35);
    qDebug()<<"type 3"<<endl;
    pos_x = x;
    pos_y = y;
    btt = tt;
    spec = 3;
    //button->setText(btt);
    //QObject::connect(button,SIGNAL(clicked()),this,SLOT(cleanc()));
}

int candy4::getspec()
{
    return spec;
}
