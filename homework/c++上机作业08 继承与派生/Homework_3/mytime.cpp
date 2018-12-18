#include"mytime.h"
#include<iostream>
using namespace std;
CMyTime::CMyTime(int hour,int minute,int second):
    Hour(hour),Minute(minute),Second(second){}
void CMyTime::Set(int hour,int minute,int second)
{
    Hour=hour,Minute=minute,Second=second;
}
void CMyTime::Display() const
{
    cout<<Hour<<":"<<Minute<<":"<<Second<<" ";
}
bool CMyTime::Next()
{
    Second++;
    if(Second>=60)
    {
        Second=0;
        Minute++;
        if(Minute>=60)
        {
            Minute=0;
            Hour++;
            if(Hour>=24)
            {
                Hour=0;
                return true;
            }
        }
    }
    return false;
}
