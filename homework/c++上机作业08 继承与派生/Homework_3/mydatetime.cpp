#include"mydatetime.h"
#include<string>
using namespace std;
CMyDateTime::CMyDateTime(int year,int month,int day,int hour,int minute,int second):
    CMyDate(year,month,day),CMyTime(hour,minute,second){}
void CMyDateTime::Set(int year,int month,int day,int hour,int minute,int second)
{
    CMyDate::Set(year,month,day);
    CMyTime::Set(hour,minute,second);
}
void CMyDateTime::Next()
{
    if(CMyTime::Next())
        CMyDate::Next();
}
void CMyDateTime::Display() const
{
    CMyDate::Display();
    CMyTime::Display();
}
