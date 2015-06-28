#include "game.h"
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

game::game(QWidget *parent):QWidget(parent)
{
    //mainwin = parent;
    //QPushButton *startgame = new QPushButton(parent);
    //startgame->setGeometry(100,200,100,50);
    sweet[0] = "border-image:url(:/candy/2.png);";
    sweet[1] = "border-image:url(:/candy/4.png);";
    sweet[2] = "border-image:url(:/candy/8.png);";
    sweet[3] = "border-image:url(:/candy/16.png);";
    sweet[4] = "border-image:url(:/candy/32.png);";
    sweet[5] = "border-image:url(:/candy/64.png);";
    sweet[6] = "border-image:url(:/candy/128.png);";
    sweet[7] = "border-image:url(:/candy/256.png);";
    sweet[8] = "border-image:url(:/candy/512.png);";
    sweet[9] = "border-image:url(:/candy/1024.png);";
    sweet[10] = "border-image:url(:/candy/2048.png);";
    sweet[11] = "#p{border-image:url(:/candy/oneal.jpg);}";
    specials[0] = "border-image:url(:/candy/2_row.png);";
    specials[1] = "border-image:url(:/candy/2_col.png);";
    specials[2] = "border-image:url(:/candy/2_bomb.png);";
    specials[3] = "border-image:url(:/candy/4_row.png);";
    specials[4] = "border-image:url(:/candy/4_col.png);";
    specials[5] = "border-image:url(:/candy/4_bomb.png);";
    specials[6] = "border-image:url(:/candy/8_row.png);";
    specials[7] = "border-image:url(:/candy/8_col.png);";
    specials[8] = "border-image:url(:/candy/8_bomb.png);";
    specials[9] = "border-image:url(:/candy/16_row.png);";
    specials[10] = "border-image:url(:/candy/16_col.png);";
    specials[11] = "border-image:url(:/candy/16_bomb.png);";
    specials[12] = "border-image:url(:/candy/32_row.png);";
    specials[13] = "border-image:url(:/candy/32_col.png);";
    specials[14] = "border-image:url(:/candy/32_bomb.png);";
    specials[15] = "border-image:url(:/candy/64_row.png);";
    specials[16] = "border-image:url(:/candy/64_col.png);";
    specials[17] = "border-image:url(:/candy/64_bomb.png);";
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            if(i==10||j==10)
                candytable[i][j] = 't';
            else
            {
                candytable[i][j] = 'n';
                cleantarget[i][j] = 0;
            }
        }
    }
    s = false;
    exchange = false;
    chocolate = false;
    //unchange = false;
    //qDebug()<<"gg"<<endl;
    generate();
    while(check()==false)
    {
        clean();
        fall();
        generate();
    }
    s = true;
    //qDebug()<<"gg"<<endl;
    //parent->close();
    //parent = new QWidget;
    parent->setObjectName("p");
    parent->resize(500,500);
    parent->setStyleSheet(sweet[11]);
    quit = new QPushButton(parent);
    quit->setGeometry(210,40,40,20);
    QObject::connect(quit,SIGNAL(clicked()),parent,SLOT(close()));
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cleantarget[i][j] = 0;
        }
    }
    //qDebug()<<"before output"<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            basic[i][j] = new QPushButton(parent);
            basic[i][j]->setGeometry(50+j*40,80+i*40,35,35);
        }
    }
    showcandy();
    //qDebug()<<"after output"<<endl;
    //QObject::connect(startgame,SIGNAL(clicked()),this,SLOT(start()));
    //QObject::connect(startgame,SIGNAL(clicked()),parent,SLOT(close()));
}

game::~game()
{
    delete this;
}
/*
void game::start()
{
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            if(i==10||j==10)
                candytable[i][j] = 't';
            else
            {
                candytable[i][j] = 'n';
                cleantarget[i][j] = 0;
            }
        }
    }
    s = false;
    exchange = false;
    chocolate = false;
    qDebug()<<"gg"<<endl;
    generate();
    while(check()==false)
    {
        clean();
        fall();
        generate();
    }
    s = true;
    qDebug()<<"gg"<<endl;
    mainwin = new QWidget;
    mainwin->resize(500,500);
    quit = new QPushButton(mainwin);
    quit->setGeometry(210,40,40,20);
    QObject::connect(quit,SIGNAL(clicked()),mainwin,SLOT(close()));
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cleantarget[i][j] = 0;
        }
    }
    qDebug()<<"before output"<<endl;
    showcandy();
    qDebug()<<"after output"<<endl;
    //mainwin->show();
}
*/

void game::generate()
{
    char base[10] = {'a','b','c','d','e','f','g','h','i','j'};
    int temp;
    srand((int)time(NULL));
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(candytable[i][j]=='n')
            {
                temp = rand()%6;
                candytable[i][j] = base[temp];
            }
        }
    }
    //qDebug()<<"generate ok"<<endl;
}

