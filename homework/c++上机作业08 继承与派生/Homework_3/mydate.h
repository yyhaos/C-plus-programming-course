#pragma once
using namespace std;
class CMyDate
{
private:
    int Year,Month,Day;
public:
    const int MonthDay[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
    CMyDate(int year=2000,int month=1,int day=1);
    void Set(int year,int month,int day);
    void Next();
    void Display() const;
    bool isLeapYear(int year);
    int getMonthDay(int year,int month);
};
