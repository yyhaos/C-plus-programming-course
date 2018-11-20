#include"mydate.h"
#include<iostream>
using namespace std;
bool CMyDate::isLeapYear(int year)
{
    if(year%400==0)
        return true;
    if(year%100!=0 && year%4==0)
        return true;
    return false;
}
int CMyDate::getMonthDay(int year,int month)
{
    if(month==2)
        return MonthDay[month]+isLeapYear(year);
    return MonthDay[month];
}
CMyDate::CMyDate(int year,int month,int day):
    Year(year),Month(month),Day(day){}
void CMyDate::Set(int year,int month,int day)
{
    Year=year,Month=month,Day=day;
}
void CMyDate::Display() const
{
    cout<<Year<<"-"<<Month<<"-"<<Day<<" ";
}
void CMyDate::Next()
{
    Day++;
    if(Day>getMonthDay(Year,Month))
    {
        Day=1;
        Month++;
        if(Month>12)
        {
            Month=1;
            Year++;
        }
    }
}