bool game::check()
{
    //qDebug()<<"check ok"<<endl;//
    char target;
    int isclean;
    int i,j;
    for(i=0;i<10;i++)
    {
        j = 0;
        target = candytable[i][j];
        isclean = 0;
        for(j=1;j<10;j++)
        {
            if(candytable[i][j]==target)
            {
                isclean++;
            }
            else
            {
                target = candytable[i][j];
                isclean = 0;
            }
            if(isclean==2)
                return false;
        }
    }
    for(j=0;j<10;j++)
    {
        i = 0;
        target = candytable[i][j];
        isclean = 0;
        for(i=1;i<10;i++)
        {
            if(candytable[i][j]==target)
            {
                isclean++;
            }
            else
            {
                target = candytable[i][j];
                isclean = 0;
            }
            if(isclean==2)
                return false;
        }
    }
    return true;
}


void game::clean()
{
    char target,killt;
    int isclean,more;
    int i,j;
    int count;
    int kill,killb,killr,killc,kills;
    if(chocolate==false)
    {
        for(i=0;i<10;i++)
        {
            j = 0;
            target = candytable[i][j];
            isclean = 0;
            more = 0;
            for(j=1;j<11;j++)
            {
                if(candytable[i][j]==target)
                {
                    if(isclean<4)
                    {
                        isclean++;
                        more++;
                    }
                    else
                        more++;
                }
                else
                {
                    switch(isclean)
                    {
                        case 2:for(int h=1;h<4;h++)
                                   cleantarget[i][j-h] = 1;
                               break;
                        case 3:for(int h=1;h<5;h++)
                               {
                                   if(h!=1)
                                       cleantarget[i][j-h] = 6;
                                   else
                                       cleantarget[i][j-h] = 4;
                               }
                               break;
                        case 4:for(int h=1;h<more+1;h++)
                               {
                                   if(h!=3)
                                       cleantarget[i][j-h] = 7;
                                   else
                                   {
                                       cleantarget[i-h][j] = 5;
                                       candytable[i-h][j] = 'z';
                                   }
                               }
                               break;
                    }
                    target = candytable[i][j];
                    isclean = 0;
                    more = 0;
                }
            }
        }
        //qDebug()<<"row clean ok"<<endl;
        for(j=0;j<10;j++)
        {
            i = 0;
            target = candytable[i][j];
            isclean = 0;
            more = 0;
            for(i=1;i<11;i++)
            {
                if(candytable[i][j]==target)
                {
                    if(isclean<4)
                    {
                        isclean++;
                        more++;
                    }
                    else
                        more++;
                }
                else
                {
                    switch(isclean)
                    {
                        case 2:
                               for(int h=1;h<4;h++)
                               {
                                   if(cleantarget[i-h][j]==1)
                                       cleantarget[i-h][j] = 3;
                                   else if(cleantarget[i-h][j]==6)
                                   {
                                       int flag = j;
                                       while(cleantarget[i-h][flag]!=4)
                                           flag++;
                                       cleantarget[i-h][flag] = 3;
                                       for(int t=1;t<4;t++)
                                           cleantarget[i-h][flag-t] = 2;
                                   }
                                   else if(cleantarget[i-h][j]==4)
                                       cleantarget[i-h][j] = 3;
                                   else if(cleantarget[i-h][j]==0)
                                       cleantarget[i-h][j] = 1;
                               }
                               break;
                        case 3:
                               count = 0;
                               for(int h=1;h<5;h++)
                               {
                                    if(cleantarget[i-h][j]==1)
                                        cleantarget[i-h][j] = 3;
                                    else if(cleantarget[i-h][j]==6)
                                    {
                                        int flag = j;
                                        while(cleantarget[i-h][flag]!=4)
                                            flag++;
                                        cleantarget[i-h][flag] = 3;
                                        for(int t=1;t<4;t++)
                                            cleantarget[i-h][flag-t] = 2;
                                    }
                                    else if(cleantarget[i-h][j]==4)
                                        cleantarget[i-h][j] = 3;
                                    else if(cleantarget[i-h][j]==0)
                                    {
                                        count++;
                                        if(count==4)
                                        {
                                            cleantarget[i-h][j] = 6;
                                            cleantarget[i-h+3][j] = 8;
                                        }
                                        else
                                            cleantarget[i-h][j] = 6;
                                    }
                               }
                               break;
                        case 4:for(int h=1;h<more+1;h++)
                               {
                                   if(h!=3)
                                       cleantarget[i-h][j] = 7;
                                   else
                                   {
                                       cleantarget[i-h][j] = 5;
                                       candytable[i-h][j] = 'z';
                                   }
                               }
                               break;
                    }
                    target = candytable[i][j];
                    isclean = 0;
                    more = 0;
                }
            }
        }
        //qDebug()<<"cloumn clean ok"<<endl;
    }
    else
    {
        qDebug()<<"in else"<<endl;
        if(candytable[x1][y1]=='z')
        {
            killt = candytable[x2][y2];
            candy_b[x2][y2]->spec = 0;
        }
        else
        {
            killt = candytable[x1][y1];
            candy_b[x1][y1]->spec = 0;
        }
        for(int rr=0;rr<10;rr++)
        {
            for(int cc=0;cc<10;cc++)
            {
                if(candytable[rr][cc]==killt)
                    cleantarget[rr][cc] = 1;
            }
        }
        chocolate = false;
    }
    //改///////////////////////////////////////////
    if(s==true)
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                kill = cleantarget[i][j];
                if(kill==1||kill==2||kill==6||kill==7)
                {
                    if(candy_b[i][j]->spec==3)
                    {
                        qDebug()<<"bomb in"<<endl;
                        for(int rr=-1;rr<2;rr++)
                        {
                            for(int cc=-1;cc<2;cc++)
                            {
                                if((((rr+i)>=0)&&((cc+j)>=0))||(((rr+i)<=9)&&((cc+j)<=9)))
                                {
                                        killb = cleantarget[rr+i][cc+j];
                                    if(killb==0)
                                        cleantarget[rr+i][cc+j] = 1;
                                }
                            }
                        }
                        candy_b[i][j]->spec = 0;
                    }
                    else if(candy_b[i][j]->spec==4)
                    {
                        qDebug()<<"ro in"<<endl;
                        for(int rr=0;rr<10;rr++)
                        {
                            killr=cleantarget[rr][j];
                            if(killr==0)
                                cleantarget[rr][j] = 1;
                        }
                        candy_b[i][j]->spec = 0;
                    }
                    else if(candy_b[i][j]->spec==8)
                    {
                        qDebug()<<"co in"<<endl;
                        for(int cc=0;cc<10;cc++)
                        {
                            killc = cleantarget[cc][i];
                            if(killc==0)
                                cleantarget[cc][i] = 1;
                        }
                        candy_b[i][j]->spec = 0;
                    }
                    else if(candy_b[i][j]->spec==5)
                    {
                        qDebug()<<"choco in"<<endl;
                        char base[10] = {'a','b','c','d','e','f','g','h','i','j'};
                        srand((int)time(NULL));
                        killt = base[rand()%6];
                        for(int rr=0;rr<10;rr++)
                        {
                            for(int cc=0;cc<10;cc++)
                            {
                                kills = cleantarget[rr][cc];
                                if(candytable[rr][cc]==killt&&kills==0)
                                    cleantarget[rr][cc] = 1;
                            }
                        }
                        candy_b[i][j]->spec = 0;
                    }
                }
            }
        }
    }
    //qDebug()<<"special clean ok"<<endl;

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            kill = cleantarget[i][j];
            if(kill==1||kill==2||kill==6||kill==7)
            {
                candytable[i][j] = 'n';
                cleantarget[i][j] = 0;
            }
        }
    }

    //qDebug()<<"clean ok"<<endl;
    // ///////////////////////////////////////////
}


