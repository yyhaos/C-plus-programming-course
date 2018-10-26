#include"Deposit.hpp"
#include<iostream>
//using namespace std;
double Deposit::profit=0.01;
int Deposit::th=0;
void Deposit::check()
{
    cout<<id<<"\t"<<name<<"\t"<<code<<"\t"<<money<<"\t"<<profit<<"\t";
    open.Show();
    cout<<endl;
}
void Deposit::change_profit(double pro)
{
    profit=pro;//Deposit::profit=pro;  is also ok
}
Deposit::Deposit(string Name,int Code,double Money,double Profit,Date Open)
{
    th++;   //Deposit::th++;  is also ok
    id=th;
    name=Name;
    code=Code;
    money=Money;
    profit=Profit;
    open=Open;
}
void Deposit::month_past(int month)
{
    while(month--)
        money=money+money*profit;
}
Date Deposit::getDate()
{
    return open;
}
