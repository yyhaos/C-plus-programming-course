#pragma once
#include<string>
#include"Date.hpp"
using namespace std;
class Deposit
{
private:
    int id;
    string name;
    int code;
    double money;
    static double profit;
    Date open;
    static int th;
public:
    Deposit (string Name="X",int Code=123,double Money=0,double Profit=0,Date Open=Date(2018,10,1));
    void check();
    static void change_profit(double );
    void month_past(int month=0);
    Date getDate();
};