void game::fall()
{
    char stack[10];
    int stackspec[10];
    int stacknum = 0;
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<10;i++)
        {
            stack[i] = 'n';
            stackspec[i] = 0;
        }
        for(int i=0;i<10;i++)
        {
            if(candytable[9-i][j]!='n')
            {
                stack[stacknum] = candytable[9-i][j];
                stackspec[stacknum] = cleantarget[9-i][j];
                stacknum++;
            }
        }
        for(int i=0;i<10;i++)
        {
                candytable[9-i][j] = stack[i];
                cleantarget[9-i][j] = stackspec[i];
        }
        stacknum = 0;
    }
}

void game::showcandy()
{
    QChar text;
    int spe;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            //qDebug()<<"produce candy"<<endl;
            text = candytable[i][j];
            spe = cleantarget[i][j];
            if(spe==0)
                candy_b[i][j] = new candy1;
            else if(spe==4)
                candy_b[i][j] = new candy2;
            else if(spe==8)
                candy_b[i][j] = new candy3;
            else if(spe==3)
                candy_b[i][j] = new candy4;
            else if(spe==5)
                candy_b[i][j] = new candy5;
            QObject::connect(basic[i][j],SIGNAL(clicked()),candy_b[i][j],SLOT(cleanc()));
            QObject::connect(candy_b[i][j],SIGNAL(value(int,int)),this,SLOT(Click(int,int)));
            candy_b[i][j]->setbutton(i,j,text);
            //qDebug()<<"produce candy"<<endl;
        }
    }
    //qDebug()<<"candymake ok"<<endl;
    change();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
                cleantarget[i][j] = 0;
        }
    }

    //mainwin->show();
}

