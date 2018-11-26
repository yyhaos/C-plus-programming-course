#include"RMB.hpp"
#include<iostream>
#include<istream>
#include<ostream>
using namespace std;

RMB::RMB(char fl,int y,int j,int f):
    flag(fl),Yuan(y),Jiao(j),Fen(f){trans(tot());}
RMB::RMB(char fl,int total):
    flag(fl),Yuan(total/100),Jiao(total/10%10),Fen(total%10){trans(tot());}
RMB::RMB(int total)
{
    trans(total);
}
int RMB::tot()
{
    int f=1;
    if(flag=='-')
        f=-1;
    return f*(Yuan*100+Jiao*10+Fen*1);
}
void RMB::trans(int total)
{
    flag='+';
    if(total<0)
        total*=-1,flag='-';
    Fen=total%10;
    total/=10;
    Jiao=total%10;
    total/=10;
    Yuan=total;
    return ;
}
RMB RMB::operator +(RMB &b)
{
    return RMB(tot()+b.tot());
}
RMB RMB::operator -(RMB &b)
{
    return RMB(tot()-b.tot());
}
RMB RMB::operator ++()
{
    trans(tot()+1);
    return RMB(tot());
}
RMB RMB::operator ++(int)
{
    trans(tot()+1);
    return RMB(tot()-1);
}
RMB operator --(RMB &a)
{
    a.trans(a.tot()-1);
    return RMB(a.tot());
}
RMB operator --(RMB &a,int)
{
    a.trans(a.tot()-1);
    return RMB(a.tot()+1);
}
ostream& operator << (ostream& os,const RMB& tm)
{
    os<<'('<<tm.flag<<tm.Yuan<<"Ôª"
          <<tm.Jiao<<"½Ç"<<tm.Fen<<"·Ö"<<')';
}
istream& operator >> (istream& is,RMB& tm)
{
    is>>tm.flag>>tm.Yuan>>tm.Jiao>>tm.Fen;
    tm.trans(tm.tot());
}
