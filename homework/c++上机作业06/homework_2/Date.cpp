#include "Date.hpp"
#include<iostream>
using namespace std;

Date::Date(){};
Date::Date(int y,int m,int d)
{
    year=y,month=m,day=d;
    //cout<<"Date类含参数构造函数调用完毕"<<endl;
}
Date::~Date(void)
{
    //cout<<"Date类析构函数调用完毕"<<endl;
}
void Date::SetDate(int y,int m,int d)
{
    year=y,month=m,day=d;
}
void Date::Show(void)
{
    cout<<year<<"-"<<month<<"-"<<day;
}
int Date::cha_month(Date b)
{
    return abs(12*year+month-12*b.year-b.month);
}