void game::Click(int nx, int ny)
{
    if(exchange==false)
    {
        exchange = true;
        x1 = nx;
        y1 = ny;
    }
    else if(exchange==true&&(((x1==nx)&&(y1==ny+1))||((x1==nx)&&(y1==ny-1))||((x1==nx+1)&&(y1==ny))||((x1==nx-1)&&(y1==ny))))
    {
        x2 = nx;
        y2 = ny;
        int temp_sp,temp_c;
        qDebug()<<candytable[x1][y1]<<endl;
        qDebug()<<candytable[x2][y2]<<endl;
        temp_sp = candy_b[x1][y1]->spec;
        candy_b[x1][y1]->spec = candy_b[x2][y2]->spec;
        candy_b[x2][y2]->spec = temp_sp;
        temp_c = candytable[x1][y1];
        candytable[x1][y1] = candytable[x2][y2];
        candytable[x2][y2] = temp_c;
        if(candytable[x1][y1]=='z'||candytable[x2][y2]=='z')
        {
            chocolate = true;
            qDebug()<<"choco ok"<<endl;
        }
        while(check()==false)
        {
            clean();
            fall();
            generate();
            //delete [] candy_b;
            deletearr();
            //qDebug()<<"delete ok"<<endl;
            showcandy();
        }
        if(checkchange()==false)
        {
            temp_sp = candy_b[x1][y1]->spec;
            candy_b[x1][y1]->spec = candy_b[x2][y2]->spec;
            candy_b[x2][y2]->spec = temp_sp;
            temp_c = candytable[x1][y1];
            candytable[x1][y1] = candytable[x2][y2];
            candytable[x2][y2] = temp_c;
        }
        exchange = false;
        chocolate = false;
    }
    else
    {
        x1 = nx;
        y1 = ny;
    }

}


void game::change()
{
    char tg;
    int st;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            tg = candytable[i][j];
            st = candy_b[i][j]->spec;
            switch(tg)
            {
                case'a':switch(st)
                        {
                            case 0:basic[i][j]->setStyleSheet(sweet[0]);break;
                            case 3:basic[i][j]->setStyleSheet(specials[2]);break;
                            case 4:basic[i][j]->setStyleSheet(specials[1]);break;
                            case 8:basic[i][j]->setStyleSheet(specials[0]);break;
                        }
                        break;
                case'b':switch(st)
                        {
                            case 0:basic[i][j]->setStyleSheet(sweet[1]);break;
                            case 3:basic[i][j]->setStyleSheet(specials[5]);break;
                            case 4:basic[i][j]->setStyleSheet(specials[4]);break;
                            case 8:basic[i][j]->setStyleSheet(specials[3]);break;
                        }
                        break;
                case'c':switch(st)
                        {
                            case 0:basic[i][j]->setStyleSheet(sweet[2]);break;
                            case 3:basic[i][j]->setStyleSheet(specials[8]);break;
                            case 4:basic[i][j]->setStyleSheet(specials[7]);break;
                            case 8:basic[i][j]->setStyleSheet(specials[6]);break;
                        }
                        break;
                case'd':switch(st)
                        {
                            case 0:basic[i][j]->setStyleSheet(sweet[3]);break;
                            case 3:basic[i][j]->setStyleSheet(specials[11]);break;
                            case 4:basic[i][j]->setStyleSheet(specials[10]);break;
                            case 8:basic[i][j]->setStyleSheet(specials[9]);break;
                        }
                        break;
                case'e':switch(st)
                        {
                            case 0:basic[i][j]->setStyleSheet(sweet[4]);break;
                            case 3:basic[i][j]->setStyleSheet(specials[14]);break;
                            case 4:basic[i][j]->setStyleSheet(specials[13]);break;
                            case 8:basic[i][j]->setStyleSheet(specials[12]);break;
                        }
                        break;
                case'f':switch(st)
                        {
                            case 0:basic[i][j]->setStyleSheet(sweet[5]);break;
                            case 3:basic[i][j]->setStyleSheet(specials[17]);break;
                            case 4:basic[i][j]->setStyleSheet(specials[16]);break;
                            case 8:basic[i][j]->setStyleSheet(specials[15]);break;
                        }
                        break;
                case'z':basic[i][j]->setStyleSheet(sweet[10]);
                        break;
            }
        }
    }
}

void game::deletearr()
{
    //qDebug()<<"in delete"<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            delete candy_b[i][j];
    }
    //qDebug()<<"delete ok"<<endl;
}

bool game::checkchange()
{
    int count = 0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(cleantarget[i][j]!=0)
                count++;
        }
    }
    if(count>0)
        return true;
    else
        return false;
}
